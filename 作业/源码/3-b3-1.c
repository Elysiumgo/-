/*2452545 计算机 刘晴语*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    double k;
    long long k1;
    printf("请输入[0-100亿)之间的数字:\n");
    scanf("%lf", &k);
    k1 = (long long)k;
    printf("%-6s : %lld\n", "十亿位", k1 / 1000000000 % 10);
    printf("%-6s : %lld\n", "亿位", k1 / 100000000 % 10);
    printf("%-6s : %lld\n", "千万位", k1 / 10000000 % 10);
    printf("%-6s : %lld\n", "百万位", k1 / 1000000 % 10);
    printf("%-6s : %lld\n", "十万位", k1 / 100000 % 10);
    printf("%-6s : %lld\n", "万位", k1 / 10000 % 10);
    printf("%-6s : %lld\n", "千位", k1 / 1000 % 10);
    printf("%-6s : %lld\n", "百位", k1 / 100 % 10);
    printf("%-6s : %lld\n", "十位", k1 / 10 % 10);
    printf("%-6s : %lld\n", "圆", k1  % 10);

    long long k2 = (long long)(100*(k - k1)+0.5);
    printf("%-6s : %lld\n", "角", k2/10);
    printf("%-6s ; %lld\n", "分", k2 % 10);

    return 0;
}
