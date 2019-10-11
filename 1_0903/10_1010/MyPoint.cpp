#include "pch.h"
#include "MyPoint.h"


MyPoint::MyPoint() :MyPoint(0, 0)
{
}

MyPoint::MyPoint(const int & x) : MyPoint(x, 0)
{
}

MyPoint::MyPoint(const int & x, const int & y): x(x),y(y)
{
	cout << "������ ���� \n";
}


MyPoint::~MyPoint()
{
	cout << "�Ҹ��� ����\n";
}

void MyPoint::SetXY(const int & x, const int & y)
{
	this->x = x;
	this->y = y;
}

void MyPoint::move(const int & dist)
{
	x += dist;
	y += dist;
}

void MyPoint::show() const
{
	cout << "[" << x << "," << y << "]" << endl;
}
