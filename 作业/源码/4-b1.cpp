/* 2452545 ����� ������ */
#include <iostream>
using namespace std;

bool flag_of_zero = true;
bool have_zero = false;


/***************************************************************************
  �������ƣ�daxie
  ��    �ܣ������д��0~9
  ���������
  �� �� ֵ��num flag_of_zero
  ˵    �������������⣬�������κκ�����������㡱-������!!!!!!
***************************************************************************/
static void daxie(int num, int flag_of_zero)
{

	/* ������Ա��������κ��޸� */
	switch (num) {
	case 0:
		if (flag_of_zero)	//�˱��ʲô��˼������˼��
		cout<< "��";
		break;
	case 1:
		cout << "Ҽ";
		break;
	case 2:
		cout << "��";
		break;
	case 3:
		cout << "��";
		break;
	case 4:
		cout << "��";
		break;
	case 5:
		cout << "��";
		break;
	case 6:
		cout << "½";
		break;
	case 7:
		cout << "��";
		break;
	case 8:
		cout << "��";
		break;
	case 9:
		cout << "��";
		break;
	default:
		cout << "error";
		break;
	}
}

/* �ɸ�����Ҫ�Զ�����������(Ҳ���Բ�����) */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	double k;
	long long k1, i, k2, i2;
	int count = 1;
	cout << "������[0-100��)֮�������:" << endl;
	cin >> k;
	k1 = static_cast<long long>(k);
	k2 = static_cast<long long>(100 * (k - k1 + 0.005));
	cout << "��д�����:" << endl;
	//����ʮ�ڡ���
	for (i = 1000000000;i >= 100000000;i /= 10, count += 1) {
		if (k >= i) {
			flag_of_zero = false;
			daxie(k1 / i % 10, flag_of_zero);
			switch (count) {
			case 1:
				cout << "ʰ";
				break;
			case 2:
				cout << "��";
				break;
			}
		}
	}
	count = 1;

	flag_of_zero = true;
	have_zero = false;

	//����ǧ��-��λ
	for (i = 10000000;i >= 10000;i /= 10, count++) {
		if (k1 / i % 10 == 0) {
			for (i2 = i / 10;i2 >= 10000;i2 /= 10) {
				if (k1 / i2 % 10 == 0)				//��鱾λ�����Ƿ���0�����������false�������0
					flag_of_zero = false;

				else {
					flag_of_zero = true;
					break;
				}
			}
			flag_of_zero = (flag_of_zero) && !have_zero;
			have_zero = true;
		}
		else {
			flag_of_zero = true;
			have_zero = false;
		}
		if (i == 10000)
			flag_of_zero = false;
		if(k1>=i)
			daxie(k1 / i % 10, flag_of_zero);

		if (k1 / i % 10 == 0) //�����λΪ0�����һλ0����
			flag_of_zero = false;
		else
			flag_of_zero = true;//ÿ��һλ����0������flag

		if (k1 / i % 10) {//��λ����0��������м䵥λ
			switch (count) {
			case 1:
				cout << "Ǫ";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "ʰ";
				break;
			}
		}
}
if ((k1 / 10000000 % 10 != 0) || k1 / 1000000 % 10 || k1 / 100000 % 10 || k1 / 10000 % 10)
cout << "��";
count = 1;
flag_of_zero = true;
have_zero = false;
//����ǧ-��λ
for (i = 1000;i >= 1;i /= 10, count++) {
	if (k1 / i % 10 == 0) {
		for (i2 = i / 10;i2 >= 1;i2 /= 10) {
			if (k1 / i2 % 10 == 0)				//��鱾λ�����Ƿ���0�����������false�������0
				flag_of_zero = false;
			else {
				flag_of_zero = true;
				break;
			}
		}
		flag_of_zero = (flag_of_zero) && !have_zero;
		have_zero = true;
	}
	else {
		flag_of_zero = true;
		have_zero = false;
	}
	if (i == 1)
		flag_of_zero = false;
	if (k1 >= i)
		daxie(k1 / i % 10, flag_of_zero);

	if (k1 / i % 10) {//��λ����0��������м䵥λ
		switch (count) {
		case 1:
			cout << "Ǫ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "ʰ";
			break;
		}
	}
}
if (k1 > 0)
	cout << "Բ";

flag_of_zero = true;
have_zero = false;

if (k1 < 1&&k2==0) {
	daxie(k1 % 10, flag_of_zero);//��������0Ԫ
	cout << "Բ";
}
if (k2 == 0)
cout << "��";
count = 1;
//����С��λ
for (i = 10;i >= 1;i /= 10, count++) {
	if (k2 > 0) {
		flag_of_zero = false;
		if (k1!=0&&k2 / i % 10 == 0&&i==10)
			flag_of_zero = true;
		daxie(k2 / i % 10, flag_of_zero);
		
		if (k2 / i % 10) {//��λ����0��������м䵥λ
			switch (count) {
			case 1:
				cout << "��";
				break;
			case 2:
				cout << "��";
				break;
			}
		}
	}
}
if (k2 % 10 == 0 && k2 != 0)
cout << "��";

cout << endl;






/* ������� */
return 0;
}
