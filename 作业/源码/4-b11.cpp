/* 2452545 计算机 刘晴语 */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：1、按需增加一个或多个函数（包括递归函数），但是所有增加的函数中不允许任何形式的循环
				 2、定义符号常量
				 3、定义const型变量

		不允许 ：1、定义全局变量
				 2、除print_tower之外的其他函数中不允许定义静态局部变量
   ----------------------------------------------------------------------------------- */
void line1(char end_ch) {
	if (end_ch == 'A')
		cout << 'A';
	else {
		cout<< end_ch;
		line1(char(end_ch - 1));
	}
}


void line2(char end_ch) {
	if (end_ch == 'A')
		return;
	else {
		line2(char(end_ch - 1));
		cout << char(end_ch);
	}
}


void kongge(char end_ch) {
	if (end_ch == 'A')
		return;
	else {
		cout << setfill(' ') << setw(2 * (int(end_ch) - 'A') + 1) << ' ';
	}
}







   /***************************************************************************
	 函数名称：
	 功    能：打印字母塔
	 输入参数：
	 返 回 值：
	 说    明：形参按需设置
			   提示：有一个参数order，指定正序/倒序
   ***************************************************************************/
void print_tower(char end_ch,int order)
{
	static int width = (end_ch - 'A') + 1;
	

	/* 允许按需定义最多一个静态局部变量（也可以不定义） */
	if (order == 1) {
		if (end_ch == 'A') {
			cout << setfill(' ') << setw(width);
			cout <<  'A' << endl;
			return;
		}
			
		else {
			print_tower(char(end_ch-1), 1);
			width -= 1;
			cout << setfill(' ') << setw(width) ;
			line1(char(end_ch));
			line2(char(end_ch));
			cout << endl;
		}
	}

	if (order == 2) {
		if (end_ch == 'A') {
			cout << setfill(' ') << setw(width);
			cout << 'A' << endl;
			return;
		}
		else {
			cout << setfill(' ')<< setw(width) ;
			width += 1;
			line1(char(end_ch));
			line2(char(end_ch));
			cout << endl;
			print_tower(char(end_ch) - 1, 2);
		}

	}
	if (order == 3) { //菱形下半部分，少一个字母，单独处理输入A的情况

		if (end_ch == '@') {
			return;
		}
		else if (end_ch == 'A') {
			cout << setfill(' ') << setw(width+1);
			cout << 'A' << endl;
			return;
		}
		else {
			cout << setfill(' ') << setw(width+1);
			width += 1;
			line1(char(end_ch));
			line2(char(end_ch));
			cout << endl;
			print_tower(char(end_ch) - 1, 3);
		}

	}

	

}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中的...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效，为避免循环出现，不处理输入错误) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();			//读缓冲区第一个字符
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "结束字符不是大写字母" << endl;
		return -1;
	}

	/* 正三角字母塔(中间为A) */ 
	cout << setfill('=')<< setw(2 * int(end_ch) - 2 * 'A' + 1) <<'=' << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "正三角字母塔(" << end_ch << "->A)" << endl;
	cout << setfill('=')<< setw(2 * end_ch - 2 * 'A' +1) << '=' << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(end_ch,1); //正序打印 A~结束字符 
	cout << endl;

	/* 倒三角字母塔(中间为A) */
	cout << setfill('=') <<setw(2 * int(end_ch) - 2 * 'A' + 1) << '=' <<  endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "倒三角字母塔(" << end_ch << "->A)" << endl;
	cout << setfill('=') <<setw(2 * int(end_ch) - 2 * 'A' + 1) << '=' <<  endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(end_ch, 2); //逆序打印 A~结束字符 
	cout << endl;

	/* 合起来就是漂亮的菱形（中间为A） */
	cout << setfill('=') <<setw(2 * end_ch - 2 * 'A' + 1) << '='<< endl;/* 按字母塔最大宽度输出= */
	cout << "菱形(" << end_ch << "->A)" << endl;
	cout << setfill('=') <<setw(2 * end_ch - 2 * 'A'  +1) <<'='<<  endl;/* 按字母塔最大宽度输出= */
	print_tower(end_ch, 1);   //打印 A~结束字符的正三角 
	print_tower(end_ch-1, 3);   //打印 A~结束字符-1的倒三角 
	cout << endl;

	return 0;
}
