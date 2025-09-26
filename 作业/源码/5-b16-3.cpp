/*2452545 计算机 刘晴语*/
#include <iostream>
#include <string>
using namespace std;
const int N = 10;

int main() {
    std::string ids[N], names[N];
    int scores[N];

    // 输入数据
    for (int i = 0; i < N; i++) {
       cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩: "<<endl;
       cin >> ids[i] >> names[i] >> scores[i];
    }

    // 选择排序（学号升序）
    for (int i = 0; i < N - 1; i++) {
        int min = i;
        for (int j = i + 1; j < N; j++) {
            if (ids[j] < ids[min]) {  // 直接比较 string
                min = j;
            }
        }
        if (min != i) {
            // 手动交换 ids
            string temp_id = ids[i];
            ids[i] = ids[min];
            ids[min] = temp_id;

            // 手动交换 names
            string temp_name = names[i];
            names[i] = names[min];
            names[min] = temp_name;

            // 手动交换 scores
            int temp_score = scores[i];
            scores[i] = scores[min];
            scores[min] = temp_score;
        }
    }

    // 输出全部学生（学号升序）
    cout << endl;
    cout << "全部学生(学号升序):"<<endl;
    for (int i = 0; i < N; i++) {
       cout << ids[i] << " " << names[i] << " " << scores[i] << endl;
    }

    return 0;
}