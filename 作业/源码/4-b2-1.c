/*2452545 ����� ������*/
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int week(int year, int month, int day) {
	if (month < 3) {
		month += 12;
		year--;
	}
	int c = year / 100;
	int m = month;
	int w = 0;
	int y = year % 100;
	int d = day;
	w = y + (int)(y / 4) + (int)(c / 4) - 2 * c + (int)(13 * (m + 1) / 5) + d - 1;
	w = (w % 7 + 7) % 7;
	switch (w) {
	case 0:
		printf( "��");
		break;
	case 1:
		printf("һ");
		break;
	case 2:
		printf("��");
		break;
	case 3:
		printf("��");
		break;
	case 4:
		printf("��");
		break;
	case 5:
		printf("��");
		break;
	case 6:
		printf("��");
		break;

	}
	return 0;
}











int main()
{
	int  year, month, day,  leap, ret;
	while (1) {
		printf("��������[1900-2100]���¡��գ�");
		ret = scanf("%d %d %d", &year, &month,&day);
		leap= (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
		if (year > 2100 || year < 1900)
			printf( "��ݲ���ȷ������������\n" );
		else if (month > 12)
			printf( "�·ݲ���ȷ������������\n" );
		else if ((!leap && month == 2 && day > 28) || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) || day > 31 || (leap && month == 2 && day > 29))
			printf( "�ղ���ȷ������������\n" );
		else if (ret==3 && year >= 1900 && year <= 2100 && month >= 1 && month <= 12)
			break;
		if (ret!=3) {
			while (getchar() != '\n')
				;
		}
	}
	printf("����");
	week(year, month, day);
	printf("\n");
}