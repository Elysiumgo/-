/* 2452545 ����� ������ */
#include <iostream>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ��������������궨�塢ȫ��const������
   3����������Զ��庯��
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
	cout<<"���������ݵĸ���[1..10000]"<<endl;
	cin >> n;

	int digit[10001] = { 0 };
	cout << "������" << n << "��������"<<endl;
	for (int i = 0;i < n;i++) {
		cin >>digit[i];
	}

	cout<<"������Ҫͳ�ƵĻ���[1..9]" << endl;
	int basis;
	cin >> basis;

	int sum = adds(digit, basis, n);

	cout << n << "�����е����ۼӺ�ֵΪ6�����ֵĸ��� : " << sum << endl;



	return 0;
}

