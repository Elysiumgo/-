/* 2452545 ����� ������ */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include"hanoi.h"
#include"hanoi_const_value.h"
#include"cmd_console_tools.h"
using namespace std;
/* ----------------------------------------------------------------------------------

	 ���ļ����ܣ�
	1����main����
	2����ʼ����Ļ
	3�����ò˵�������hanoi_menu.cpp�У�������ѡ��
	4������ѡ����ò˵������Ӧ��ִ�к�����hanoi_multiple_solutions.cpp�У�

	 ���ļ�Ҫ��
	1����������ȫ�ֱ��������ⲿȫ�ֺ;�̬ȫ�֣�const��#define�������Ʒ�Χ�ڣ�
	2����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	3���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */

   
int main()
{
	cout << "��ȷ�ϵ�ǰcmd���ڵĴ�СΪ40��*120�����ϣ�����Ϊ������/16����C������Q�˳�" << endl;
	while (1) {
		char ch = _getch();
		if (ch == 'C' || ch == 'c')
			break;
		if (ch == 'Q' || ch == 'q')
			return 0;
	}

	while (1) {
		cct_cls();
		char start=menu();
		if (start == '1') {
			cct_cls();
			basic1();
		}
		else if (start == '2') {
			cct_cls();
			basic2_steps();
		}
		else if (start == '0')
			break;
		else if (start == '3') {
			cct_cls();
			inside1();
		}
		else if (start == '4') {
			cct_cls();
			inside2();
		}
		else if (start == '5') {
			cct_cls();
			column_only();
			my_exit();
		}
		else if (start == '6') {
			cct_cls();
			disk_only();
			my_exit();
		}
		else if (start == '8') {
			cct_cls();
			hanoi_automove();
			my_exit();
		}
		else if (start == '9') {
			cct_cls();
			hanoi_own();
			my_exit();
		}
		else if (start == '7') {
			cct_cls();
			hanoi_firststep();
			my_exit();
		}
	}
	
	









	return 0;
}