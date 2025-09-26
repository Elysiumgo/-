/*2452545 计算机 刘晴语*/
#include<iostream>
#include<iomanip>
#include<limits> 
using namespace std;
void calendar(int year, int month)
{
	/* 按需添加代码 */
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
	cout << year << "年" << month << "月" << endl;
	/* 头部分隔线，不算打表 */
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;

	/* 按需添加代码 */
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

	/* 尾部分隔线，不算打表 */
	cout << "======================================================" << endl;
}





int main() {
	int year, month;
	while (1) {
		cout << "请输入年[1900-2100]、月" << endl;
		cin >> year >> month;
		if (cin.good() && year >= 1900 && year <= 2100 && month >= 1 && month <= 12)
			break;
		else if (cin.fail()) {
			cout << "输入错误，请重新输入" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (year > 2100 || year < 1900)
				cout << "年份不正确，请重新输入" << endl;
	    else if (month > 12)
				cout << "月份不正确，请重新输入" << endl;
		
		}


	cout << endl;
	calendar(year, month);
	return 0;
}
