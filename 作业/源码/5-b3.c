/*������ 2452545 �����*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>





int if_leap(int y, int m, int d) 
{
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int month2[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int leap = (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
	if (m > 12 || m <= 0) {
		printf("�������-�·ݲ���ȷ\n");
		return 3;
	}
	else if ((!leap) && (d > month[m - 1])) {
		printf("�������-�����µĹ�ϵ�Ƿ�\n");
		return 3;
	}
	else if (leap && d > month2[m - 1]) {
		printf("�������-�����µĹ�ϵ�Ƿ�\n");
		return 3;
	}
	else
		return leap;
}


int what_day(int m, int d, int leap) 
{
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int month2[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int i,sum=0;
	if (!leap){
		for (i = 0;i < m-1;i++) {
			sum += month[i];
		}
	}
	else {
		for (i = 0;i < m-1;i++) {
			sum += month2[i];
		}
	}
	return sum + d;
}



int main()
{
	printf("�������꣬�£���\n");
	int y = 0, m = 0, d = 0, t = 0,day;
	scanf("%d %d %d", &y, &m, &d);
	int leap=if_leap(y, m, d);
	if (leap == 3)
		return 0;
	day=what_day(m, d,leap);
	
	printf("%d-%d-%d��%d��ĵ�%d��\n", y, m, d, y, day);
	return 0; 
}
