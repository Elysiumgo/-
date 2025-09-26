/* 2452545 计算机 刘晴语 */
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main()
{
	int ret, x;

	while (1) {
		printf("请输入x的值[0-100] : ");
		ret = scanf("%d", &x);
		if (ret && (x >= 0 && x <= 100))
			break;
		else {
			if (ret==1)
				printf("输入有错[ret=%d x=%d],请重新输入\n", ret, x);
			else {
				printf("输入有错[ret=%d x=%d],请重新输入\n", ret, x);
				while (getchar() != '\n')
					;
			}
		}
	}
	printf("ret=%d x=%d\n", ret, x);

	return 0;
}
