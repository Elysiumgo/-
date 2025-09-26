/*2452545 计算机 刘晴语*/
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int main()
{
	int i, year, month, day, n,leap,ret;
	while (1) {
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		ret = scanf("%d %d", &year, &month);
		if (ret==2 && year >= 2000 && year <= 2030 && month >= 1 && month <= 12)
			break;
		else {
			if (ret == 2)
				printf("输入非法，请重新输入\n");
			else if(ret!=1){
				printf("输入非法，请重新输入\n");
				while (getchar() != '\n')
					;
			}
		}
	}
	//判断年份和月份结束
	while (1) {
		printf( "请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ",year,month);
		ret = scanf("%d", &day);
		if (ret && day <= 6 && day >= 0)
			break;
		else {
			if (ret) 
				printf("输入非法，请重新输入\n");
			else {
				printf("输入非法，请重新输入\n");
				while (getchar() != 0)
					;
			}
		}
	}
	printf("\n");
	//判断星期数结束
	leap = (year % 4 == 0);
	printf("%d年%d月的月历为:\n", year, month);
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n" );
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