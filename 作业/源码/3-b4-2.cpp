#include <iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int main()
{
	cout << "请输入三角形的两边及其夹角(角度)" << endl;
	int a, b, t;
	cin >> a >> b >> t;
	const double pi = 3.14159;
	float s;
	s = static_cast<float>(a * b * sin(t * pi / 180) / 2);
	cout << "三角形面积为 : " << setprecision(3) << setiosflags(ios::fixed) << s << endl;
	return 0;

}     