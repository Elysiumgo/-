/*������ 2452545 �����*/
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	cout << "����������ֵ��" << endl;
	float k;
	int t50=0, t20=0, t10=0,t5=0, t1=0, t05=0, t01=0, t005=0, t002=0, t001=0,k2=0;
	cin >> k;
	t50 = static_cast<int>(k/50) ;
	t20 = static_cast<int>((k - 50*t50)/20);
	t10= static_cast<int>((k - 50 * t50-20*t20)/10);
	t5 = static_cast<int>((k - 50 * t50 - 20 * t20-10*t10)/5);
	t1 = static_cast<int>(k - 50 * t50 - 20 * t20 - 5 * t5-10*t10);

	k2 = static_cast<int>(100 * (k - 50 * t50 - 20 * t20 - 5 * t5-10*t10 - t1)+0.5); //����С������
	t05 = static_cast<int>(k2 / 50);
	t01 = static_cast<int>((k2 - 50 * t05)/10);
	t005 = static_cast<int>((k2 - 50 * t05-10*t01)/5);
	t002 = static_cast<int>((k2 - 50 * t05 - 10 * t01-5*t005) / 2);
	t001 = static_cast<int>(k2 - 50 * t05 - 10 * t01 - 5 * t005 - 2 * t002);

	cout << "��" << (t50 + t20 + t10 + t5 + t1 + t05 + t01 + t005 + t002 + t001) << "�����㣬�������£�" << endl;

	if (t50 != 0)
		cout <<left<<setw(4)<< "50Ԫ" << " : " << t50 << "��" << endl;
	if (t20 != 0)
		cout << left << setw(4) << "20Ԫ" << " : " << t20 << "��" << endl;
	if (t10 != 0)
		cout << left << setw(4) << "10Ԫ" << " : " << t10 << "��" << endl;
	if (t5 != 0)
		cout << left << setw(4) << "5Ԫ" << " : " << t5 << "��" << endl;
	if (t1 != 0)
		cout << left << setw(4) << "1Ԫ" << " : " << t1 << "��" << endl;
	if (t05 != 0)
		cout << left << setw(4) << "5��" << " : " << t05 << "��" << endl;
	if (t01 != 0)
		cout << left << setw(4) << "1��" << " : " << t01 << "��" << endl;
	if (t005 != 0)
		cout << left << setw(4) << "5��" << " : " << t005 << "��" << endl;
	if (t002 != 0)
		cout << left << setw(4) << "2��" << " : " << t002 << "��" << endl;
	if (t001 != 0)
		cout << left << setw(4) << "1��" << " : " << t001 << "��" << endl;



	return 0;
}