/*2452545 ����� ������*/
#include <iostream>
#include <limits>
using namespace std;

int main()
{
	int a[21];
	int count = 0;
	int i;
	cout << "��������������������������20������0������������" << endl;
	for (i = 0;i < 20;i++) {
		cin >> a[i];
		if (cin.fail()) {
			cout << "����Ч����" << endl;
			return 0;
		}
		if ((a[i] < 0|| a[i] == 0) && count == 0) {  // ��һ������ͽ���
			cout << "����Ч����" << endl;
			return 0;
		}
		if (a[i] <= 0)
			break;
		
		count++;
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	
	cout << "ԭ����Ϊ��" << endl;
	for (int i = 0;i < count;i++)
		cout << a[i] << ' ';
	cout << endl;

	
	cout << "������Ҫ�����������" << endl;
	int k;
	cin >> k;
	int charu = count;  // Ĭ�ϲ��뵽���
	for (int i = 0; i < count; i++) {
		if (a[i] >= k) {
			charu = i;
			break;
		}
	}
	for (int i = count; i > charu; i--) 
		a[i] = a[i - 1]; //����
	
	a[charu] = k;
	cout << "����������Ϊ��" << endl;
	for (int i = 0; i < count+1; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;

	return 0;
	
}
