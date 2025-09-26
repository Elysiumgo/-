/*2452545 计算机 刘晴语*/
#include<iostream>
#include <limits>
#include<iomanip>
using namespace std;

int daysofmonth(int year, int month) //每个月的天数
{  
	bool leap;
	leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

	if (month == 2) 
		return leap ? 29 : 28;
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	return 31;
}




int FirstDay(int year, int month) //每个月的第一天的星期数
{  
	if (month < 3) {
		month += 12;
		year--;
	}
	int c = year / 100;
	int y = year % 100;
	int m = month;
	int d = 1;
	int w = (y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1) % 7;
	return (w + 7) % 7; 
}







void printYearCalendar(int year, int months_row) {

	int rows = (12 + months_row - 1) / months_row; // 计算需要多少行

	for (int row = 0; row < rows; ++row) {
		// 打印月份
		for (int column = 0; column < months_row; ++column) {
			int month = row * months_row + column + 1;
			if (month > 12)
				break;
			cout << setw(13) <<right<< month<<"月" <<setw(17)<< " ";
		}
		cout << endl;

		// 打印星期
		for (int column = 0; column < months_row; ++column) {
			int month = row * months_row + column + 1;
			if (month > 12) 
				break;
			cout << "Sun Mon Tue Wed Thu Fri Sat     ";
		}
		cout << endl;

		// 计算日历行数（最多6行）
		for (int week = 0; week < 6; ++week) {
			for (int column = 0; column < months_row; ++column) {
				int month = row * months_row + column + 1;
				if (month > 12) break;

				int firstDay = FirstDay(year, month);
				int monthDays = daysofmonth(year, month);

				// 打印当前周的日期
				for (int day = 1; day <= 7; ++day) {
					int currentDay = week * 7 + day - firstDay;
					if (currentDay > 0 && currentDay <= monthDays) {
						cout << setw(4) << left << currentDay;
					}
					else {
						cout << "    ";
					}
				}
				cout << "    "; // 月份之间的间隔
			}
			cout << endl;
		}
		cout << endl; // 每行月份结束后打印一个空行
	}
}











int main()
{
	int year;
	while (1) {
		cout << "请输入年份[1900-2100]" << endl;
		cin >> year;
		if (cin.good() && year >= 1900 && year <= 2100)
			break;
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
		}
	}
	//年份输入完毕
	int row;
	while (1) {
		cout << "请输入每行打印的月份数[1/2/3/4/6/12]" << endl;
		cin >> row;
		if (cin.good() &&( row==1||row==2||row==3||row==4||row==6||row==12))
			break;
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

		}
	}

	cout << year << "年的日历:" << endl;
	printYearCalendar(year,row);







	return 0;


}