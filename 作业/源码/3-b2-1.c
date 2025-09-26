/*2452545 计算机 刘晴语*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int k;
    printf("请输入一个[1..30000]间的整数:\n");
    scanf("%d", &k);
    printf("%s : %d\n", "万位", k / 10000 % 10);
    printf("%s : %d\n", "千位", k / 1000 % 10);
    printf("%s : %d\n", "百位", k / 100 % 10);
    printf("%s : %d\n", "十位", k / 10 % 10);
    printf("%s : %d\n", "个位", k  % 10);

    return 0;
}
