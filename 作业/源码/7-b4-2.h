/* 2452545 ����� ������ */
#pragma once
#include<cmath>


/* ���������Ҫ��ͷ�ļ�������ռ� */

class triangle;  //�����ǰ������˼��һ�£����������Ŀ����Ϊʲô

/* point��Ķ��弰ʵ�֣��Ѹ����������ݣ���Ҫ�󲹳���� */
class point {
private:
	int x;
	int y;
public:
	/* �������ڴ����һ����Ա����������1����,Ҫ������ʵ�� */
	void set(int new_x, int new_y) {
		x = new_x;
		y = new_y;
	}
	/* ������������Ǹ���Ա�����⣬������������κε����ݳ�Ա�ͳ�Ա�����������Ը�����Ҫ����������� */
	friend class triangle;
};

/* triangle��Ķ��弰ʵ�֣��Ѹ����������ݣ���Ҫ�󲹳���� */
class triangle {
private:
	point p1;
	point p2;
	point p3;
	//�����������private���ݳ�Ա�⣬������������κ����͵����ݳ�Ա
public:
	/* ���캯������ʵ�֣���׼���� */
	triangle(int p1_x, int p1_y, int p2_x, int p2_y, int p3_x, int p3_y)
	{
		/* ��p1/p2/p3������ֱ�x,y����ֵ */
		p1.set(p1_x, p1_y);
		p2.set(p2_x, p2_y);
		p3.set(p3_x, p3_y);
	}


	double area()
	{
		double area = 0.5 * std::abs(
			(p2.x - p1.x) * (p3.y - p1.y) -
			(p3.x - p1.x) * (p2.y - p1.y)
		);
		if (area < 1e-10) {
			return -1;
		}

		return area;
	
	}

	/* ���Զ�����Ҫ�ĳ�Ա�������������ޣ��������ڷ�ʽʵ�֣�������������ݳ�Ա */

};
