/* 2452545 计算机 刘晴语 */
#pragma once

#include<cmath>

class point {
private:
	int x;
	int y;



public:
	int getx() const //函数声明后加const，表示不允许在本函数中修改数据成员的值 
	{
		return x;
	}
	int gety() const 
	{
		return y;
	}
	/* 可以定义需要的成员函数，数量不限，并以体内方式实现，不允许添加数据成员 */

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
	/* 根据需要补充相应的语句后完成area函数(形参为空，不准改)，要求：如果三点能构成三角形，则返回面积，否则返回 -1 */
	
	/* 构造函数（已实现，不准动） */
	triangle(int p1_x, int p1_y, int p2_x, int p2_y, int p3_x, int p3_y)
	{
		/* 给p1/p2/p3三个点分别赋x,y坐标值 */
		p1.set(p1_x, p1_y);
		p2.set(p2_x, p2_y);
		p3.set(p3_x, p3_y);
	}
	/* 可以定义需要的成员函数，数量不限，并以体内方式实现，不允许添加数据成员 */
	double area()
	{
		int cross = (p2.getx() - p1.getx()) * (p3.gety() - p1.gety())
			- (p2.gety() - p1.gety()) * (p3.getx() - p1.getx());

		// 如果三点共线，返回 -1
		if (cross == 0) 
			return -1;

		
		return abs(cross) / 2.0;
	}
};
