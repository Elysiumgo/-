/* 2452545 计算机 刘晴语 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----具体要求----
   1、不允许添加其它头文件
   2、允许定义一个全局变量、不允许定义静态局部变量
   3、不允许添加其它函数
   4、main函数处理输入，允许循环
   --------------------------------------------------------------------- */


   /***************************************************************************
     函数名称：
     功    能：打印n层汉诺塔的移动顺序
     输入参数：int n：层数
               char src：起始柱
               char tmp：中间柱
               char dst：目标柱
     返 回 值：
     说    明：1、函数名、形参、返回类型均不准动
               2、本函数不允许出现任何形式的循环
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    static int i = 0;
    if (n == 1) {
        i++;
        printf("%5d: %2d# %c-->%c\n", i, n, src, dst);
    }

    else {
        hanoi(n - 1, src, dst, tmp);
        i++;
        printf("%5d: %2d# %c-->%c\n", i, n, src, dst);
        hanoi(n - 1, tmp, src, dst);
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
            2、处理输入错误时，允许使用循环
            3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
***************************************************************************/
int main()
{
    int n;
    char src, dst, tmp = 'A';
    while (1) {
        int ret;
        printf("请输入汉诺塔的层数(1-16)\n" );
        ret = scanf("%d", &n);
        if (ret && n >= 1 && n <= 16) {
            while (getchar() != '\n')
                ;
            break;
        }
        else {
            while (getchar() != '\n')
                ;
        }

    }
    //n输入错误处理完毕

    while (1) {
        int ret;
        printf("请输入起始柱(A-C)\n" );
        ret = scanf("%c", &src);
        if (ret && src == 'A' || src == 'a' || src == 'B' || src == 'b' || src == 'C' || src == 'c') {
            while (getchar() != '\n')
                ;
            break;
        }
        else {
            while (getchar() != '\n')
                ;
        }
    }
    //起始柱输入错误处理完毕

    while (1) {
        int ret;
        printf("请输入目标柱(A-C)\n") ;
        ret=scanf("%c", &dst);
        if (ret && dst != src && (dst == 'A' || dst == 'a' || dst == 'B' || dst == 'b' || dst == 'C' || dst == 'c')) {
            while (getchar() != '\n')
                ;
            break;
        }//输入正确且与src不同
        else if (ret && dst == src && (dst == 'A' || dst == 'a' || dst == 'B' || dst == 'b' || dst == 'C' || dst == 'c')) {
            printf("%s%c%s%c%s\n", "目标柱(", src,")不能与起始柱(" , src , ")相同");
            while (getchar() != '\n')
                ;
        }//输入正确但与src相同
        else {
            while (getchar() != '\n')
                ;
        }
    }
    //目标柱输入错误处理完毕

    if ((src == 'A' && dst == 'B') || (src == 'a' && dst == 'b') || (src == 'B' && dst == 'A') || (src == 'b' && dst == 'a'))
        tmp = 'C';
    if ((src == 'A' && dst == 'C') || (src == 'a' && dst == 'c') || (src == 'C' && dst == 'A') || (src == 'c' && dst == 'a'))
        tmp = 'B';
    if ((src == 'C' && dst == 'B') || (src == 'c' && dst == 'b') || (src == 'C' && dst == 'A') || (src == 'c' && dst == 'a'))
        tmp = 'A';
    //tmp为中间柱

    
    if (src == 'a' || src == 'b' || src == 'c')
        src -= 32;
    if (dst == 'a' || dst == 'b' || dst == 'c')
        dst -= 32;
    //统一大小写

    printf( "移动步骤为:\n");
    hanoi(n, src, tmp, dst);

    printf("\n");





}
