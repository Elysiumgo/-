/*2452545 ����� ������*/
#include<iostream>
#include<ctime>
using namespace std;


static const char other[] = "!@#$%^*&-_=+,.?";


void generatePassword(char password[], int length, int upper, int lower, int digit, int other_char) {
    
    int pos = 0;

    // ��д��ĸ
    for (int i = 0; i < upper; i++) {
        password[pos++] = 'A' + rand() % 26;
    }

    // Сд��ĸ
    for (int i = 0; i < lower; i++) {
        password[pos++] = 'a' + rand() % 26;
    }

    // ����
    for (int i = 0; i < digit; i++) {
        password[pos++] = '0' + rand() % 10;
    }

    // ��������
    for (int i = 0; i < other_char; i++) {
        password[pos++] = other[rand() % (sizeof(other) - 1)];
    }

    // ʣ�ಿ��������
    while (pos < length) {
        int choice = rand() % 4;  // 0:��д, 1:Сд, 2:����, 3:��������
        switch (choice) {
        case 0: password[pos++] = 'A' + rand() % 26; break;
        case 1: password[pos++] = 'a' + rand() % 26; break;
        case 2: password[pos++] = '0' + rand() % 10; break;
        case 3: password[pos++] = other[rand() % (sizeof(other) - 1)]; break;
        }
    }

    // Fisher-Yates ϴ���㷨
    for (int i = length - 1; i > 0; i--) {
        int j = (i * 127 + (int)time(0)) % (i + 1);  

        // ���� 
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    password[length] = '\0';  // �ַ�����β
}














int main()
{
    srand(static_cast<unsigned int>(time(0))); // ��ʼ���������

    int length, upper, lower, digit, other_char;
    cout << "���������볤�ȣ�12-16������д��ĸ����(��2)��Сд��ĸ����(��2)�����ָ���(��2)���������Ÿ���(��2)"<<endl;
    cin >> length >> upper >> lower >> digit >> other_char;

    if (cin.fail() || length < 12 || length>16 || upper < 2 || lower < 2 || digit < 2 || other_char < 2||(length<upper+lower+digit+other_char)) {
        cout << "����Ƿ�" << endl;
        return 0;
    }
    




    // ����������
    cout << length << " " << upper << " " << lower << " " << digit << " " << other_char << endl;


    for (int i = 0; i < 10; i++) {
        char password[17];  // ���16�ַ� + '\0'
        generatePassword(password, length, upper, lower, digit, other_char);
        std::cout << password <<endl;
    }

    return 0;
}

