/* 2452545 ����� ������ */
#include <iostream>
#include <string>
using namespace std;

const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
string result;  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */



void daxie(int num, int flag_of_zero)
{
	if (num!=0){
		char tem[3] = { chnstr[num * 2],chnstr[num * 2 + 1],0 };
		result += tem;
	}
	else if (num == 0 && flag_of_zero) {
		char tem[3] = { chnstr[num * 2],chnstr[num * 2 + 1],0 };
		result += tem;
	}

}


int main()
{
	double k;
	long long k1, i, k2, i2;
	int count = 1;
	bool flag_of_zero = true;
	bool have_zero = false;


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
				result += "ʰ";
				break;
			case 2:
				result += "��";
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
		if (k1 >= i)
			daxie(k1 / i % 10, flag_of_zero);

		if (k1 / i % 10 == 0) //�����λΪ0�����һλ0����
			flag_of_zero = false;
		else
			flag_of_zero = true;//ÿ��һλ����0������flag

		if (k1 / i % 10) {//��λ����0��������м䵥λ
			switch (count) {
			case 1:
				result += "Ǫ";
				break;
			case 2:
				result += "��";
				break;
			case 3:
				result += "ʰ";
				break;
			}
		}
	}
	if ((k1 / 10000000 % 10 != 0) || k1 / 1000000 % 10 || k1 / 100000 % 10 || k1 / 10000 % 10)
		result += "��";
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
				result += "Ǫ";
				break;
			case 2:
				result += "��";
				break;
			case 3:
				result += "ʰ";
				break;
			}
		}
	}
	if (k1 > 0)
		result += "Բ";

	flag_of_zero = true;
	have_zero = false;

	if (k1 < 1 && k2 == 0) {
		daxie(k1 % 10, flag_of_zero);//��������0Ԫ
		result += "Բ";
	}
	if (k2 == 0)
		result += "��";
	count = 1;
	//����С��λ
	for (i = 10;i >= 1;i /= 10, count++) {
		if (k2 > 0) {
			flag_of_zero = false;
			if (k1 != 0 && k2 / i % 10 == 0 && i == 10)
				flag_of_zero = true;
			daxie(k2 / i % 10, flag_of_zero);

			if (k2 / i % 10) {//��λ����0��������м䵥λ
				switch (count) {
				case 1:
					result += "��";
					break;
				case 2:
					result += "��";
					break;
				}
			}
		}
	}
	if (k2 % 10 == 0 && k2 != 0)
		result += "��";





	cout << result << endl;  /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
	return 0;
}
