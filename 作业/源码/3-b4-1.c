/*2452545 ����� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>

int main()
{
    printf("�����������ε����߼���н�(�Ƕ�)\n");
    int a, b, t;
    const double pi = 3.14159;
    scanf("%d %d %d", &a, &b, &t);
    printf("%s : %.3f", "���������Ϊ",a*b*sin(t*pi/180)/2 );

    return 0;
}
