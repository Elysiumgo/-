/*2452545 计算机 刘晴语*/
#include <iostream>
using namespace std;
int main()
{
    int k;
    cout << "请输入一个[1..30000]间的整数:" << endl;
    cin >> k;
    cout << "万位 : " << (k / 10000) % 10 << endl;
    cout << "千位 : " << (k / 1000) % 10 << endl;
    cout << "百位 : " << (k / 100) % 10 << endl;
    cout << "十位 : " << (k / 10) % 10 << endl;
    cout << "个位 : " << (k / 1) % 10 << endl;
    return 0;
}
