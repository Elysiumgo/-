/* 2452545 ����� ������ */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�����������hanoi�ж���һ����̬�ֲ�����
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
               3��������һ����̬�ֲ�����
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    static int i = 0;
    if (n == 1)
    {
        i++;
        cout << setw(5) << i <<": " << setw(2) << n << '#' << ' ' << src << "-->" << dst << endl;
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        i++;
        cout << setw(5) << i << ": " << setw(2) << n << '#' << ' ' << src << "-->" << dst << endl;
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
        cout << "�����뺺ŵ���Ĳ���(1-16)" << endl;
        cin >> n;
        if (cin.good() && n >= 1 && n <= 16) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    }
    //n������������

    while (1) {
        cout << "��������ʼ��(A-C)" << endl;
        cin >> src;
        if (cin.good() && src == 'A' || src == 'a' || src == 'B' || src == 'b' || src == 'C' || src == 'c') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    //��ʼ��������������

    while (1) {
        cout << "������Ŀ����(A-C)" << endl;
        cin >> dst;
        if (cin.good() && dst != src && (dst == 'A' || dst == 'a' || dst == 'B' || dst == 'b' || dst == 'C' || dst == 'c')) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }//������ȷ����src��ͬ
        else if (cin.good() && dst == src && (dst == 'A' || dst == 'a' || dst == 'B' || dst == 'b' || dst == 'C' || dst == 'c')) {
            cout << "Ŀ����(" << src << ")��������ʼ��(" << src << ")��ͬ" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }//������ȷ����src��ͬ
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

    cout << "�ƶ�����Ϊ:" << endl;
    hanoi(n, src, tmp, dst);

    cout << endl;





}

