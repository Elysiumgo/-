/*2452545 计算机 刘晴语*/
#include<iostream>
#include <limits>
using namespace std;

int main()
{
	int digit[9][9] = { 0 };
	int sum = 0;
	int i;
	int j;
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	for (i = 0;i < 9;i++) {
		for (j = 0;j < 9;j++) {
			while (1) {
				cin >> digit[i][j];
				if (cin.fail() || digit[i][j] < 1 || digit[i][j] > 9) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列的值: " << endl;
				}
				else
					break;

			}
		}
	}
	//输入错误处理结束

	bool shudu = 1;
	int check[10] = { 0 };//检查重复
	for (i = 0; i < 9 && shudu; i++) {
		for (j = 0; j < 9; j++) {
			check[digit[i][j]] += 1;       // 计数器+1
			if (check[digit[i][j]] > 1) {  // 检查是否重复
				shudu = false;
				break;
			}
		}
		//横行
	}
	for (int k = 1; k <= 9; k++)
		check[k] = 0;// 清空

		for (j = 0; j < 9 && shudu; j++) {
			for (i = 0; i < 9; i++) {
				check[digit[i][j]] += 1;       // 计数器+1
				if (check[digit[i][j]] > 1) {  // 检查是否重复
					shudu = false;
					break;
				}
			}
		}

		//竖行


	
	for (int row = 0; row < 9 && shudu; row += 3) {
		for (int column = 0; column < 9 && shudu; column += 3) {
			for (int k = 1; k <= 9; k++)
				check[k] = 0; //清空

			// 检查九宫格
			for (i = row; i < row + 3 && shudu; i++) {
				for (j = column; j < column + 3 && shudu; j++) {
					check[digit[i][j]]++;
					if (check[digit[i][j]] > 1) {
						shudu = false;
						break;
					}
				}
			}
		}
	}







	cout << (shudu ? "是" : "不是") << "数独的解" << endl;
	
	return 0;
}
