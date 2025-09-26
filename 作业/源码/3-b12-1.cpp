/* 2452545 计算机 刘晴语 */
#include <iostream>
#include<limits> 
using namespace std;

int main()
{
	int x;

	while (1) {
		cout << "请输入x的值[0-100] : ";
		if ((cin >> x) && x >= 0 && x <= 100) //读入x的方式必须是 cin>>int型变量，不允许其他方式
			break;
		else {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			
		}
	}

		cout << "cin.good()=" << cin.good() << " x=" << x << endl; //此句不准动，并且要求输出时good为1

		return 0;
	}

