/*2452545 ����� ������*/
#pragma once

/* ������const���������ͷ�ļ��������� */
#include "hanoi_const_value.h"

/* ------------------------------------------------------------------------------------------------------

	 ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
   ------------------------------------------------------------------------------------------------------ */

char menu();
void my_exit();
void basic1();
void basic2_steps();
void inside1();
void inside2();
void column_only();
void disk_only();
void hanoi_automove();
void hanoi_own();
void hanoi_firststep();