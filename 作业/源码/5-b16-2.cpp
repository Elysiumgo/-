/*2452545 计算机 刘晴语*/
#include <iostream>
#include <string>
using namespace std;

#define N 10

int main() {
    string ids[N], names[N];
    int scores[N] = { 0 }, order[N] = { 0 };

    // 输入数据
    for (int i = 0; i < N; i++) {
       cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩: "<<endl;
       cin >> ids[i] >> names[i] >> scores[i];
        order[i] = i;
    }

    // 冒泡排序
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (scores[j] > scores[j + 1] ||(scores[j] == scores[j + 1] && order[j] > order[j + 1])) {
                // 手动交换数据
                string temp_id = ids[j];
                string temp_name = names[j];
                int temp_score = scores[j];
                int temp_order = order[j];

                ids[j] = ids[j + 1];
                names[j] = names[j + 1];
                scores[j] = scores[j + 1];
                order[j] = order[j + 1];

                ids[j + 1] = temp_id;
                names[j + 1] = temp_name;
                scores[j + 1] = temp_score;
                order[j + 1] = temp_order;
            }
        }
    }

    // 输出不及格名单
    cout <<endl<<"不及格名单(成绩升序):"<<endl;
    for (int i = 0; i < N; i++) {
        if (scores[i] < 60) {
            cout << ids[i] << " " << names[i] << " " << scores[i] << endl;
        }
    }

    return 0;
}