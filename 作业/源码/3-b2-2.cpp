/*2452545 ����� ������*/
#include <iostream>
using namespace std;
int main()
{
    int k;
    cout << "������һ��[1..30000]�������:" << endl;
    cin >> k;
    cout << "��λ : " << (k / 10000) % 10 << endl;
    cout << "ǧλ : " << (k / 1000) % 10 << endl;
    cout << "��λ : " << (k / 100) % 10 << endl;
    cout << "ʮλ : " << (k / 10) % 10 << endl;
    cout << "��λ : " << (k / 1) % 10 << endl;
    return 0;
}
