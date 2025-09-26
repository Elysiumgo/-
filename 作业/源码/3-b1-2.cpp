/*2452545 计算机 刘晴语*/
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
    double r, h;
    const double pi = 3.14159;
    cout << "请输入半径和高度" << endl;
    cin >> r >> h;
    cout << fixed;
    cout << setiosflags(ios::left) << setw(10) << "圆周长" <<" : " <<  setprecision(2)<<2 * pi * r * r << endl;
    cout << setiosflags(ios::left) << setw(10) << "圆面积" << " : " << setprecision(2) << pi * r * r << endl;
    cout << setiosflags(ios::left) << setw(10) << "圆球表面积" << " : " << setprecision(2) << 4 * pi * r * r << endl;
    cout << setiosflags(ios::left) << setw(10) << "圆球体积" << " : " << setprecision(2) << 4 * pi * r * r * r/3 << endl;
    cout << setiosflags(ios::left) << setw(10) << "圆柱体积" << " : " << setprecision(2) << pi * r * r * h << endl;
    
    return 0;
}
