/*������ 2452545 �����*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	printf("������ɼ������1000������������������\n");
	int score[1000];
	int i,count=0;
	for (i = 0;i < 1000;i++) {
		scanf("%d", &score[i]);
		count++;
		if (score[i] < 0 && count == 1) {
			printf("����Ч����\n");
			return 0;
		}
		else if (score[i] < 0) {
			break;
		}
			
	}
	//�������

	printf("���������Ϊ:\n");
	for (i = 0;i < count - 1;i++){
		printf("%d ", score[i]);
		if ((i + 1) % 10==0&&(i+1)>=10)
			printf("\n");
	}
	if (i < 10)
		printf("\n");

	//��ʼ����
	int j, t;
	for (i = 0;i < count - 1;i++) {
		for (j = 0;j < count - (i + 1);j++) { //��С����������
			if (score[j] < score[j + 1]) {
				t = score[j];
				score[j] = score[j + 1];
				score[j + 1] = t;
			}
		}
	}

	//���
	printf("�����������Ķ�Ӧ��ϵΪ:\n");
	int sum = 1;
	for (i = 0;i < count - 1;i++) {
		if (i < count - 2 && score[i] == score[i + 1]) { //����ʱ���ܷ������һ������
			sum++;
		}
		else {
			printf("%d %d\n", score[i], sum);
			sum = 1;
		}
	}
		return 0;
}





