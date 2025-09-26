/*2452545 ������ �����*/
/*2450987  ������  2453718  ף֮��  2451034  �����  2452503  ������  2453277  ��ѩ÷*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 26
#define TNT 50

int main() 
{
    char map[ROW + 2][COL + 2] = { 0 };
    int mine_count = 0;
    for (int i = 1; i <= ROW; i++) {
        for (int j = 1; j <= COL; j++) {
            char c;
            while (1) {
                c = getchar();
                if (c == '*' || (c >= '0' && c <= '8'))
                    break; // �����ո�
            }

            if (c == '*') {
                map[i][j] = '*';
                mine_count++;
            }
            else {
                map[i][j] = c - '0'; // ת��Ϊ����
            }

        }
    }
    //ת����

    if (mine_count != TNT) {
        printf("����1\n");
        return 0;
    }
    //����Ƿ���50��TNT




    for (int i = 1; i < ROW + 1; i++) {
        for (int j = 1; j < COL + 1; j++) {
            if (map[i][j] != '*') {
                int count = 0;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        if (map[i + di][j + dj] == '*')
                            count++;
                    }
                }

                /* ���������ݱȽ� */
                if (count != map[i][j]) {
                    printf("����2\n");
                    return 0;
                }
            }
        }
    }









    printf("��ȷ\n");
    return 0;









}