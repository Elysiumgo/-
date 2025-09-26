/* -----------------------------------------

	 ���ļ�����Ҫ�ύ��������Ķ�

   ----------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include "cmd_hdc_tools.h"
#include "cmd_console_tools.h"
//using namespace std;

extern "C" WINBASEAPI HWND WINAPI GetConsoleWindow(); //VS�д˴����в����ߣ���Ӱ������ʹ��

/* �Ѷ���ľ�̬ȫ�ֱ��� */
static HWND hWnd = GetConsoleWindow();
static HDC hdc = NULL;
static int _BgColor_, _FgColor_, _Width_, _High;

/***************************************************************************
  �������ƣ�
  ��    �ܣ���(x1,y1)-(x2,y2)֮�仭��һ�����ص������
  ���������const int x1�����x���꣬���Ͻ�Ϊ(0,0)
		   const int y1�����y���꣬���Ͻ�Ϊ(0,0)
		   const int x2���յ�y���꣬���Ͻ�Ϊ(0,0)
		   const int y2���յ�y���꣬���Ͻ�Ϊ(0,0)
  �� �� ֵ��
  ˵    ������ɫֱ���õ�ǰ�趨
***************************************************************************/
static void hdc_base_line(int x1, int y1, const int x2, const int y2)
{
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2 + 1, y2 + 1);
#if 0
	if (x1 == x2 && y1 == y2) { //һ��������
		LineTo(hdc, x2 + 1, y2 + 1);
	}
	else if (x1 == x2 && abs(y1 - y2) == 1) { // ��������������
		LineTo(hdc, x2 + 1, y2 + 1);
	}
	else if (abs(x1-x2)==1 && y1 == y2) {	//��������������
		LineTo(hdc, x2 + 1, y2 + 1);
	}
	else
		LineTo(hdc, x2 + 1, y2 + 1);
#endif
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʼ��
  ���������const int bgcolor������ɫ
            const int fgcolor��ǰ��ɫ
			const int width  ����Ļ��ȣ�����
			const int high   ����Ļ�߶ȣ�����
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void hdc_init(const int bgcolor, const int fgcolor, const int width, const int high)
{
	/* ���ͷţ���ֹ��release���ٴ�init��hdc_release�����룩 */
	hdc_release();

	/* ����init����һ����̬ȫ������¼������hdc_cls()���õ� */
	_BgColor_ = bgcolor;
	_FgColor_ = fgcolor;
	_Width_ = width;
	_High = high;

	hdc = GetDC(hWnd);
//	cct_setcursor(CURSOR_INVISIBLE);
//	cct_setcolor(bgcolor, fgcolor);
//	cct_setfontsize("������", 16);
//	cct_setconsoleborder(width / 8 + !!(width % 8), high / 16 + !!(high % 16)); //������Ŀ�ȼ��߶�ת��Ϊ�ض��������������!!�ĺ��壺�������8/16�ı��������ж�+1
//	cct_cls();
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ��ͷŻ�ͼ��Դ
  ���������
  �� �� ֵ��
  ˵    ����������
***************************************************************************/
void hdc_release()
{
	if (hdc) {
		ReleaseDC(hWnd, hdc);
		hdc = NULL;
//		cct_setcursor(CURSOR_VISIBLE_NORMAL);
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����û�����ɫ������RGBֵ
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void hdc_set_pencolor(const int RGB_value)
{
	SelectObject(hdc, GetStockObject(DC_PEN));
	SetDCPenColor(hdc, RGB_value);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����û�����ɫ������RGB��ɫ��ֵ0-255
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void hdc_set_pencolor(const unsigned char red, const unsigned char green, const unsigned char blue)
{
	hdc_set_pencolor(RGB(red, green, blue));
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ������Ļ�����е�ͼ��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/

void hdc_cls()
{
    /* ����һ��Ҫ��һ����ɫ��ʼ������������ص㣬�ҵ�����㷽����ͬѧ����֪ͨ�� */
	hdc_init(_BgColor_, (_FgColor_ + 1)%16, _Width_, _High);

	/* ��thdc_init�л��޸�_FgColor_��ֵ�������+1����+15�����ñ���thdc_clsǰ����ɫ */
	hdc_init(_BgColor_, (_FgColor_ + 15)%16, _Width_, _High);

	/* ���ֻ���������demoʱ�������hdc_cls()���һ������ȱ�ߵ����������ʱ����
	   ������ֻ������л������⣬���ߴ���ʱֵ */
	Sleep(30);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��������Ͻ����꼰��ȡ��߶ȣ�����һ��������
  ���������const int left_up_x			�����Ͻ�x
			const int left_up_y			�����Ͻ�y
		   const int width			�����
		   const int high				���߶�
		   bool filled				���Ƿ���Ҫ��䣨Ĭ����䣩
		   const int RGB_value			����ɫ��Ĭ��ֵ�򲻸ı䣩
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void hdc_rectangle(const int x1, const int y1, const int width, const int high, const int RGB_value)
{
	const int x2 = x1 + (width < 1 ? 1 : width) - 1;	//��С���Ϊ1
	const int y2 = y1 + (high < 1 ? 1 : high) -1;		//��С�߶�Ϊ1

	/* �������û���� hdc_init ��ʼ���������ڣ���ֱ�ӷ��� */
	if (x1 < 0 || x1 >= _Width_ || x2 < 0 || x2 >= _Width_ || y1 < 0 || y1 >= _High || y2 < 0 || y2 >= _High)
		return;

	/* ��������µ���ɫ������Ҫ���� */
	if (RGB_value != INVALID_RGB)
		hdc_set_pencolor(RGB_value);

#if 1
	for (int y = y1; y <= y2; y++) {
		MoveToEx(hdc, x1, y, NULL);
		LineTo(hdc, x2+1, y);
	}
#elif 0
	if (abs(x1-x2)<=abs(y1-y2)) {
		/* ��y1~y2������ģ�⻭������ */
		for (int i = x1; i <= x2; i++) {
			MoveToEx(hdc, x1, y1, NULL);
			LineTo(hdc, x2 + 1, y2 + 1);
//			hdc_base_line(i, y1, i, y2);
		}
	}
	else {
		/* ��y1~y2������ģ�⻭������ */
		for (int i = y1; i <= y2; i++) {
			MoveToEx(hdc, x1, y1, NULL);
			LineTo(hdc, x2 + 1, y2 + 1);
//			hdc_base_line(x1, i, x2, i);
		}
	}
#elif 0
	/* ���x1==x2����ʱ���α�Ϊһ�����Ϊ1��ֱ�ߣ�Ҫ���⴦�� */
	if (x1 == x2) {
		hdc_base_line(x1, y1, x2, y2);
	}
	else {
		/* ��y1~y2������ģ�⻭������ */
		for (int i = y1; i <= y2; i++)
			hdc_base_line(x1, i, x2, i);
	}
#endif
}
