/*2452545 ����� ������*/
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int main()
{
	int i, year, month, day, n,leap,ret;
	while (1) {
		printf("���������(2000-2030)���·�(1-12) : ");
		ret = scanf("%d %d", &year, &month);
		if (ret==2 && year >= 2000 && year <= 2030 && month >= 1 && month <= 12)
			break;
		else {
			if (ret == 2)
				printf("����Ƿ�������������\n");
			else if(ret!=1){
				printf("����Ƿ�������������\n");
				while (getchar() != '\n')
					;
			}
		}
	}
	//�ж���ݺ��·ݽ���
	while (1) {
		printf( "������%d��%d��1�յ�����(0-6��ʾ������-������) : ",year,month);
		ret = scanf("%d", &day);
		if (ret && day <= 6 && day >= 0)
			break;
		else {
			if (ret) 
				printf("����Ƿ�������������\n");
			else {
				printf("����Ƿ�������������\n");
				while (getchar() != 0)
					;
			}
		}
	}
	printf("\n");
	//�ж�����������
	leap = (year % 4 == 0);
	printf("%d��%d�µ�����Ϊ:\n", year, month);
	printf("������  ����һ  ���ڶ�  ������  ������  ������  ������\n" );
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		for (n = 1;;n++) {
			for (;day > 0;day--) {
				printf("%6s", " ");
				printf("%2s", " ");
				n++;
			}
			for (i = 1;i <= 31;i++) {
				printf("%4d", i);
				printf("%4s", " ");
				n++;
				if (n > 7) {
					printf("\n");
					n = 1;
				}
			}
			if (i >= 31)
				break;
		}

	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		for (n = 1;;n++) {
			for (;day > 0;day--) {
				printf("%6s", " ");
				printf("%2s", " ");
				n++;
			}
			for (i = 1;i <= 30;i++) {
				printf("%4d", i);
				printf("%4s", " ");
				n++;
				if (n > 7) {
					printf("\n");
					n = 1;
				}
			}
			if (i >= 30)
				break;
		}

	}
	else if (month == 2 && leap) {
		for (n = 1;;n++) {
			for (;day > 0;day--) {
				printf("%6s", " ");
				printf("%2s", " ");
				n++;
			}
			for (i = 1;i <= 29;i++) {
				printf("%4d", i);
				printf("%4s", " ");
				n++;
				if (n > 7) {
					printf("\n");
					n = 1;
				}
			}
			if (i >= 29)
				break;
		}

	}
	else if (month == 2 && leap == 0) {
		for (n = 1;;n++) {
			for (;day > 0;day--) {
				printf("%6s", " ");
				printf("%2s", " ");
				n++;
			}
			for (i = 1;i <= 28;i++) {
				printf("%4d", i);
				printf("%4s", " ");
				n++;
				if (n > 7) {
					printf("\n");
					n = 1;
				}
			}
			if (i >= 28)
				break;
		}

	}

	printf("\n");
	return 0;
}