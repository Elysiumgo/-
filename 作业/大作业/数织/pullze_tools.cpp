/* 2452545 计算机 刘晴语 */
#include<iostream>
#include<conio.h>
#include "cmd_console_tools.h"
#include "pullze.h"
using namespace std;

//工具函数，如菜单，判断提交是否成功


//菜单
char menu()
{

	cct_cls();
	cct_setcolor();
	cct_setfontsize("新宋体",15);
	cct_setconsoleborder(120, 80);


	while (1) {
		cout << "---------------------------------------------------------" << endl
			<< "A.内部数组，原样输出" << endl
			<< "B.内部数组，生成提示行列并输出" << endl
			<< "C.内部数组，游戏版" << endl
			<< "--------------------------------------------------------" << endl
			<< "D.n * n的框架(无分隔线)，原样输出" << endl
			<< "E.n * n的框架(无分隔线)，含提示行列" << endl
			<< "F.n * n的框架(无分隔线)，显示初始状态，鼠标移动可显示坐标" << endl
			<< "G.cmd图形界面完整版(无分隔线)" << endl
			<< "--------------------------------------------------------" << endl
			<< "H.n * n的框架(有分隔线)，原样输出" << endl
			<< "I.n * n的框架(有分隔线)，含提示行列" << endl
			<< "J.n * n的框架(有分隔线)，显示初始状态，鼠标移动可显示坐标" << endl
			<< "K.cmd图形界面完整版(有分隔线)" << endl
			<< "--------------------------------------------------------" << endl
			<< "Q.退出" << endl
			<< "--------------------------------------------------------" << endl
			<< "[请选择:]";

		char k = toupper(_getch());
		if (k >= 'A' && k <= 'K' || k == 'Q')
			return k;

	}

	return 0;



}


//退出
void my_exit()
{
	cct_setcolor();
	cout << endl;
	cout << "\n\n\n\n本小题结束，请输入End继续...";
	while (1) {
		char E, N, D;
		cin >> E >> N >> D;
		E = toupper(E);
		N = toupper(N);
		D = toupper(D);
		if (E == 'E' && N == 'N' && D == 'D')
			break;
		cout << "输入错误，请重新输入" << endl;
	}

}












