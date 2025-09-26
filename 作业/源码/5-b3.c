/*刘晴语 2452545 计算机*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>





int if_leap(int y, int m, int d) 
{
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int month2[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int leap = (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
	if (m > 12 || m <= 0) {
		printf("输入错误-月份不正确\n");
		return 3;
	}
	else if ((!leap) && (d > month[m - 1])) {
		printf("输入错误-日与月的关系非法\n");
		return 3;
	}
	else if (leap && d > month2[m - 1]) {
		printf("输入错误-日与月的关系非法\n");
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
	printf("请输入年，月，日\n");
	int y = 0, m = 0, d = 0, t = 0,day;
	scanf("%d %d %d", &y, &m, &d);
	int leap=if_leap(y, m, d);
	if (leap == 3)
		return 0;
	day=what_day(m, d,leap);
	
	printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, day);
	return 0; 
}
