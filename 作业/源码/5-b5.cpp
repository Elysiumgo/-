/*������ 2452545 �����*/
#include <iostream>
using namespace std;

int main()
{
	cout << "������ɼ������1000������������������" << endl;
	int score[1000];
	int i, count = 0;
	for (i = 0;i < 1000;i++) {
		cin >> score[i];
		count++;
		if (count == 1 && score[i] < 0) {
			cout << "����Ч����" << endl;
			return 0;
		}
		else if (score[i] < 0)
			break;
	}
	//�������
	cout << "���������Ϊ:" << endl;
	for (i = 0;i < count - 1;i++) {
		cout << score[i] << ' ';
		if ((i + 1) >= 10 && (i + 1) % 10 == 0)
			cout << endl;

	}
	if (i < 10)
		cout << endl;

	

	//��ʼ����
	int j, t;
	for (i = 0;i < count - 1;i++) {

		for (j = 0;j < count - (i + 1);j++) {
			if (score[j] < score[j + 1]) {
				t = score[j];
				score[j] = score[j + 1];
				score[j + 1] = t;
			}
		}
	}


	//���
	cout << "���������εĶ�Ӧ��ϵΪ:" << endl;
	int rank = 1;
	for (i = 0;i < count - 1;i++) {
		cout << score[i] << ' ' << rank << endl;
		if (i < count - 2 &&score[i] != score[i + 1])
			rank = i + 2;
	}



	return 0;

}