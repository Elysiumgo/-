/*2452545 计算机 刘晴语*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>

int main()
{
    const double pi=3.14159;
    double r, h;
    printf("请输入半径和高度\n");
    scanf("%lf %lf", &r, &h);
    printf("%-10s : %.2f\n", "圆周长",2*pi*r);
    printf("%-10s : %.2f\n", "圆面积", pi * r * r);
    printf("%-10s : %.2f\n", "圆球表面积", 4 * pi * r * r);
    printf("%-10s : %.2f\n", "圆球体积",  4 * pi * r * r * r/3);
    printf("%-10s : %.2f\n", "圆柱体积", 2 * pi * r * r * h);

    return 0;
}
