/* 2452545 ����� ������ */
#pragma once

#include<cmath>

class point {
private:
	int x;
	int y;



public:
	int getx() const //�����������const����ʾ�������ڱ��������޸����ݳ�Ա��ֵ 
	{
		return x;
	}
	int gety() const 
	{
		return y;
	}
	/* ���Զ�����Ҫ�ĳ�Ա�������������ޣ��������ڷ�ʽʵ�֣�������������ݳ�Ա */

	void set(int new_x, int new_y) 
	{
		x = new_x;
		y = new_y;

	}
};


class triangle {
private:
	point p1;
	point p2;
	point p3;
	
public:
	/* ������Ҫ������Ӧ���������area����(�β�Ϊ�գ���׼��)��Ҫ����������ܹ��������Σ��򷵻���������򷵻� -1 */
	
	/* ���캯������ʵ�֣���׼���� */
	triangle(int p1_x, int p1_y, int p2_x, int p2_y, int p3_x, int p3_y)
	{
		/* ��p1/p2/p3������ֱ�x,y����ֵ */
		p1.set(p1_x, p1_y);
		p2.set(p2_x, p2_y);
		p3.set(p3_x, p3_y);
	}
	/* ���Զ�����Ҫ�ĳ�Ա�������������ޣ��������ڷ�ʽʵ�֣�������������ݳ�Ա */
	double area()
	{
		int cross = (p2.getx() - p1.getx()) * (p3.gety() - p1.gety())
			- (p2.gety() - p1.gety()) * (p3.getx() - p1.getx());

		// ������㹲�ߣ����� -1
		if (cross == 0) 
			return -1;

		
		return abs(cross) / 2.0;
	}
};
