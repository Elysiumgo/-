/*2452545 计算机 刘晴语*/
#include <iostream>
#include <iomanip>
#include<math.h>
using namespace std;
int main()
{
    int i;
    double sum = 1, ex = 1,x;
    while (true) {
        cout << "请输入x的值[-10 ~ +65]" << endl;
        cin >> x;
        if (x >= -10 && x <= 65)
            break;
        else {
            cin.clear();
            cout << "输入非法，请重新输入" << endl;
        }
    }
    

    for (i = 1;;i++) {
        ex *=x/i;
        if (fabs(ex) < 1e-6)
            break;
        sum += ex;
    }
    
    
    cout << "e^" << x << "=" << setprecision(10) << sum << endl;

    return 0;
}