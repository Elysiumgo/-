/* 2452545 计算机 刘晴语*/
#include<iostream>
#include<climits>
using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int max(int a, int b, int c) {
	int t;
	t = a > b ? a : b;
	return t > c ? t : c;
}

int max(int a, int b, int c,int d) {
	int t1,t2;
	t1 = a > b ? a : b;
	t2 = t1 > c ? t1 : c;
	return t2 > d ? t2 : d;
}




int main()
{
	int num, a, b, c, d;
	
	while (1) {
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> num;
		if (num == 2) {
			cin >> a >> b;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
			else
			{
				cout << "max=" << max(a, b) << endl;
				break;
			}
		}
		if (num == 3) {
			cin >> a >> b >> c;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
			cout << "max=" << max(a, b, c) << endl;
			break;
		}
		if (num == 4) {
			cin >> a >> b >> c >> d;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
			cout << "max=" << max(a, b, c, d) << endl;
			break;
		}
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (num != 2 && num != 3 && num != 4) {
			cout << "个数输入错误" << endl;
			break;
		}
			
			

	}
}


