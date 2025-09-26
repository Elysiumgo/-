/* 2452545 计算机 刘晴语 */
#include <iostream>
using namespace std;

/* 1、不允许定义任何类型的全局变量，包括常变量及宏定义等
   2、不允许给出任何形式的全局函数
*/

/* --- 将类的定义补充完整 --- */
class Days {
private:
	int year;
	int month;
	int day;
	//除上面的三个private数据成员外，不再允许添加任何类型的数据成员

	/* 下面可以补充需要的类成员函数的定义（不提供给外界，仅供本类的其它成员函数调用，因此声明为私有，数量不限，允许不定义） */
	bool isLeapYear() {
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}

	// 检查日期是否有效
	bool isCorrectDate() {
		if (year < 1 || month < 1 || month > 12 || day < 1)
			return false;

		int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (isLeapYear()) 
			daysInMonth[1] = 29;

		return day <= daysInMonth[month - 1];
	}





public:
	Days(int y, int m, int d) : year(y), month(m), day(d) {}

	// 计算该日期是该年的第几天
	int calc_days() {
		if (!isCorrectDate()) 
			return -1;  // 无效返回 -1

		int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (isLeapYear()) daysInMonth[1] = 29;

		int total = 0;
		for (int i = 0; i < month - 1; ++i) {
			total += daysInMonth[i];
		}
		total += day;

		return total;
	}
};



/* --- 此处给出类成员函数的体外实现 --- */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
 ***************************************************************************/
int main()
{
	if (1) {
		Days d1(2024, 3, 18);
		cout << "应该输出78， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 3, 18);
		cout << "应该输出77， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2024, 12, 31);
		cout << "应该输出366，实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 12, 31);
		cout << "应该输出365，实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2024, 2, 29);
		cout << "应该输出60， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 2, 29);
		cout << "应该输出-1， 实际是：" << d1.calc_days() << endl;
	}

	return 0;
}
