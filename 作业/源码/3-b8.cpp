/*2452545 ����� ������*/
#include <iostream>
#include <iomanip>
#include<math.h>
using namespace std;
int main()
{
    int i;
    double sum = 1, ex = 1,x;
    while (true) {
        cout << "������x��ֵ[-10 ~ +65]" << endl;
        cin >> x;
        if (x >= -10 && x <= 65)
            break;
        else {
            cin.clear();
            cout << "����Ƿ�������������" << endl;
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