/*2452545 计算机 刘晴语*/
#include <iostream>
#include <limits>
using namespace std;

int main()
{
	int a[21];
	int count = 0;
	int i;
	cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl;
	for (i = 0;i < 20;i++) {
		cin >> a[i];
		if (cin.fail()) {
			cout << "无有效输入" << endl;
			return 0;
		}
		if ((a[i] < 0|| a[i] == 0) && count == 0) {  // 第一个输入就结束
			cout << "无有效输入" << endl;
			return 0;
		}
		if (a[i] <= 0)
			break;
		
		count++;
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	
	cout << "原数组为：" << endl;
	for (int i = 0;i < count;i++)
		cout << a[i] << ' ';
	cout << endl;

	
	cout << "请输入要插入的正整数" << endl;
	int k;
	cin >> k;
	int charu = count;  // 默认插入到最后
	for (int i = 0; i < count; i++) {
		if (a[i] >= k) {
			charu = i;
			break;
		}
	}
	for (int i = count; i > charu; i--) 
		a[i] = a[i - 1]; //后移
	
	a[charu] = k;
	cout << "插入后的数组为：" << endl;
	for (int i = 0; i < count+1; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;

	return 0;
	
}
