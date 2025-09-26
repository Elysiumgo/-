/* 2452545 ����� ������ */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�cls()
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
			char ch     ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/
char menu() {
	cout << "1.��I��J��K��L��������������(��Сд���ɣ������ͷ��겻�������ƣ��߽�ֹͣ)" << endl;
	cout << "2.��I��J��K��L��������������(��Сд���ɣ������ͷ��겻�������ƣ��߽����)" << endl;
	cout << "3.�ü�ͷ�������������ң�����дHPKM�������ƶ���꣬�߽�ֹͣ��" << endl;
	cout << "4.�ü�ͷ�������������ң�����дHPKM�������ƶ���꣬�߽���ƣ�" << endl;
	cout << "0.�˳�" << endl;
	cout << "[��ѡ��0-4]";
	char k = _getch();

	return (k);
}
void move_by_ijkl(HANDLE hout, int k) {
	int X = 35, Y = 9, moveto;
	while (1) {
		moveto = _getch();
		if (moveto == 0xE0) { // ��⵽�����ַ��������Ƿ����
			moveto = _getch(); // ��ȡ�ڶ����ַ�
				continue; // �������ͷ��
			
		}
		
		if (moveto == 'I' || moveto == 'i') {//��I
			if (Y > 1)
				Y--;
			else if (k == '2') {
				Y = 17;
				gotoxy(hout, X, 17);
			}
			gotoxy(hout, X, Y);
		}

		

		else if (moveto == 'K' || moveto == 'k') {//��K
			if (Y < 17)
				Y++;
			else if (k == '2')
				Y = 1;
			gotoxy(hout, X, Y);
		}
		else if (moveto == 'J' || moveto == 'j') {//��J
			if (X > 1)
				X--;
			else if (k == '2')
				X = 69;
			gotoxy(hout, X, Y);
		}
		else if (moveto == 'L' || moveto == 'l') {//��L
			if (X < 69)
				X++;
			else if (k == '2')
				X = 1;
			gotoxy(hout, X, Y);
		}
		if (moveto == ' ') //���ո�
			showch(hout, X, Y, ' ');
		if (moveto == 'Q' || moveto == 'q')
			break;
	}
	gotoxy(hout, 0, 23);
	cout << "��Ϸ���������س������ز˵�." << endl;
	while (_getch() != 13)
		;
	cls(hout);
}

void move_by_arrow(HANDLE hout, int k) {
	int X = 35, Y = 9, moveto;
	while (1) {
		moveto = _getch();
		if (moveto == 0xE0 || moveto == 0x00) {
			moveto = _getch();
			if (moveto == 'H') {//����
				if (Y > 1)
					Y--;
				else if (k == '4') {
					Y = 17;
					gotoxy(hout, X, 17);
				}
				gotoxy(hout, X, Y);
			}
			if (moveto == 'P') {//����
				if (Y < 17)
					Y++;
				else if (k == '4')
					Y = 1;
				gotoxy(hout, X, Y);
			}
			if (moveto == 'K') {//����
				if (X > 1)
					X--;
				else if (k == '4')
					X = 68;
				gotoxy(hout, X, Y);
			}
			if (moveto == 'M') {//����
				if (X < 69)
					X++;
				else if (k == '4')
					X = 1;
				gotoxy(hout, X, Y);
			}
		}
		if (moveto == ' ' && X <= 69) //���ո�
			showch(hout, X, Y, ' ');
		if (moveto == 'Q' || moveto == 'q')
			break;
	}
	gotoxy(hout, 0, 23);
	cout << "��Ϸ���������س������ز˵�." << endl;
	while (_getch() != 13)
		;
	cls(hout);
}







int main()
{
	int X = 9, Y = 35;
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand((unsigned int)(time(0)));
	while (1) {//һֱִ��ֱ��������ȷ����
		char k = menu();
		if (k == '1' || k == '2' || k == '3' || k == '4') {
			/* �˾�������ǵ���ϵͳ��cls�������� */
			cls(hout);

			/* ��ʾ��ʼ�ı߿����е�����ַ� */
			init_border(hout);

			gotoxy(hout, 35, 9);
			if (k == '1' || k == '2')
				move_by_ijkl(hout, k);

			if (k == '3' || k == '4')
				move_by_arrow(hout, k);
		}
		if (k == '0')
			break;
		else
			cls(hout);
	}



	return 0;
}
