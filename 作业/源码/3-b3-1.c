/*2452545 ����� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    double k;
    long long k1;
    printf("������[0-100��)֮�������:\n");
    scanf("%lf", &k);
    k1 = (long long)k;
    printf("%-6s : %lld\n", "ʮ��λ", k1 / 1000000000 % 10);
    printf("%-6s : %lld\n", "��λ", k1 / 100000000 % 10);
    printf("%-6s : %lld\n", "ǧ��λ", k1 / 10000000 % 10);
    printf("%-6s : %lld\n", "����λ", k1 / 1000000 % 10);
    printf("%-6s : %lld\n", "ʮ��λ", k1 / 100000 % 10);
    printf("%-6s : %lld\n", "��λ", k1 / 10000 % 10);
    printf("%-6s : %lld\n", "ǧλ", k1 / 1000 % 10);
    printf("%-6s : %lld\n", "��λ", k1 / 100 % 10);
    printf("%-6s : %lld\n", "ʮλ", k1 / 10 % 10);
    printf("%-6s : %lld\n", "Բ", k1  % 10);

    long long k2 = (long long)(100*(k - k1)+0.5);
    printf("%-6s : %lld\n", "��", k2/10);
    printf("%-6s ; %lld\n", "��", k2 % 10);

    return 0;
}
