/*2452545 ����� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int k;
    printf("������һ��[1..30000]�������:\n");
    scanf("%d", &k);
    printf("%s : %d\n", "��λ", k / 10000 % 10);
    printf("%s : %d\n", "ǧλ", k / 1000 % 10);
    printf("%s : %d\n", "��λ", k / 100 % 10);
    printf("%s : %d\n", "ʮλ", k / 10 % 10);
    printf("%s : %d\n", "��λ", k  % 10);

    return 0;
}
