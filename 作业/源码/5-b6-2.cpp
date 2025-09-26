/* 2452545 计算机 刘晴语 */
#include <iostream>
#include <iomanip>
#include<limits>
using namespace std;



int pole_count[3] = { 0 };       // 记录每根柱子的圆盘数（0A,1B,2C）
int pole_disks[3][10];  // 记录圆盘编号
int step = 0;



void printStatus()
{
    if (step == 0) {
        cout << "初始:" << setw(17);
    }



    int p,i;
    for (p = 0; p < 3; p++) {
        cout << char('A' + p) << ": ";
        for (i = 0; i < 10; i++) {
            if (i < pole_count[p])
                cout << pole_disks[p][i] << " ";
            else
                cout << "  ";
        }
    }
    cout << endl;
   
}







void move(char from, char to) {
    int from_pole = from - 'A';
    int to_pole = to - 'A';

    // 移动圆盘
    int disk = pole_disks[from_pole][pole_count[from_pole] - 1];
    pole_count[from_pole]--;
    pole_disks[to_pole][pole_count[to_pole]] = disk;
    pole_count[to_pole]++;

   
    if (step > 0) {
        cout << "第 " << setw(3) << step << " 步(" << setw(2) << disk << "): "
            << from << "-->" << to << " ";
        printStatus();
    }

}











void hanoi(int n, char src, char tmp, char dst) {
    if (n == 1) {
        step++;
        move(src, dst);
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        step++;
        move(src, dst);
        hanoi(n - 1, tmp, src, dst);
    }
}


    int main()
    {
        int n;
        char src, dst, tmp = 'A';
        while (1) {
            cout << "请输入汉诺塔的层数(1-10)" << endl;
            cin >> n;
            if (cin.good() && n >= 1 && n <= 10) {
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



        int src_pole = src - 'A';
        for (int i = n; i >= 1; i--) {
            pole_disks[src_pole][pole_count[src_pole]++] = i;
        }

        printStatus();
        hanoi(n, src, tmp, dst);
        return 0;


        
       
       



    }
