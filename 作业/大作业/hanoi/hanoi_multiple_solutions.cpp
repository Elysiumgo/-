/* 2452545 ����� ������ */
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

	 ���ļ����ܣ�
	1����ű� hanoi_main.cpp �и��ݲ˵�����ֵ���õĸ��˵����Ӧ��ִ�к���

	 ���ļ�Ҫ��
	1�����������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
	2�������徲̬ȫ�ֱ�����������Ҫ��������Ҫ�����ĵ���ʾ��ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
	3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */



int pole_count[3] = { 0 };       // ��¼ÿ�����ӵ�Բ������0A,1B,2C��
int pole_disks[3][10];  // ��¼Բ�̱��
int step = 0;

void get_hanoi_input(int* n, char* src, char* dst, int* speed, int mode)
{
	// �������
	while (true) {
		cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
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

	// ������ʼ��
	while (true) {
		cout << "��������ʼ��(A-C)" << endl;
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

	// ת��Ϊ��д
	if (*src >= 'a' && *src <= 'c') {
		*src -= 32;
	}

	// ����Ŀ����
	while (1) {
		cout << "������Ŀ����(A-C)" << endl;
		cin >> *dst;
		if (cin.good() && *dst != *src && (*dst == 'A' || *dst == 'a' || *dst == 'B' || *dst == 'b' || *dst == 'C' || *dst == 'c')) {
			std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			break;
		}
		else if (cin.good() && *dst == *src) {
			cout << "Ŀ����(" << *src << ")��������ʼ��(" << *src << ")��ͬ" << endl;
			std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
		}
		else {
			cin.clear();
			std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
		}
	}

	// ת��Ϊ��д
	if (*dst >= 'a' && *dst <= 'c') {
		*dst -= 32;
	}

	// �����ٶ�
	if (mode == 4 || mode == 5 || mode == 6 || mode == 7 || mode == 8 || mode == 9) {
		while (true) {
			cout << "�������ƶ��ٶ�(0-20��0-���س�������ʾ 1-20:��ʱ1-20ms)" << endl;
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

	cout << "���س�������" << endl;
	char k = _getch();
	while (k != '\n' && k != '\r')
		;
}

// ��������X����
int get_peg_center(char peg) {
	int x = HDC_Start_X + 23 * HDC_Base_Width / 2;
	if (peg == 'B') x += 23 * HDC_Base_Width + HDC_Underpan_Distance;
	else if (peg == 'C') x += 2 * (23 * HDC_Base_Width + HDC_Underpan_Distance);
	return x;
}


//�趨���ӻ�����ɫ
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

//�ڲ�������ʾ(����+����)
void show_status(char from = 0, char to = 0, int disk = 0, int speed = 10, int mode = 3) {
	const int X = 10, Y = 29;

	if (step == 0) {
		cct_gotoxy(0, 41);
		cout << left << setw(17) << "��ʼ : ";
	}
	// ��ʾ������Ϣ
	if (step > 0) {
		// ������ͣ�͹��λ��
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

		cout << "�� " << setw(3) << step << " ��(" << setw(2) << disk << "): "
			<< from << "-->" << to << " ";
	}

	// ������ʾ
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

	// ������ʾ
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

	// 1. ��ʾ�ƶ���ʾ�����ӻ���ԭλ��
	if (mode == 7 || mode == 8 || mode == 9) {
		Sleep(HDC_Init_Delay);
	}

	// 2. ��src�Ƴ�����
	pole_disks[from_idx][--pole_count[from_idx]] = 0;


	// 3. ��������Ŀ��λ��
	
	pole_disks[to_idx][pole_count[to_idx]] = disk;
	show_status(from, to, disk, speed, mode);

	if (mode == 7 || mode == 8 || mode == 9)
	{
		// 4. ����
		int disk_size = disk;
		int from_x = get_peg_center(from);
		int to_x = get_peg_center(to);
		int width = (1 + 2 * disk_size) * HDC_Base_Width;

		// ����
		int current_x = from_x - width / 2;
		int current_y = HDC_Start_Y - (pole_count[from_idx] + 1) * HDC_Base_High;
		while (current_y > HDC_Top_Y) {
			hdc_rectangle(current_x, current_y, width, HDC_Base_High, RGB(12, 12, 12));
			hdc_rectangle(from_x - HDC_Base_Width / 2, current_y, HDC_Base_Width, HDC_Base_High, RGB(249, 241, 165));
			current_y -= HDC_Step_Y;
			disk_color(disk_size);
			hdc_rectangle(current_x, current_y, width, HDC_Base_High, INVALID_RGB);

			// ���Ʋ�����ʾ����ͣ
			if (speed == 0 && (step != 0 || mode == 9)) {
				while (_getch() != 13)
					;
			}
			else if (step != 0) {
				if (step <= 7)
					Sleep(speed);
			}
		}

		// ˮƽ�ƶ�
		while (current_x != to_x - width / 2) {
			hdc_rectangle(current_x, current_y, width, HDC_Base_High, RGB(12, 12, 12));
			if (current_x < to_x - width / 2) current_x += HDC_Step_X;
			else current_x -= HDC_Step_X;
			disk_color(disk_size);
			hdc_rectangle(current_x, current_y, width, HDC_Base_High, INVALID_RGB);

			// ���Ʋ�����ʾ����ͣ
			if (speed == 0 && (step != 0 || mode == 9)) {
				while (_getch() != 13)
					;
			}
			else if (step != 0) {
				if (step <= 7)
					Sleep(speed);
			}
		}

		// �½�
		int target_y = HDC_Start_Y - (pole_count[to_idx] + 1) * HDC_Base_High;
		while (current_y < target_y) {
			hdc_rectangle(current_x, current_y, width, HDC_Base_High, RGB(12, 12, 12));
			if (current_y > HDC_Top_Y + HDC_Base_High)
				hdc_rectangle(to_x - HDC_Base_Width / 2, current_y, HDC_Base_Width, HDC_Base_High, RGB(249, 241, 165));
			current_y += HDC_Step_Y;
			//����
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

	// 5. ��ʽ���¸߶�
	pole_disks[to_idx][pole_count[to_idx]++] = disk;
	

	// 6. ��ʾ����״̬
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



//1. ������

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




//2. ������(������¼)

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




//3. ����
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


	// ���

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




//4. �ڲ�������ʾ(����+����)

void inside2()
{
	int n, speed;
	char src, dst;

	get_hanoi_input(&n, &src, &dst, &speed, 4);

	// ��ʼ��ȫ�ֱ���
	step = 0;
	for (int i = 0; i < 3; i++) {
		pole_count[i] = 0;
		for (int j = 0; j < 10; j++) {
			pole_disks[i][j] = 0;
		}
	}

	// ��ʼ��Դ����
	int src_idx = src - 'A';
	for (int i = n; i >= 1; i--) {
		pole_disks[src_idx][pole_count[src_idx]++] = i;
	}

	cct_cls();
	cout << "��" << src << "�ƶ���" << dst << "����" << n << "�㣬" << "��ʱ����Ϊ" << speed << "ms";

	cct_gotoxy(8, 30);
	cout << "=========================" << endl;

	cout << "          A         B         C  ";

	cct_gotoxy(3, 25);
	cout << left << setw(21) << "��ʼ:";
	show_status(src, dst, n, speed, 4);

	// ��ʼ�ƶ�
	char tmp = 198 - src - dst;
	hanoi_final(n, src, dst, tmp, speed, 4);

	my_exit();
}





//5.ͼ�ν�-Ԥ��-������Բ��
void column_only()
{
	hdc_init();
	hdc_set_pencolor(249, 241, 165);//���ӵĻ�ɫ

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




//6. ͼ�ν�-Ԥ��-����ʼ���ϻ�n������
void disk_only()
{
	int n, speed;
	char src, dst;


	get_hanoi_input(&n, &src, &dst, &speed, '6');

	char tmp = 198 - src - dst;

	cct_cls();
	cct_gotoxy(0, 38);
	cout << "��" << src << "�ƶ���" << dst << "����" << n << "��" << endl;

	column_only();

	if (src == 'A') {
		for (int i = n;i > 0;i--) { //���Ż�n��
			disk_color(i);
			hdc_rectangle(HDC_Start_X + 23 * HDC_Base_Width / 2 - (1 + 2 * i) * HDC_Base_Width / 2 + 1, HDC_Start_Y - (n - i + 1) * HDC_Base_High, (1 + 2 * i) * HDC_Base_Width, HDC_Base_High, INVALID_RGB);
			Sleep(HDC_Init_Delay);
		}
	}
	else if (src == 'B') {
		for (int i = n;i > 0;i--) { //���Ż�n��
			disk_color(i);
			hdc_rectangle(HDC_Start_X + 23 * HDC_Base_Width / 2 + HDC_Underpan_Distance + 23 * HDC_Base_Width - (1 + 2 * i) * HDC_Base_Width / 2 + 1, HDC_Start_Y - (n - i + 1) * HDC_Base_High, (1 + 2 * i) * HDC_Base_Width, HDC_Base_High, INVALID_RGB);
			Sleep(HDC_Init_Delay);
		}
	}
	else if (src == 'C') {
		for (int i = n;i > 0;i--) { //���Ż�n��
			disk_color(i);
			hdc_rectangle(HDC_Start_X + 23 * HDC_Base_Width / 2 + HDC_Underpan_Distance + 23 * HDC_Base_Width + HDC_Underpan_Distance + 23 * HDC_Base_Width - (1 + 2 * i) * HDC_Base_Width / 2 + 1, HDC_Start_Y - (n - i + 1) * HDC_Base_High, (1 + 2 * i) * HDC_Base_Width, HDC_Base_High, INVALID_RGB);
			Sleep(HDC_Init_Delay);
		}
	}


}




//8.ͼ�ν� - �Զ��ƶ��汾

void hanoi_automove()
{
	step = 0;
	// ����
	int n, speed;
	char src, dst;

	get_hanoi_input(&n, &src, &dst, &speed, 8);

	char tmp = 198 - src - dst; // ASCII������м����� (A=65, B=66, C=67 -> 65+66+67=198)

	cct_cls();

	// ��ʼ��
	int src_idx = src - 'A';
	pole_count[0] = pole_count[1] = pole_count[2] = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 10; j++) {
			pole_disks[i][j] = 0;
		}
	}

	// ����Դ���ӳ�ʼ��disk_stacks
	for (int i = 0; i < n; i++) {
		pole_disks[src_idx][i] = n - i; // �ײ�����������
	}
	pole_count[src_idx] = n;

	column_only();
	if (src == 'A') {
		for (int i = n;i > 0;i--) { //���Ż�n��
			disk_color(i);
			hdc_rectangle(HDC_Start_X + 23 * HDC_Base_Width / 2 - (1 + 2 * i) * HDC_Base_Width / 2 + 1, HDC_Start_Y - (n - i + 1) * HDC_Base_High, (1 + 2 * i) * HDC_Base_Width, HDC_Base_High, INVALID_RGB);
			Sleep(HDC_Init_Delay);
		}
	}
	else if (src == 'B') {
		for (int i = n;i > 0;i--) { //���Ż�n��
			disk_color(i);
			hdc_rectangle(HDC_Start_X + 23 * HDC_Base_Width / 2 + HDC_Underpan_Distance + 23 * HDC_Base_Width - (1 + 2 * i) * HDC_Base_Width / 2 + 1, HDC_Start_Y - (n - i + 1) * HDC_Base_High, (1 + 2 * i) * HDC_Base_Width, HDC_Base_High, INVALID_RGB);
			Sleep(HDC_Init_Delay);
		}
	}
	else if (src == 'C') {
		for (int i = n;i > 0;i--) { //���Ż�n��
			disk_color(i);
			hdc_rectangle(HDC_Start_X + 23 * HDC_Base_Width / 2 + HDC_Underpan_Distance + 23 * HDC_Base_Width + HDC_Underpan_Distance + 23 * HDC_Base_Width - (1 + 2 * i) * HDC_Base_Width / 2 + 1, HDC_Start_Y - (n - i + 1) * HDC_Base_High, (1 + 2 * i) * HDC_Base_Width, HDC_Base_High, INVALID_RGB);
			Sleep(HDC_Init_Delay);
		}
	}
	// ��ʾ��ʼ״̬
	show_status(src, dst, n, speed, 8);

	cct_gotoxy(0, 39);
	cout << "��" << src << "�ƶ���" << dst << "����" << n << "�㣬" << "��ʱ����Ϊ" << speed << "ms" << "��ǰ7���������Զ���Ϊ0ms��";

	cct_gotoxy(8, 30);
	cout << "=========================" << endl;
	cout << "          A         B         C  ";

	






	// ��ʼ�ƶ�
	hanoi_final(n, src, dst, tmp, speed, 8);
}



//7.һ��
void hanoi_firststep()
{
	step = 0;
	int n, speed;
	char src, dst;


	get_hanoi_input(&n, &src, &dst, &speed, 7);

	char tmp = 198 - src - dst;


	cct_cls();


	// ��ʼ��
	int src_idx = src - 'A';
	pole_count[0] = pole_count[1] = pole_count[2] = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 10; j++) {
			pole_disks[i][j] = 0;
		}
	}

	// ����Դ���ӳ�ʼ��disk_stacks
	for (int i = 0; i < n; i++) {
		pole_disks[src_idx][i] = n - i;
	}
	pole_count[src_idx] = n;

	column_only();

	if (src == 'A') {
		for (int i = n;i > 0;i--) { //���Ż�n��
			disk_color(i);
			hdc_rectangle(HDC_Start_X + 23 * HDC_Base_Width / 2 - (1 + 2 * i) * HDC_Base_Width / 2 + 1, HDC_Start_Y - (n - i + 1) * HDC_Base_High, (1 + 2 * i) * HDC_Base_Width, HDC_Base_High, INVALID_RGB);
			Sleep(HDC_Init_Delay);
		}
	}
	else if (src == 'B') {
		for (int i = n;i > 0;i--) { //���Ż�n��
			disk_color(i);
			hdc_rectangle(HDC_Start_X + 23 * HDC_Base_Width / 2 + HDC_Underpan_Distance + 23 * HDC_Base_Width - (1 + 2 * i) * HDC_Base_Width / 2 + 1, HDC_Start_Y - (n - i + 1) * HDC_Base_High, (1 + 2 * i) * HDC_Base_Width, HDC_Base_High, INVALID_RGB);
			Sleep(HDC_Init_Delay);
		}
	}
	else if (src == 'C') {
		for (int i = n;i > 0;i--) { //���Ż�n��
			disk_color(i);
			hdc_rectangle(HDC_Start_X + 23 * HDC_Base_Width / 2 + HDC_Underpan_Distance + 23 * HDC_Base_Width + HDC_Underpan_Distance + 23 * HDC_Base_Width - (1 + 2 * i) * HDC_Base_Width / 2 + 1, HDC_Start_Y - (n - i + 1) * HDC_Base_High, (1 + 2 * i) * HDC_Base_Width, HDC_Base_High, INVALID_RGB);
			Sleep(HDC_Init_Delay);
		}
	}



	src_idx = src - 'A';
	for (int i = 0; i < n; i++) {
		pole_disks[src_idx][i] = n - i; // �ײ�����������
	}
	pole_count[src_idx] = n;

	cct_gotoxy(0, 39);
	cout << "��" << src << "�ƶ���" << dst << "����" << n << "�㣬" << "��ʱ����Ϊ" << speed << "ms" << "��ǰ7���������Զ���Ϊ0ms��";







	cct_gotoxy(8, 30);
	cout << "=========================" << endl;

	cout << "          A         B         C  ";


	Sleep(HDC_Init_Delay);




	// ��ʼ�ƶ�
	show_status(src, dst, n, speed, 7);
	step++;
	move_disk_with_status(src, dst, speed, 7);
}




//9.����
void hanoi_own() {
	//��ʼ��
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




	// ���Ƴ�ʼ����
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
	cout << left << "��ʼ : ";
	// 4. ��ʾ��ʼ״̬
	show_status(src, dst, n, speed, 9);


	while (true) {
		cct_gotoxy(0, 42);
		cout << "�������ƶ�������(������ʽ��AC=A���˵������ƶ���C��Q=�˳�) ��";

		char input[3];
		cin >> input;
		cct_gotoxy(60, 42);
		cout << "  ";

		input[0] = toupper(input[0]);
		input[1] = toupper(input[1]);
		// �˳�����
		if (toupper(input[0]) == 'Q') {
			cout << "��Ϸ��ֹ!!!!!";
			break;
		}

		// ���봦��
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




		// �ƶ�
		step++;
		move_disk_with_status(from, to, speed, 9);

		// ���
		if (pole_count[dst - 'A'] == n) {
			break;
		}
	}
}



