/*������ 2452545 �����*/
#include <iostream>
#include <iomanip>
#include<Windows.h>
#include<conio.h>
#include "5-b7.h"
using namespace std;

   
int step;
bool show;




void printStatus(int A[], int B[], int C[], int& topA, int& topB, int& topC,
    int speed, bool show, char from = 0, char to = 0, int disk = 0)
    {
    const int X = 10, Y = 16;


    if (speed == 0&&step!=0) {
        while (_getch() != 13)
            ;
    }
    else if(step!=0) {
        Sleep(1000 / (speed + 1));
    }

    if (step > 0 && show) {
        cct_gotoxy(3, 25);
        printf("%s%3d%s%2d%s%c%s%c ", "�� ", step, " ��(", disk, "): ", from, "-->", to);
    }
    
    for (int i = 0; i < 10; i++) {
        cct_gotoxy(X, Y - i); printf("  ");
        cct_gotoxy(X + 10, Y - i); printf("  ");
        cct_gotoxy(X + 20, Y - i); printf("  ");
    }

    for (int i = 0; i < 10; i++)
    {
        if (A[i] != 0)
        {
            cct_gotoxy(X,Y-i);
            cout<<A[i];
        }
        else
            cout<<"  ";
    }

    for (int i = 0; i < 10; i++)
    {
        if (B[i] != 0)
        {
            cct_gotoxy(X+10, Y - i);
            cout<<B[i];
        }
        else
            cout << "  ";
    }

    for (int i = 0; i < 10; i++)
    {
        if (C[i] != 0)
        {
            cct_gotoxy(X+20, Y - i);
            cout<<C[i];
        }
        else
            cout << "  ";
    }




    if (show) {

        cct_gotoxy(30,25);
        printf("A: ");
        for (int i = 0; i < 10; i++)
        {
            if (A[i] != 0)
                cout << A[i]<<' ';
            else
                cout << "  ";
        }

        printf("B: ");
        for (int i = 0; i < 10; i++)
        {
            if (B[i] != 0)
                cout << B[i] << ' ';
            else
                cout << "  ";
        }

        printf("C: ");
        for (int i = 0; i < 10; i++)
        {
            if (C[i] != 0)
                cout << C[i] << ' ';
            else
                cout << "  ";

        }
        cout << endl;

    }

}







void moveStatus(int A[], int B[], int C[], int& topA, int& topB, int& topC,
    char from, char to, int speed, int show) 
{
    step++;
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





   
    printStatus(A, B, C, topA, topB, topC, speed, show, from, to, disk);


    
    

}







void hanoi(int A[], int B[], int C[], int& topA, int& topB, int& topC,
    int n, char src, char tmp, char dst, int speed, int show) 
{
    
    if (n == 1) {
        moveStatus(A, B, C, topA, topB, topC, src, dst, speed, show);
    }
    else {
        hanoi(A, B, C, topA, topB, topC, n - 1, src, dst, tmp, speed, show);
        moveStatus(A, B, C, topA, topB, topC, src, dst, speed, show);
        hanoi(A, B, C, topA, topB, topC, n - 1, tmp, src, dst, speed, show);
    }
}















int main()
{
    int A[10] = { 0 }, B[10] = { 0 }, C[10] = { 0 };  // ���������ϵ�Բ��
    int topA = -1, topB = -1, topC = -1; //ָ��
    int n;
    step = 0;
    char src = 0, dst = 0, tmp = 0;
    while (1) {
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
        cin >> n;
        if (cin.good() && n >= 1 && n <= 10) {
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            break;
        }
        else {
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        }

    }
    //n������������

    while (1) {
        cout << "��������ʼ��(A-C)" << endl;
        cin >> src;
        if (cin.good() && src == 'A' || src == 'a' || src == 'B' || src == 'b' || src == 'C' || src == 'c') {
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            break;
        }
        else {
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        }
    }
    //��ʼ��������������

    while (1) {
        cout << "������Ŀ����(A-C)" << endl;
        cin >> dst;
        if (cin.good() && dst != src && (dst == 'A' || dst == 'a' || dst == 'B' || dst == 'b' || dst == 'C' || dst == 'c')) {
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            break;
        }//������ȷ����src��ͬ
        else if (cin.good() && dst == src && (dst == 'A' || dst == 'a' || dst == 'B' || dst == 'b' || dst == 'C' || dst == 'c')) {
            cout << "Ŀ����(" << src << ")��������ʼ��(" << src << ")��ͬ" << endl;
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        }//������ȷ����src��ͬ
        else {
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        }
    }
    //Ŀ����������������

    int speed;
    while (1) {
        cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
        cin >> speed;
        if (speed >= 0 && speed <= 5)
            break;
        else {
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        }

    }
    //�ٶ�������������

    int show_notbool;
    while (1) {
        cout << "�������Ƿ���ʾ�ڲ�����ֵ(0-����ʾ 1-��ʾ)" << endl;
        cin >> show_notbool;
        if (show_notbool != 0 && show_notbool != 1) {
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        }
        else {
            show = show_notbool;
            break;
        }

    }
    //�Ƿ���ʾ�ڲ�����ֵ�������






   
    


    if (src == 'a' || src == 'b' || src == 'c')
        src -= 32;
    if (dst == 'a' || dst == 'b' || dst == 'c')
        dst -= 32;
    //ͳһ��Сд

    tmp = 198 - src - dst;
    //tmpΪ�м��� ��toupper���ð�

    
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

    cct_cls();
    //����

    cout << "��" << src << "�ƶ���" << dst << "��" << "��" << n << "�㣬" << "��ʱ����Ϊ" << speed << "��";
    cout << (show ? "" : "��") << "��ʾ�ڲ�����ֵ" << endl;


    
 
    
  
   
    cct_gotoxy(8, 17);
    cout << "=========================" <<endl;
    
    cout << "          A         B         C  ";





    if (show) {
        cct_gotoxy(3, 25);
        printf("%-21s", "��ʼ:");
        printStatus(A, B, C, topA, topB, topC, speed, show, src, dst, 0);
        
    }
  



    hanoi(A, B, C, topA, topB, topC, n, src, tmp, dst, speed, show);




    system("pause");
    return 0;
    

}