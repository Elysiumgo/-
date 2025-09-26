/*刘晴语 2452545 计算机*/
#include <iostream>
using namespace std;

int main()
{
	cout << "请输入成绩（最多1000个），负数结束输入" << endl;
	int score[1000];
	int i, count = 0;
	for (i = 0;i < 1000;i++) {
		cin >> score[i];
		count++;
		if (count == 1 && score[i] < 0) {
			cout << "无有效输入" << endl;
			return 0;
		}
		else if (score[i] < 0)
			break;
	}
	//输入结束
	cout << "输入的数组为:" << endl;
	for (i = 0;i < count - 1;i++) {
		cout << score[i] << ' ';
		if ((i + 1) >= 10 && (i + 1) % 10 == 0)
			cout << endl;

	}
	if (i < 10)
		cout << endl;

	

	//开始排序
	int j, t;
	for (i = 0;i < count - 1;i++) {

		for (j = 0;j < count - (i + 1);j++) {
			if (score[j] < score[j + 1]) {
				t = score[j];
				score[j] = score[j + 1];
				score[j + 1] = t;
			}
		}
	}


	//输出
	cout << "分数与名次的对应关系为:" << endl;
	int rank = 1;
	for (i = 0;i < count - 1;i++) {
		cout << score[i] << ' ' << rank << endl;
		if (i < count - 2 &&score[i] != score[i + 1])
			rank = i + 2;
	}



	return 0;

}