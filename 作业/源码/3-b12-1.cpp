/* 2452545 ����� ������ */
#include <iostream>
#include<limits> 
using namespace std;

int main()
{
	int x;

	while (1) {
		cout << "������x��ֵ[0-100] : ";
		if ((cin >> x) && x >= 0 && x <= 100) //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
			break;
		else {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			
		}
	}

		cout << "cin.good()=" << cin.good() << " x=" << x << endl; //�˾䲻׼��������Ҫ�����ʱgoodΪ1

		return 0;
	}

