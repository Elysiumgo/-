/*2452545 ����� ������*/
#include <iostream>
using namespace std;


static const char others[] = "!@#$%^*&-_=+,.?";

// ��������Ƿ����Ҫ��
bool checkPassword(const char pwd[], int len, int upper, int lower, int digit, int other) {
    int u = 0, l = 0, d = 0, o = 0;

    // ͳ�Ƹ����ַ�����
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

    // ����Ƿ��������Ҫ�����ܺ͵����ܳ���
    return (u >= upper && l >= lower && d >= digit && o >= other && (u + l + d + o) == len && len >= 12 && len<=16 && upper >= 2 && lower >= 2 && digit >= 2 && other >= 2);
}

int main() {
    char line[100];  // ���ڶ�ȡÿ������
    int len, upper, lower, digit, other;

    cin.getline(line, sizeof(line));

    // ��ȡ5������
   cin >> len >> upper >> lower >> digit >> other;
   cin.getline(line, sizeof(line));  // ��ȡʣ�ಿ�֣�����У�

    // ���10������
    bool allCorrect = true;
    for (int i = 0; i < 10; i++) {
        char password[17];  // ���16�ַ� + '\0'
        cin.getline(password, sizeof(password));

        if (!checkPassword(password, len, upper, lower, digit, other)) {
            allCorrect = false;
        }
    }

    // ������
   cout << (allCorrect ? "��ȷ" : "����") << endl;
    return 0;
}