/*2452545 计算机 刘晴语*/
#include <iostream>
using namespace std;


static const char others[] = "!@#$%^*&-_=+,.?";

// 检查密码是否符合要求
bool checkPassword(const char pwd[], int len, int upper, int lower, int digit, int other) {
    int u = 0, l = 0, d = 0, o = 0;

    // 统计各类字符数量
    for (int i = 0; i < len; i++) {
        char c = pwd[i];
        if (c >= 'A' && c <= 'Z') 
            u++;
        else if (c >= 'a' && c <= 'z') 
            l++;
        else if (c >= '0' && c <= '9') 
            d++;
        else {
            for (int j = 0;j < 16;j++)
                if (c == others[j])
                {
                    o++;
                    break;
                }

        }
    }

    // 检查是否满足最低要求且总和等于总长度
    return (u >= upper && l >= lower && d >= digit && o >= other && (u + l + d + o) == len && len >= 12 && len<=16 && upper >= 2 && lower >= 2 && digit >= 2 && other >= 2);
}

int main() {
    char line[100];  // 用于读取每行输入
    int len, upper, lower, digit, other;

    cin.getline(line, sizeof(line));

    // 读取5个整数
   cin >> len >> upper >> lower >> digit >> other;
   cin.getline(line, sizeof(line));  // 读取剩余部分（如果有）

    // 检查10组密码
    bool allCorrect = true;
    for (int i = 0; i < 10; i++) {
        char password[17];  // 最大16字符 + '\0'
        cin.getline(password, sizeof(password));

        if (!checkPassword(password, len, upper, lower, digit, other)) {
            allCorrect = false;
        }
    }

    // 输出结果
   cout << (allCorrect ? "正确" : "错误") << endl;
    return 0;
}