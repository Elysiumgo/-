/* 2452545 ����� ������ */
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main()
{
	int ret, x;

	while (1) {
		printf("������x��ֵ[0-100] : ");
		ret = scanf("%d", &x);
		if (ret && (x >= 0 && x <= 100))
			break;
		else {
			if (ret==1)
				printf("�����д�[ret=%d x=%d],����������\n", ret, x);
			else {
				printf("�����д�[ret=%d x=%d],����������\n", ret, x);
				while (getchar() != '\n')
					;
			}
		}
	}
	printf("ret=%d x=%d\n", ret, x);

	return 0;
}
