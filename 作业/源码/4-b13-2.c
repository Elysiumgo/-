/* 2452545 ����� ������ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2��������һ��ȫ�ֱ������������徲̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */


   /***************************************************************************
     �������ƣ�
     ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
     ���������int n������
               char src����ʼ��
               char tmp���м���
               char dst��Ŀ����
     �� �� ֵ��
     ˵    ����1�����������βΡ��������;���׼��
               2������������������κ���ʽ��ѭ��
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    static int i = 0;
    if (n == 1) {
        i++;
        printf("%5d: %2d# %c-->%c\n", i, n, src, dst);
    }

    else {
        hanoi(n - 1, src, dst, tmp);
        i++;
        printf("%5d: %2d# %c-->%c\n", i, n, src, dst);
        hanoi(n - 1, tmp, src, dst);
    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��������롢���õݹ麯��
            2�������������ʱ������ʹ��ѭ��
            3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
***************************************************************************/
int main()
{
    int n;
    char src, dst, tmp = 'A';
    while (1) {
        int ret;
        printf("�����뺺ŵ���Ĳ���(1-16)\n" );
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
        printf("��������ʼ��(A-C)\n" );
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
        printf("������Ŀ����(A-C)\n") ;
        ret=scanf("%c", &dst);
        if (ret && dst != src && (dst == 'A' || dst == 'a' || dst == 'B' || dst == 'b' || dst == 'C' || dst == 'c')) {
            while (getchar() != '\n')
                ;
            break;
        }//������ȷ����src��ͬ
        else if (ret && dst == src && (dst == 'A' || dst == 'a' || dst == 'B' || dst == 'b' || dst == 'C' || dst == 'c')) {
            printf("%s%c%s%c%s\n", "Ŀ����(", src,")��������ʼ��(" , src , ")��ͬ");
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

    printf( "�ƶ�����Ϊ:\n");
    hanoi(n, src, tmp, dst);

    printf("\n");





}
