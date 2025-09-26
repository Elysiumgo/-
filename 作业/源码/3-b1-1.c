/*2452545 ����� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>

int main()
{
    const double pi=3.14159;
    double r, h;
    printf("������뾶�͸߶�\n");
    scanf("%lf %lf", &r, &h);
    printf("%-10s : %.2f\n", "Բ�ܳ�",2*pi*r);
    printf("%-10s : %.2f\n", "Բ���", pi * r * r);
    printf("%-10s : %.2f\n", "Բ������", 4 * pi * r * r);
    printf("%-10s : %.2f\n", "Բ�����",  4 * pi * r * r * r/3);
    printf("%-10s : %.2f\n", "Բ�����", 2 * pi * r * r * h);

    return 0;
}
