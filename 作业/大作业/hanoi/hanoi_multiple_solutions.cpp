/* 2452545 计算机 刘晴语 */
#include"hanoi.h"
#include"cmd_hdc_tools.h"
#include"cmd_console_tools.h"
#include <iostream>
#include<iomanip>
#include <cstdio>
#include<conio.h>
#include<limits>


using namespace std;
/* ----------------------------------------------------------------------------------

	 本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

	 本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */



int pole_count[3] = { 0 };       // 记录每根柱子的圆盘数（0A,1B,2C）
int pole_disks[3][10];  // 记录圆盘编号
int step = 0;

void get_hanoi_input(int* n, char* src, char* dst, int* speed, int mode)
{
	// 输入层数
	while (true) {
		cout << "请输入汉诺塔的层数(1-10)" << endl;
		cin >> *n;
		if (cin.good() && *n >= 1 && *n <= 10) {
			std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			break;
		}
		else {
			cin.clear();
			std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
		}
	}

	// 输入起始柱
	while (true) {
		cout << "请输入起始柱(A-C)" << endl;
		cin >> *src;
		if (cin.good() && (*src == 'A' || *src == 'a' || *src == 'B' || *src == 'b' || *src == 'C' || *src == 'c')) {
			std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			break;
		}
		else {
			cin.clear();
			std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
		}
	}

	// 转换为大写
	if (*src >= 'a' && *src <= 'c') {
		*src -= 32;
	}

	// 输入目标柱
	while (1) {
		cout << "请输入目标柱(A-C)" << endl;
		cin >> *dst;
		if (cin.good() && *dst != *src && (*dst == 'A' || *dst == 'a' || *dst == 'B' || *dst == 'b' || *dst == 'C' || *dst == 'c')) {
			std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			break;
		}
		else if (cin.good() && *dst == *src) {
			cout << "目标柱(" << *src << ")不能与起始柱(" << *src << ")相同" << endl;
			std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
		}
		else {
			cin.clear();
			std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
		}
	}

	// 转换为大写
	if (*dst >= 'a' && *dst <= 'c') {
		*dst -= 32;
	}

	// 输入速度
	if (mode == 4 || mode == 5 || mode == 6 || mode == 7 || mode == 8 || mode == 9) {
		while (true) {
			cout << "请输入移动速度(0-20：0-按回车单步演示 1-20:延时1-20ms)" << endl;
			cin >> *speed;
			if (cin.good() && *speed >= 0 && *speed <= 20) {
				std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
				break;
			}
			else {
				cin.clear();
				std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			}
		}
	}
}


void my_exit()
{

	cout << "按回车键继续" << endl;
	char k = _getch();
	while (k != '\n' && k != '\r')
		;
}

// 柱子中心X坐标
int get_peg_center(char peg) {
	int x = HDC_Start_X + 23 * HDC_Base_Width / 2;
	if (peg == 'B') x += 23 * HDC_Base_Width + HDC_Underpan_Distance;
	else if (peg == 'C') x += 2 * (23 * HDC_Base_Width + HDC_Underpan_Distance);
	return x;
}


//设定盘子画笔颜色
void disk_color(int n)
{
	if (n == 1)
		hdc_set_pencolor(0, 55, 218);
	else if (n == 2)
		hdc_set_pencolor(19, 161, 14);
	else if (n == 3)
		hdc_set_pencolor(58, 150, 221);
	else if (n == 4)
		hdc_set_pencolor(197, 15, 31);
	else if (n == 5)
		hdc_set_pencolor(136, 23, 152);
	else if (n == 6)
		hdc_set_pencolor(193, 156, 0);
	else if (n == 7)
		hdc_set_pencolor(204, 204, 204);
	else if (n == 8)
		hdc_set_pencolor(118, 118, 118);
	else if (n == 9)
		hdc_set_pencolor(59, 120, 255);
	else if (n == 10)
		hdc_set_pencolor(22, 198, 12);

}

//内部数组显示(横向+纵向)
void show_status(char from = 0, char to = 0, int disk = 0, int speed = 10, int mode = 3) {
	const int X = 10, Y = 29;

	if (step == 0) {
		cct_gotoxy(0, 41);
		cout << left << setw(17) << "初始 : ";
	}
	// 显示步骤信息
	if (step > 0) {
		// 处理暂停和光标位置
		if (mode == 7 || mode == 8 || mode == 9) {
			Sleep(speed);
			cct_gotoxy(0, 41);
		}
		else if (mode == 4) {
			if (speed != 0) {
				Sleep(speed);
				cct_gotoxy(0, 41);
			}
			else {
				cct_gotoxy(0, 41);
				while (_getch() != 13)
					;
			}
		}

		cout << "第 " << setw(3) << step << " 步(" << setw(2) << disk << "): "
			<< from << "-->" << to << " ";
	}

	// 横向显示
	if (mode == 7 || mode == 8 || mode == 4 || mode == 9) {
		cct_gotoxy(30, 41);
	}
	for (int peg = 0; peg < 3; peg++) {
		cout << char('A' + peg) << " : ";
		for (int level = 0; level <= 9; level++) {
			if (pole_disks[peg][level] != 0)
				cout << pole_disks[peg][level] << " ";
			else
				cout << "  ";
		}
	}
	cout << endl;

	// 纵向显示
	if (mode != 3)
	{
		for (int i = 0; i < 10; i++) {
			cct_gotoxy(X, Y - i);
			if (pole_disks[0][i] != 0)
				cout << pole_disks[0][i];
			else
				cout << "  ";

			cct_gotoxy(X + 10, Y - i);

			if (pole_disks[1][i] != 0)
				cout << pole_disks[1][i];
			else
				cout << "  ";

			cct_gotoxy(X + 20, Y - i);
			if (pole_disks[2][i] != 0)
				cout << pole_disks[2][i];
			else
				cout << "  ";
		}
	}
	if (step == 0)
		Sleep(HDC_Init_Delay);
}

void move_disk_with_status(char from, char to, int speed, int mode) {

	int from_idx = from - 'A';
	int to_idx = to - 'A';
	int disk = pole_disks[from_idx][pole_count[from_idx] - 1];

	// 1. 显示移动提示（盘子还在原位）
	if (mode == 7 || mode == 8 || mode == 9) {
		Sleep(HDC_Init_Delay);
	}

	// 2. 从src移除盘子
	pole_disks[from_idx][--pole_count[from_idx]] = 0;


	// 3. 盘子已在目标位置
	
	pole_disks[to_idx][pole_count[to_idx]] = disk;
	show_status(from, to, disk, speed, mode);

	if (mode == 7 || mode == 8 || mode == 9)
	{
		// 4. 动画
		int disk_size = disk;
		int from_x = get_peg_center(from);
		int to_x = get_peg_center(to);
		int width = (1 + 2 * disk_size) * HDC_Base_Width;

		// 上升
		int current_x = from_x - width / 2;
		int current_y = HDC_Start_Y - (pole_count[from_idx] + 1) * HDC_Base_High;
		while (current_y > HDC_Top_Y) {
			hdc_rectangle(current_x, current_y, width, HDC_Base_High, RGB(12, 12, 12));
			hdc_rectangle(from_x - HDC_Base_Width / 2, current_y, HDC_Base_Width, HDC_Base_High, RGB(249, 241, 165));
			current_y -= HDC_Step_Y;
			disk_color(disk_size);
			hdc_rectangle(current_x, current_y, width, HDC_Base_High, INVALID_RGB);

			// 控制步骤显示和暂停
			if (speed == 0 && (step != 0 || mode == 9)) {
				while (_getch() != 13)
					;
			}
			else if (step != 0) {
				if (step <= 7)
					Sleep(speed);
			}
		}

		// 水平移动
		while (current_x != to_x - width / 2) {
			hdc_rectangle(current_x, current_y, width, HDC_Base_High, RGB(12, 12, 12));
			if (current_x < to_x - width / 2) current_x += HDC_Step_X;
			else current_x -= HDC_Step_X;
			disk_color(disk_size);
			hdc_rectangle(current_x, current_y, width, HDC_Base_High, INVALID_RGB);

			// 控制步骤显示和暂停
			if (speed == 0 && (step != 0 || mode == 9)) {
				while (_getch() != 13)
					;
			}
			else if (step != 0) {
				if (step <= 7)
					Sleep(speed);
			}
		}

		// 下降
		int target_y = HDC_Start_Y - (pole_count[to_idx] + 1) * HDC_Base_High;
		while (current_y < target_y) {
			hdc_rectangle(current_x, current_y, width, HDC_Base_High, RGB(12, 12, 12));
			if (current_y > HDC_Top_Y + HDC_Base_High)
				hdc_rectangle(to_x - HDC_Base_Width / 2, current_y, HDC_Base_Width, HDC_Base_High, RGB(249, 241, 165));
			current_y += HDC_Step_Y;
			//盘子
			disk_color(disk_size);
			hdc_rectangle(current_x, current_y, width, HDC_Base_High, INVALID_RGB);
			if (speed == 0 && (step != 0 || mode == 9)) {
				while (_getch() != 13)
					;
			}
			else if (step != 0) {
				if (step <= 7)
					Sleep(speed);
			}
		}
	}

	// 5. 正式更新高度
	pole_disks[to_idx][pole_count[to_idx]++] = disk;
	

	// 6. 显示最终状态
	if (mode == 7 || mode == 8 || mode == 9) {
		show_status(from, to, disk, speed, mode);
	}
}

void output_final(int n, char src, char dst, int speed, int mode)
{
	if (mode == 8 || mode == 7)
		move_disk_with_status(src, dst, speed, mode);
	else if (mode == 2)
		cout << setw(5) << step << ": " << setw(2) << n << '#' << ' ' << src << "-->" << dst << endl;
	else if (mode == 1)
		cout << setw(2) << n << '#' << ' ' << src << "-->" << dst << endl;
	else if (mode == 3 || mode == 4)
		move_disk_with_status(src, dst, speed, mode);
}



void hanoi_final(int n, char src, char dst, char tmp, int speed, int mode)
{
	if (n == 1) {

		step++;
		output_final(n, src, dst, speed, mode);
	}

	else {
		hanoi_final(n - 1, src, tmp, dst, speed, mode);
		step++;

		output_final(n, src, dst, speed, mode);

		hanoi_final(n - 1, tmp, dst, src, speed, mode);
	}
}



//1. 基本解

void basic1()
{
	int n, speed;
	char src, dst;
	step = 0;


	get_hanoi_input(&n, &src, &dst, &speed, 1);

	char tmp = 198 - src - dst;
	hanoi_final(n, src, dst, tmp, speed, 1);

	my_exit();
}




//2. 基本解(步数记录)

void basic2_steps()
{
	step = 0;
	int n, speed;
	char src, dst;


	get_hanoi_input(&n, &src, &dst, &speed, 2);

	char tmp = 198 - src - dst;
	hanoi_final(n ,  src,dst, tmp, speed, 2);

	my_exit();
}




//3. 横向
void inside1()
{
	step = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 10; j++) {
			pole_disks[i][j] = 0;
		}
	}


	for (int i = 0; i < 3; i++) {
		pole_count[i] = 0;
	}


	// 清空

	int n, speed;
	char src, dst;


	get_hanoi_input(&n, &src, &dst, &speed, 3);

	char tmp = 198 - src - dst;
	int src_pole = src - 'A';
	for (int i = n; i >= 1; i--) {
		pole_disks[src_pole][pole_count[src_pole]++] = i;
	}



	hanoi_final(n, src, dst, tmp, speed, 3);

	my_exit();

}




//4. 内部数组显示(纵向+横向)

void inside2()
{
	int n, speed;
	char src, dst;

	get_hanoi_input(&n, &src, &dst, &speed, 4);

	// 初始化全局变量
	step = 0;
	for (int i = 0; i < 3; i++) {
		pole_count[i] = 0;
		for (int j = 0; j < 10; j++) {
			pole_disks[i][j] = 0;
		}
	}

	// 初始化源柱子
	int src_idx = src - 'A';
	for (int i = n; i >= 1; i--) {
		pole_disks[src_idx][pole_count[src_idx]++] = i;
	}

	cct_cls();
	cout << "从" << src << "移动到" << dst << "，共" << n << "层，" << "延时设置为" << speed << "ms";

	cct_gotoxy(8, 30);
	cout << "=========================" << endl;

	cout << "          A         B         C  ";

	cct_gotoxy(3, 25);
	cout << left << setw(21) << "初始:";
	show_status(src, dst, n, speed, 4);

	// 开始移动
	char tmp = 198 - src - dst;
	hanoi_final(n, src, dst, tmp, speed, 4);

	my_exit();
}





//5.图形解-预备-画三个圆柱
void column_only()
{
	hdc_init();
	hdc_set_pencolor(249, 241, 165);//柱子的黄色

	cct_gotoxy(0, 40);
	Sleep(HDC_Init_Delay);


	hdc_rectangle(HDC_Start_X - 6, HDC_Start_Y, 25 * HDC_Base_Width, HDC_Base_High, INVALID_RGB);
	Sleep(HDC_Init_Delay);
	hdc_rectangle(HDC_Start_X + HDC_Underpan_Distance + 23 * HDC_Base_Width, HDC_Start_Y, 23 * HDC_Base_Width, HDC_Base_High, INVALID_RGB);
	Sleep(HDC_Init_Delay);
	hdc_rectangle(HDC_Start_X + 2 * (HDC_Underpan_Distance + 23 * HDC_Base_Width), HDC_Start_Y, 23 * HDC_Base_Width, HDC_Base_High, INVALID_RGB);
	Sleep(HDC_Init_Delay);


	for (int i = 0; i < 3; i++) {
		int x = get_peg_center('A' + i);
		hdc_rectangle(x - HDC_Base_Width / 2, HDC_Base_High + 24,
			HDC_Base_Width, 230, INVALID_RGB);
		Sleep(HDC_Init_Delay);
	}


}




//6. 图形解-预备-在起始柱上画n个盘子
void disk_only()
{
	int n, speed;
	char src, dst;


	get_hanoi_input(&n, &src, &dst, &speed, '6');

	char tmp = 198 - src - dst;

	cct_cls();
	cct_gotoxy(0, 38);
	cout << "从" << src << "移动到" << dst << "，共" << n << "层" << endl;

	column_only();

	if (src == 'A') {
		for (int i = n;i > 0;i--) { //倒着画n个
			disk_color(i);
			hdc_rectangle(HDC_Start_X + 23 * HDC_Base_Width / 2 - (1 + 2 * i) * HDC_Base_Width / 2 + 1, HDC_Start_Y - (n - i + 1) * HDC_Base_High, (1 + 2 * i) * HDC_Base_Width, HDC_Base_High, INVALID_RGB);
			Sleep(HDC_Init_Delay);
		}
	}
	else if (src == 'B') {
		for (int i = n;i > 0;i--) { //倒着画n个
			disk_color(i);
			hdc_rectangle(HDC_Start_X + 23 * HDC_Base_Width / 2 + HDC_Underpan_Distance + 23 * HDC_Base_Width - (1 + 2 * i) * HDC_Base_Width / 2 + 1, HDC_Start_Y - (n - i + 1) * HDC_Base_High, (1 + 2 * i) * HDC_Base_Width, HDC_Base_High, INVALID_RGB);
			Sleep(HDC_Init_Delay);
		}
	}
	else if (src == 'C') {
		for (int i = n;i > 0;i--) { //倒着画n个
			disk_color(i);
			hdc_rectangle(HDC_Start_X + 23 * HDC_Base_Width / 2 + HDC_Underpan_Distance + 23 * HDC_Base_Width + HDC_Underpan_Distance + 23 * HDC_Base_Width - (1 + 2 * i) * HDC_Base_Width / 2 + 1, HDC_Start_Y - (n - i + 1) * HDC_Base_High, (1 + 2 * i) * HDC_Base_Width, HDC_Base_High, INVALID_RGB);
			Sleep(HDC_Init_Delay);
		}
	}


}




//8.图形解 - 自动移动版本

void hanoi_automove()
{
	step = 0;
	// 输入
	int n, speed;
	char src, dst;

	get_hanoi_input(&n, &src, &dst, &speed, 8);

	char tmp = 198 - src - dst; // ASCII码计算中间柱子 (A=65, B=66, C=67 -> 65+66+67=198)

	cct_cls();

	// 初始化
	int src_idx = src - 'A';
	pole_count[0] = pole_count[1] = pole_count[2] = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 10; j++) {
			pole_disks[i][j] = 0;
		}
	}

	// 根据源柱子初始化disk_stacks
	for (int i = 0; i < n; i++) {
		pole_disks[src_idx][i] = n - i; // 底部放最大的盘子
	}
	pole_count[src_idx] = n;

	column_only();
	if (src == 'A') {
		for (int i = n;i > 0;i--) { //倒着画n个
			disk_color(i);
			hdc_rectangle(HDC_Start_X + 23 * HDC_Base_Width / 2 - (1 + 2 * i) * HDC_Base_Width / 2 + 1, HDC_Start_Y - (n - i + 1) * HDC_Base_High, (1 + 2 * i) * HDC_Base_Width, HDC_Base_High, INVALID_RGB);
			Sleep(HDC_Init_Delay);
		}
	}
	else if (src == 'B') {
		for (int i = n;i > 0;i--) { //倒着画n个
			disk_color(i);
			hdc_rectangle(HDC_Start_X + 23 * HDC_Base_Width / 2 + HDC_Underpan_Distance + 23 * HDC_Base_Width - (1 + 2 * i) * HDC_Base_Width / 2 + 1, HDC_Start_Y - (n - i + 1) * HDC_Base_High, (1 + 2 * i) * HDC_Base_Width, HDC_Base_High, INVALID_RGB);
			Sleep(HDC_Init_Delay);
		}
	}
	else if (src == 'C') {
		for (int i = n;i > 0;i--) { //倒着画n个
			disk_color(i);
			hdc_rectangle(HDC_Start_X + 23 * HDC_Base_Width / 2 + HDC_Underpan_Distance + 23 * HDC_Base_Width + HDC_Underpan_Distance + 23 * HDC_Base_Width - (1 + 2 * i) * HDC_Base_Width / 2 + 1, HDC_Start_Y - (n - i + 1) * HDC_Base_High, (1 + 2 * i) * HDC_Base_Width, HDC_Base_High, INVALID_RGB);
			Sleep(HDC_Init_Delay);
		}
	}
	// 显示初始状态
	show_status(src, dst, n, speed, 8);

	cct_gotoxy(0, 39);
	cout << "从" << src << "移动到" << dst << "，共" << n << "层，" << "延时设置为" << speed << "ms" << "（前7步，后面自动变为0ms）";

	cct_gotoxy(8, 30);
	cout << "=========================" << endl;
	cout << "          A         B         C  ";

	






	// 开始移动
	hanoi_final(n, src, dst, tmp, speed, 8);
}



//7.一步
void hanoi_firststep()
{
	step = 0;
	int n, speed;
	char src, dst;


	get_hanoi_input(&n, &src, &dst, &speed, 7);

	char tmp = 198 - src - dst;


	cct_cls();


	// 初始化
	int src_idx = src - 'A';
	pole_count[0] = pole_count[1] = pole_count[2] = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 10; j++) {
			pole_disks[i][j] = 0;
		}
	}

	// 根据源柱子初始化disk_stacks
	for (int i = 0; i < n; i++) {
		pole_disks[src_idx][i] = n - i;
	}
	pole_count[src_idx] = n;

	column_only();

	if (src == 'A') {
		for (int i = n;i > 0;i--) { //倒着画n个
			disk_color(i);
			hdc_rectangle(HDC_Start_X + 23 * HDC_Base_Width / 2 - (1 + 2 * i) * HDC_Base_Width / 2 + 1, HDC_Start_Y - (n - i + 1) * HDC_Base_High, (1 + 2 * i) * HDC_Base_Width, HDC_Base_High, INVALID_RGB);
			Sleep(HDC_Init_Delay);
		}
	}
	else if (src == 'B') {
		for (int i = n;i > 0;i--) { //倒着画n个
			disk_color(i);
			hdc_rectangle(HDC_Start_X + 23 * HDC_Base_Width / 2 + HDC_Underpan_Distance + 23 * HDC_Base_Width - (1 + 2 * i) * HDC_Base_Width / 2 + 1, HDC_Start_Y - (n - i + 1) * HDC_Base_High, (1 + 2 * i) * HDC_Base_Width, HDC_Base_High, INVALID_RGB);
			Sleep(HDC_Init_Delay);
		}
	}
	else if (src == 'C') {
		for (int i = n;i > 0;i--) { //倒着画n个
			disk_color(i);
			hdc_rectangle(HDC_Start_X + 23 * HDC_Base_Width / 2 + HDC_Underpan_Distance + 23 * HDC_Base_Width + HDC_Underpan_Distance + 23 * HDC_Base_Width - (1 + 2 * i) * HDC_Base_Width / 2 + 1, HDC_Start_Y - (n - i + 1) * HDC_Base_High, (1 + 2 * i) * HDC_Base_Width, HDC_Base_High, INVALID_RGB);
			Sleep(HDC_Init_Delay);
		}
	}



	src_idx = src - 'A';
	for (int i = 0; i < n; i++) {
		pole_disks[src_idx][i] = n - i; // 底部放最大的盘子
	}
	pole_count[src_idx] = n;

	cct_gotoxy(0, 39);
	cout << "从" << src << "移动到" << dst << "，共" << n << "层，" << "延时设置为" << speed << "ms" << "（前7步，后面自动变为0ms）";







	cct_gotoxy(8, 30);
	cout << "=========================" << endl;

	cout << "          A         B         C  ";


	Sleep(HDC_Init_Delay);




	// 开始移动
	show_status(src, dst, n, speed, 7);
	step++;
	move_disk_with_status(src, dst, speed, 7);
}




//9.自助
void hanoi_own() {
	//初始化
	step = 0;
	int n, speed;
	char src, dst;


	get_hanoi_input(&n, &src, &dst, &speed, 9);

	char tmp = 198 - src - dst;

	cct_cls();


	int src_idx = src - 'A';
	pole_count[0] = pole_count[1] = pole_count[2] = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 10; j++) {
			pole_disks[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		pole_disks[src_idx][i] = n - i;
	}
	pole_count[src_idx] = n;


	column_only();




	// 绘制初始盘子
	for (int i = n; i > 0; i--) {
		disk_color(i);
		int x = get_peg_center(src);
		int width = (1 + 2 * i) * HDC_Base_Width;
		hdc_rectangle(x - width / 2 + 1, HDC_Start_Y - (n - i + 1) * HDC_Base_High, width, HDC_Base_High, INVALID_RGB);
		Sleep(HDC_Init_Delay);
	}


	cct_gotoxy(8, 30);
	cout << "=========================" << endl;

	cout << "          A         B         C  ";

	cct_gotoxy(0, 41);
	cout << left << "初始 : ";
	// 4. 显示初始状态
	show_status(src, dst, n, speed, 9);


	while (true) {
		cct_gotoxy(0, 42);
		cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";

		char input[3];
		cin >> input;
		cct_gotoxy(60, 42);
		cout << "  ";

		input[0] = toupper(input[0]);
		input[1] = toupper(input[1]);
		// 退出条件
		if (toupper(input[0]) == 'Q') {
			cout << "游戏中止!!!!!";
			break;
		}

		// 输入处理
		if (strlen(input) < 2 || !(input[0] >= 'A' && input[0] <= 'C') || !(input[1] >= 'A' && input[1] <= 'C')) {
			cct_gotoxy(0, 43);
			cout << "  ";
			continue;
		}

		char from = input[0];
		char to = input[1];

		if (pole_count[from - 'A'] == 0) {
			continue;
		}

		if (pole_count[to - 'A'] > 0 && pole_disks[from - 'A'][pole_count[from - 'A'] - 1] > pole_disks[to - 'A'][pole_count[to - 'A'] - 1]) {
			continue;
		}




		// 移动
		step++;
		move_disk_with_status(from, to, speed, 9);

		// 完成
		if (pole_count[dst - 'A'] == n) {
			break;
		}
	}
}



