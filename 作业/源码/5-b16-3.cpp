/*2452545 ����� ������*/
#include <iostream>
#include <string>
using namespace std;
const int N = 10;

int main() {
    std::string ids[N], names[N];
    int scores[N];

    // ��������
    for (int i = 0; i < N; i++) {
       cout << "�������" << i + 1 << "���˵�ѧ�š��������ɼ�: "<<endl;
       cin >> ids[i] >> names[i] >> scores[i];
    }

    // ѡ������ѧ������
    for (int i = 0; i < N - 1; i++) {
        int min = i;
        for (int j = i + 1; j < N; j++) {
            if (ids[j] < ids[min]) {  // ֱ�ӱȽ� string
                min = j;
            }
        }
        if (min != i) {
            // �ֶ����� ids
            string temp_id = ids[i];
            ids[i] = ids[min];
            ids[min] = temp_id;

            // �ֶ����� names
            string temp_name = names[i];
            names[i] = names[min];
            names[min] = temp_name;

            // �ֶ����� scores
            int temp_score = scores[i];
            scores[i] = scores[min];
            scores[min] = temp_score;
        }
    }

    // ���ȫ��ѧ����ѧ������
    cout << endl;
    cout << "ȫ��ѧ��(ѧ������):"<<endl;
    for (int i = 0; i < N; i++) {
       cout << ids[i] << " " << names[i] << " " << scores[i] << endl;
    }

    return 0;
}