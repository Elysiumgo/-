/*2452545 ����� ������*/
#include<iostream>
#include<iomanip>
#include<limits> 
using namespace std;
void calendar(int year, int month)
{
	/* ������Ӵ��� */
	int n,i;
	bool leap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
	int day;
	int y=year;
	int m = month;
	if (month < 3) {
		m=month + 12;
		y=year-1;
	}
	int c = y / 100;
	int w = 0;
	y %= 100;
	int d = 1;
	w = y + static_cast<int>(y / 4) + static_cast<int>(c / 4) - 2 * c + static_cast<int>(13 * (m + 1) / 5) + d - 1;
	w = (w % 7 + 7) % 7;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		day = 31;
	else if (leap && month == 2)
		day = 29;
	else if (!leap && month == 2)
		day = 28;
	else
		day = 30;
	cout << year << "��" << month << "��" << endl;
	/* ͷ���ָ��ߣ������� */
	cout << "======================================================" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
	cout << "======================================================" << endl;

	/* ������Ӵ��� */
	for (n = 1;;n++) {
		for (;w > 0;w--) {
			cout << setw(6) << " ";
			cout << setw(2) << " ";
			n++;
		}
		for (i = 1;i <= day;i++) {
			cout << setw(4) << i;
			cout << setw(4) << ' ';
			n++;
			if (n > 7) {
				cout << endl;
				n = 1;
			}
		}
		if (i > day)
			if (n!=1)
				cout << endl;
			break;
	}

	/* β���ָ��ߣ������� */
	cout << "======================================================" << endl;
}





int main() {
	int year, month;
	while (1) {
		cout << "��������[1900-2100]����" << endl;
		cin >> year >> month;
		if (cin.good() && year >= 1900 && year <= 2100 && month >= 1 && month <= 12)
			break;
		else if (cin.fail()) {
			cout << "�����������������" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (year > 2100 || year < 1900)
				cout << "��ݲ���ȷ������������" << endl;
	    else if (month > 12)
				cout << "�·ݲ���ȷ������������" << endl;
		
		}


	cout << endl;
	calendar(year, month);
	return 0;
}
