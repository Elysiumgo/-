/*������ 2452545 �����*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int A[10] = { 0 }, B[10] = { 0 }, C[10] = { 0 };  // ���������ϵ�Բ��
int topA = -1, topB = -1, topC = -1;          // ջ��ָ��
int step = 0;

void printStatus()
{
    if (step == 0) {
        printf("%-21s", "��ʼ:");
    }



    printf( "A: ");
    for (int i = 0; i < 10; i++)
    {
        if (A[i] != 0)
            printf("%d ", A[i]);
        else
            printf("  ");
    }

    printf( "B: ");
    for (int i = 0; i < 10; i++)
    {
        if (B[i] != 0)
            printf("%d ", B[i]);
        else
            printf("  ");
    }

    printf("C: ");
    for (int i = 0; i < 10; i++)
    {
        if (C[i] != 0)
            printf("%d ", C[i]);
        else
            printf("  ");

    }
    printf("\n");

}







void move(char from, char to) {
    int disk;
    if (from == 'A') {
        disk = A[topA];
        A[topA] = 0;
        topA--;
    }
    else if (from == 'B') {
        disk = B[topB];
        B[topB] = 0;
        topB--;
    }
    else if (from == 'C') {
        disk = C[topC];
        C[topC] = 0;
        topC--;
    }

    if (to == 'A') {
        A[++topA] = disk;
    }
    else if (to == 'B') {
        B[++topB] = disk;
    }
    else if (to == 'C') {
        C[++topC] = disk;
    }


    if (step > 0) {
        printf("%s%3d%s%2d%s%c%s%c ", "�� ", step, " ��(", disk, "): ", from, "-->", to);
        printStatus();
    }


}







void hanoi(int n, char src, char tmp, char dst) {
    if (n == 1) {
        step++;
        move(src, dst);
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        step++;
        move(src, dst);
        hanoi(n - 1, tmp, src, dst);
    }
}















int main()
{
    int n;
    char src, dst, tmp = 'A';
    while (1) {
        int ret;
        printf("�����뺺ŵ���Ĳ���(1-10)\n");
        ret = scanf("%d", &n);
        if (ret && n >= 1 && n <= 16) {
            while (getchar() != '\n')
                ;
            break;
        }
        else {
            while (getchar() != '\n')
                ;
        }

    }
    //n������������

    while (1) {
        int ret;
        printf("��������ʼ��(A-C)\n");
        ret = scanf("%c", &src);
        if (ret && src == 'A' || src == 'a' || src == 'B' || src == 'b' || src == 'C' || src == 'c') {
            while (getchar() != '\n')
                ;
            break;
        }
        else {
            while (getchar() != '\n')
                ;
        }
    }
    //��ʼ��������������

    while (1) {
        int ret;
        printf("������Ŀ����(A-C)\n");
        ret = scanf("%c", &dst);
        if (ret && dst != src && (dst == 'A' || dst == 'a' || dst == 'B' || dst == 'b' || dst == 'C' || dst == 'c')) {
            while (getchar() != '\n')
                ;
            break;
        }//������ȷ����src��ͬ
        else if (ret && dst == src && (dst == 'A' || dst == 'a' || dst == 'B' || dst == 'b' || dst == 'C' || dst == 'c')) {
            printf("%s%c%s%c%s\n", "Ŀ����(", src, ")��������ʼ��(", src, ")��ͬ");
            while (getchar() != '\n')
                ;
        }//������ȷ����src��ͬ
        else {
            while (getchar() != '\n')
                ;
        }
    }
    //Ŀ����������������

    if ((src == 'A' && dst == 'B') || (src == 'a' && dst == 'b') || (src == 'B' && dst == 'A') || (src == 'b' && dst == 'a'))
        tmp = 'C';
    if ((src == 'A' && dst == 'C') || (src == 'a' && dst == 'c') || (src == 'C' && dst == 'A') || (src == 'c' && dst == 'a'))
        tmp = 'B';
    if ((src == 'C' && dst == 'B') || (src == 'c' && dst == 'b') || (src == 'C' && dst == 'A') || (src == 'c' && dst == 'a'))
        tmp = 'A';
    //tmpΪ�м���


    if (src == 'a' || src == 'b' || src == 'c')
        src -= 32;
    if (dst == 'a' || dst == 'b' || dst == 'c')
        dst -= 32;
    //ͳһ��Сд

    for (int i = n; i >= 1; i--) {
        if (src == 'A') {
            topA++;
            A[topA] = i;
        }
        else if (src == 'B') {
            topB++;
            B[topB] = i;
        }
        else if (src == 'C') {
            topC++;
            C[topC] = i;
        }

    }



    printStatus();

    hanoi(n, src, tmp, dst);







}