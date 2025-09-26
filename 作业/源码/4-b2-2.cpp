/*2452545 计算机 刘晴语*/
#include<iostream>
#include<iomanip>
#include <limits>
using namespace std;
int week(int year, int month, int day) {
	if (month < 3) {
		month += 12;
		year--;
	}
	int c = year / 100;
	int m = month;
	int w=0;
	int y = year % 100;
	int d = day;
	w = y + static_cast<int>(y / 4) + static_cast<int>(c / 4) - 2 * c + static_cast<int>(13 * (m + 1) / 5) + d - 1;
	w = (w % 7 + 7) % 7;
	switch (w) {
		case 0:
			cout << "日";
			break;
		case 1:
			cout << "一";
			break;
		case 2:
			cout << "二";
			break;
		case 3:
			cout << "三";
			break;
		case 4:
			cout << "四";
			break;
		case 5:
			cout << "五";
			break;
		case 6:
			cout << "六";
			break;

	}
	return 0;
}








int main()
{
	int year, month, day;
	bool leap;
	while (1) {
		cout << "请输入年[1900-2100]、月、日：";
		cin >> year >> month >> day;
		leap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
			if (year > 2100 || year < 1900)
				cout << "年份不正确，请重新输入" << endl;
			else if (month > 12)
				cout << "月份不正确，请重新输入" << endl;
			else if ((!leap&&month==2&&day>28)||((month==4||month==6||month==9||month==11)&&day>30)||day>31||(leap&&month==2&&day>29))
				cout << "日不正确，请重新输入" << endl;
			else if (cin.good() && year >= 1900 && year <= 2100 && month >= 1 && month <= 12)
				break;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
	cout << "星期";
	week(year, month, day);
	cout << endl;
	return 0;
}
