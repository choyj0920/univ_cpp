#pragma once
#include "MyPoint.h"
class Rectangle
{
private:
	MyPoint LT;
	MyPoint RB;

public:
	Rectangle();
	Rectangle(const int& x1, const int& y1, const int& x2, const int &y2);
	void move(const int &dist);
	void show();
	~Rectangle();
};

