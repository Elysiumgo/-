/*2452545 ����� ������*/
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
    double r, h;
    const double pi = 3.14159;
    cout << "������뾶�͸߶�" << endl;
    cin >> r >> h;
    cout << fixed;
    cout << setiosflags(ios::left) << setw(10) << "Բ�ܳ�" <<" : " <<  setprecision(2)<<2 * pi * r * r << endl;
    cout << setiosflags(ios::left) << setw(10) << "Բ���" << " : " << setprecision(2) << pi * r * r << endl;
    cout << setiosflags(ios::left) << setw(10) << "Բ������" << " : " << setprecision(2) << 4 * pi * r * r << endl;
    cout << setiosflags(ios::left) << setw(10) << "Բ�����" << " : " << setprecision(2) << 4 * pi * r * r * r/3 << endl;
    cout << setiosflags(ios::left) << setw(10) << "Բ�����" << " : " << setprecision(2) << pi * r * r * h << endl;
    
    return 0;
}
