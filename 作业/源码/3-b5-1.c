/*������ 2452545 �����*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	printf( "�������꣬�£���\n");
	int y = 0, m = 0, d = 0, t = 0;
	scanf("%d %d %d", &y, &m, &d);
	int leap = (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
	int r = (m == 1 && d > 31) || (m == 2 && d > 29) || (m == 3 && d > 31) || (m == 4 && d > 30) || (m == 5 && d > 31) || (m == 6 && d > 30) || (m == 7 && d > 31) || (m == 8 && d > 31) || (m == 9 && d > 30) || (m == 10 && d > 31) || (m == 11 && d > 30) || (m == 12 && d > 31);
	int leap2 = (leap == 0 && (m == 2 && d > 28));
	if (m > 12 || m <= 0)
		printf("�������-�·ݲ���ȷ\n");
	else if (leap2 || r)
		printf( "�������-�����µĹ�ϵ�Ƿ�\n" );
	else if (r == 0 && leap == 0)
	{
		if (m == 1)
			t = d;
		if (m == 2)
			t = 31 + d;
		if (m == 3)
			t = 59 + d;
		if (m == 4)
			t = 90 + d;
		if (m == 5)
			t = 120 + d;
		if (m == 6)
			t = 151 + d;
		if (m == 7)
			t = 181 + d;
		if (m == 8)
			t = 212 + d;
		if (m == 9)
			t = 243 + d;
		if (m == 10)
			t = 273 + d;
		if (m == 11)
			t = 303 + d;
		if (m == 12)
			t = 334 + d;
		printf("%d-%d-%d��%d��ĵ�%d��\n", y, m, d, y, t);
	}
	else if (r == 0 && leap == 1)
	{
		if (m == 1)
			t = d;
		if (m == 2)
			t = 31 + d;
		if (m == 3)
			t = 60 + d;
		if (m == 4)
			t = 91 + d;
		if (m == 5)
			t = 121 + d;
		if (m == 6)
			t = 152 + d;
		if (m == 7)
			t = 182 + d;
		if (m == 8)
			t = 213 + d;
		if (m == 9)
			t = 244 + d;
		if (m == 10)
			t = 274 + d;
		if (m == 11)
			t = 304 + d;
		if (m == 12)
			t = 335 + d;
		printf("%d-%d-%d��%d��ĵ�%d��\n", y, m, d, y, t);
	}

	return 0;




}