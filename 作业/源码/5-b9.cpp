/*2452545 ����� ������*/
#include<iostream>
#include <limits>
using namespace std;

int main()
{
	int digit[9][9] = { 0 };
	int sum = 0;
	int i;
	int j;
	cout << "������9*9�ľ���ֵΪ1-9֮��" << endl;
	for (i = 0;i < 9;i++) {
		for (j = 0;j < 9;j++) {
			while (1) {
				cin >> digit[i][j];
				if (cin.fail() || digit[i][j] < 1 || digit[i][j] > 9) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "�����������" << i + 1 << "��" << j + 1 << "�е�ֵ: " << endl;
				}
				else
					break;

			}
		}
	}
	//������������

	bool shudu = 1;
	int check[10] = { 0 };//����ظ�
	for (i = 0; i < 9 && shudu; i++) {
		for (j = 0; j < 9; j++) {
			check[digit[i][j]] += 1;       // ������+1
			if (check[digit[i][j]] > 1) {  // ����Ƿ��ظ�
				shudu = false;
				break;
			}
		}
		//����
	}
	for (int k = 1; k <= 9; k++)
		check[k] = 0;// ���

		for (j = 0; j < 9 && shudu; j++) {
			for (i = 0; i < 9; i++) {
				check[digit[i][j]] += 1;       // ������+1
				if (check[digit[i][j]] > 1) {  // ����Ƿ��ظ�
					shudu = false;
					break;
				}
			}
		}

		//����


	
	for (int row = 0; row < 9 && shudu; row += 3) {
		for (int column = 0; column < 9 && shudu; column += 3) {
			for (int k = 1; k <= 9; k++)
				check[k] = 0; //���

			// ���Ź���
			for (i = row; i < row + 3 && shudu; i++) {
				for (j = column; j < column + 3 && shudu; j++) {
					check[digit[i][j]]++;
					if (check[digit[i][j]] > 1) {
						shudu = false;
						break;
					}
				}
			}
		}
	}







	cout << (shudu ? "��" : "����") << "�����Ľ�" << endl;
	
	return 0;
}
