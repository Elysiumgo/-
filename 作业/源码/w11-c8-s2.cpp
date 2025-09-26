/* 2452545 计算机 刘晴语 */
#include <iostream>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量（不包括宏定义、全局const变量）
   3、允许添加自定义函数
   ---------------------------------------------------------------------
*/


int digitSum(int num) {
	while (num >= 10) {
		int sum = 0;
		while (num > 0) {
			sum += num % 10;
			num /= 10;
		}
		num = sum;
	}
	return num;
}

int adds(int digit[], int basis, int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (digitSum(digit[i]) == basis) {
			count++;
		}
	}
	return count;
}









int main()
{
	int n;
	cout<<"请输入数据的个数[1..10000]"<<endl;
	cin >> n;

	int digit[10001] = { 0 };
	cout << "请输入" << n << "个正整数"<<endl;
	for (int i = 0;i < n;i++) {
		cin >>digit[i];
	}

	cout<<"请输入要统计的基数[1..9]" << endl;
	int basis;
	cin >> basis;

	int sum = adds(digit, basis, n);

	cout << n << "个数中迭代累加后值为6的数字的个数 : " << sum << endl;



	return 0;
}

