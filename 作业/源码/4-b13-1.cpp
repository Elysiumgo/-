/* 2452545 计算机 刘晴语 */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、仅允许hanoi中定义一个静态局部变量
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
               3、允许定义一个静态局部变量
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    static int i = 0;
    if (n == 1)
    {
        i++;
        cout << setw(5) << i <<": " << setw(2) << n << '#' << ' ' << src << "-->" << dst << endl;
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        i++;
        cout << setw(5) << i << ": " << setw(2) << n << '#' << ' ' << src << "-->" << dst << endl;
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
        cout << "请输入汉诺塔的层数(1-16)" << endl;
        cin >> n;
        if (cin.good() && n >= 1 && n <= 16) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    }
    //n输入错误处理完毕

    while (1) {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;
        if (cin.good() && src == 'A' || src == 'a' || src == 'B' || src == 'b' || src == 'C' || src == 'c') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    //起始柱输入错误处理完毕

    while (1) {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> dst;
        if (cin.good() && dst != src && (dst == 'A' || dst == 'a' || dst == 'B' || dst == 'b' || dst == 'C' || dst == 'c')) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }//输入正确且与src不同
        else if (cin.good() && dst == src && (dst == 'A' || dst == 'a' || dst == 'B' || dst == 'b' || dst == 'C' || dst == 'c')) {
            cout << "目标柱(" << src << ")不能与起始柱(" << src << ")相同" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }//输入正确但与src相同
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

    cout << "移动步骤为:" << endl;
    hanoi(n, src, tmp, dst);

    cout << endl;





}

