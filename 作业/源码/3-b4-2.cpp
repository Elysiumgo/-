#include <iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int main()
{
	cout << "�����������ε����߼���н�(�Ƕ�)" << endl;
	int a, b, t;
	cin >> a >> b >> t;
	const double pi = 3.14159;
	float s;
	s = static_cast<float>(a * b * sin(t * pi / 180) / 2);
	cout << "���������Ϊ : " << setprecision(3) << setiosflags(ios::fixed) << s << endl;
	return 0;

}     