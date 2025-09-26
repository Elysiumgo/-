/*2452545 刘晴语 计算机*/
/*2450987  蒋理智  2453718  祝之涵  2451034  崔艺窈  2452503  赵若妍  2453277  白雪梅*/
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
                    break; // 跳过空格
            }

            if (c == '*') {
                map[i][j] = '*';
                mine_count++;
            }
            else {
                map[i][j] = c - '0'; // 转换为数字
            }

        }
    }
    //转下来

    if (mine_count != TNT) {
        printf("错误1\n");
        return 0;
    }
    //检查是否是50个TNT




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

                /* 与输入数据比较 */
                if (count != map[i][j]) {
                    printf("错误2\n");
                    return 0;
                }
            }
        }
    }









    printf("正确\n");
    return 0;









}