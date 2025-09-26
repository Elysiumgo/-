/* 2452545 计算机 刘晴语*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //取系统时间
using namespace std;

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */


        int a = 123, b = 0, c = 0, i = 0; //设a<b<c
        for (a = 123;a <= 651;a++) {
            for (b = a; b <= (1953 - a) / 2;b++) {
                c = 1953 - a - b;
                if (c <= 1000) {
                    int a1 = a / 100, a2 = a / 10 % 10, a3 = a % 10;
                    int b1 = b / 100, b2 = b / 10 % 10, b3 = b % 10;
                    int c1 = c / 100, c2 = c / 10 % 10, c3 = c % 10;

                    // 检查数字是否在1-9且不重复
                    if (a1 != 0 && a2 != 0 && a3 != 0 &&
                        b1 != 0 && b2 != 0 && b3 != 0 &&
                        c1 != 0 && c2 != 0 && c3 != 0 &&
                        a1 != a2 && a1 != a3 && a2 != a3 &&
                        b1 != b2 && b1 != b3 && b2 != b3 &&
                        c1 != c2 && c1 != c3 && c2 != c3 &&
                        a1 != b1 && a1 != b2 && a1 != b3 &&
                        a2 != b1 && a2 != b2 && a2 != b3 &&
                        a3 != b1 && a3 != b2 && a3 != b3 &&
                        a1 != c1 && a1 != c2 && a1 != c3 &&
                        a2 != c1 && a2 != c2 && a2 != c3 &&
                        a3 != c1 && a3 != c2 && a3 != c3 &&
                        b1 != c1 && b1 != c2 && b1 != c3 &&
                        b2 != c1 && b2 != c2 && b2 != c3 &&
                        b3 != c1 && b3 != c2 && b3 != c3) {
                        i++;
                        cout << "No." << setw(3) << i << " : " << a << '+' << b << '+' << c << '=' << "1953" << endl;

                    }
                }
            }
        }
        cout << "total=" << i << endl;


	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;
	cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;

	return 0;
}
