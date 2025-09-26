/*刘晴语 2452545 计算机*/
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	cout << "请输入找零值：" << endl;
	float k;
	int t50=0, t20=0, t10=0,t5=0, t1=0, t05=0, t01=0, t005=0, t002=0, t001=0,k2=0;
	cin >> k;
	t50 = static_cast<int>(k/50) ;
	t20 = static_cast<int>((k - 50*t50)/20);
	t10= static_cast<int>((k - 50 * t50-20*t20)/10);
	t5 = static_cast<int>((k - 50 * t50 - 20 * t20-10*t10)/5);
	t1 = static_cast<int>(k - 50 * t50 - 20 * t20 - 5 * t5-10*t10);

	k2 = static_cast<int>(100 * (k - 50 * t50 - 20 * t20 - 5 * t5-10*t10 - t1)+0.5); //处理小数部分
	t05 = static_cast<int>(k2 / 50);
	t01 = static_cast<int>((k2 - 50 * t05)/10);
	t005 = static_cast<int>((k2 - 50 * t05-10*t01)/5);
	t002 = static_cast<int>((k2 - 50 * t05 - 10 * t01-5*t005) / 2);
	t001 = static_cast<int>(k2 - 50 * t05 - 10 * t01 - 5 * t005 - 2 * t002);

	cout << "共" << (t50 + t20 + t10 + t5 + t1 + t05 + t01 + t005 + t002 + t001) << "张找零，具体如下：" << endl;

	if (t50 != 0)
		cout <<left<<setw(4)<< "50元" << " : " << t50 << "张" << endl;
	if (t20 != 0)
		cout << left << setw(4) << "20元" << " : " << t20 << "张" << endl;
	if (t10 != 0)
		cout << left << setw(4) << "10元" << " : " << t10 << "张" << endl;
	if (t5 != 0)
		cout << left << setw(4) << "5元" << " : " << t5 << "张" << endl;
	if (t1 != 0)
		cout << left << setw(4) << "1元" << " : " << t1 << "张" << endl;
	if (t05 != 0)
		cout << left << setw(4) << "5角" << " : " << t05 << "张" << endl;
	if (t01 != 0)
		cout << left << setw(4) << "1角" << " : " << t01 << "张" << endl;
	if (t005 != 0)
		cout << left << setw(4) << "5分" << " : " << t005 << "张" << endl;
	if (t002 != 0)
		cout << left << setw(4) << "2分" << " : " << t002 << "张" << endl;
	if (t001 != 0)
		cout << left << setw(4) << "1分" << " : " << t001 << "张" << endl;



	return 0;
}