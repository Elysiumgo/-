/*2452545 ����� ������*/
#include<iostream>
#include<iomanip>
#include <limits>
using namespace std;
int main()
{
	int i, year, month, day, n;
	bool leap;
	while (1) {
		cout << "���������(2000-2030)���·�(1-12) : ";
		if ((cin >> year >> month) && year >= 2000 && year <= 2030 && month >= 1 && month <= 12)
			break;
		else {
			cout << "����Ƿ�������������" << endl;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
	}
	//�ж���ݺ��·ݽ���
	while (1) {
		cout << "������"<<year<<"��"<<month<<"��"<<"1�յ�����(0-6��ʾ������-������) : ";
		if ((cin >> day) && day <= 6 && day >= 0)
			break;
		else {
			cout << "����Ƿ�������������" << endl;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
	}
	cout << endl;
	//�ж�����������
	leap = (year % 4 == 0);
	cout << year << "��" << month << "�µ�����Ϊ:" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		for (n = 1;;n++) {
			for (;day > 0;day--) {
				cout << setw(6) << " ";
				cout << setw(2) << " ";
				n++;
			}
			for (i = 1;i <= 31;i++) {
				cout << setw(4) << i;
				cout << setw(4) << ' ';
				n++;
				if (n > 7) {
					cout << endl;
					n = 1;
				}
			}
			if (i >= 31)
				break;
		}

	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		for (n = 1;;n++) {
			for (;day > 0;day--) {
				cout << setw(6) << " ";
				cout << setw(2) << " ";
				n++;
			}
			for (i = 1;i <= 30;i++) {
				cout << setw(4) << i;
				cout << setw(4) << ' ';
				n++;
				if (n > 7) {
					cout << endl;
					n = 1;
				}
			}
			if (i >= 30)
				break;
		}

	}
	else if (month == 2 && leap) {
		for (n = 1;;n++) {
			for (;day > 0;day--) {
				cout << setw(6) << " ";
				cout << setw(2) << " ";
				n++;
			}
			for (i = 1;i <= 29;i++) {
				cout << setw(4) << i;
				cout << setw(4) << ' ';
				n++;
				if (n > 7) {
					cout << endl;
					n = 1;
				}
			}
			if (i >= 29)
				break;
		}

	}
	else if (month == 2 && leap == 0) {
		for (n = 1;;n++) {
			for (;day > 0;day--) {
				cout << setw(6) << " ";
				cout << setw(2) << " ";
				n++;
			}
			for (i = 1;i <= 28;i++) {
				cout << setw(4) << i;
				cout << setw(4) << ' ';
				n++;
				if (n > 7) {
					cout << endl;
					n = 1;
				}
			}
			if (i >= 28)
				break;
		}

	}

	cout << endl;
	return 0;
}