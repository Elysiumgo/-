/*2452545 计算机 刘晴语*/
#include<iostream>
#include<ctime>
using namespace std;


static const char other[] = "!@#$%^*&-_=+,.?";


void generatePassword(char password[], int length, int upper, int lower, int digit, int other_char) {
    
    int pos = 0;

    // 大写字母
    for (int i = 0; i < upper; i++) {
        password[pos++] = 'A' + rand() % 26;
    }

    // 小写字母
    for (int i = 0; i < lower; i++) {
        password[pos++] = 'a' + rand() % 26;
    }

    // 数字
    for (int i = 0; i < digit; i++) {
        password[pos++] = '0' + rand() % 10;
    }

    // 其他符号
    for (int i = 0; i < other_char; i++) {
        password[pos++] = other[rand() % (sizeof(other) - 1)];
    }

    // 剩余部分随机填充
    while (pos < length) {
        int choice = rand() % 4;  // 0:大写, 1:小写, 2:数字, 3:其他符号
        switch (choice) {
        case 0: password[pos++] = 'A' + rand() % 26; break;
        case 1: password[pos++] = 'a' + rand() % 26; break;
        case 2: password[pos++] = '0' + rand() % 10; break;
        case 3: password[pos++] = other[rand() % (sizeof(other) - 1)]; break;
        }
    }

    // Fisher-Yates 洗牌算法
    for (int i = length - 1; i > 0; i--) {
        int j = (i * 127 + (int)time(0)) % (i + 1);  

        // 交换 
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    password[length] = '\0';  // 字符串结尾
}














int main()
{
    srand(static_cast<unsigned int>(time(0))); // 初始化随机种子

    int length, upper, lower, digit, other_char;
    cout << "请输入密码长度（12-16），大写字母个数(≥2)，小写字母个数(≥2)，数字个数(≥2)，其它符号个数(≥2)"<<endl;
    cin >> length >> upper >> lower >> digit >> other_char;

    if (cin.fail() || length < 12 || length>16 || upper < 2 || lower < 2 || digit < 2 || other_char < 2||(length<upper+lower+digit+other_char)) {
        cout << "输入非法" << endl;
        return 0;
    }
    




    // 输出输入参数
    cout << length << " " << upper << " " << lower << " " << digit << " " << other_char << endl;


    for (int i = 0; i < 10; i++) {
        char password[17];  // 最大16字符 + '\0'
        generatePassword(password, length, upper, lower, digit, other_char);
        std::cout << password <<endl;
    }

    return 0;
}

