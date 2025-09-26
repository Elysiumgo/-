/*2452545 计算机 刘晴语*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>

int main()
{
    printf("请输入三角形的两边及其夹角(角度)\n");
    int a, b, t;
    const double pi = 3.14159;
    scanf("%d %d %d", &a, &b, &t);
    printf("%s : %.3f", "三角形面积为",a*b*sin(t*pi/180)/2 );

    return 0;
}
