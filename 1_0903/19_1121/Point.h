#pragma once
class Point
{
private:
	int x;
	int y;
public:
	Point() :Point(0, 0){}
	~Point(){}
	Point(const int& x, const int& y);
	int getX();
	int getY();
	bool operator>(const Point& d);
	bool operator<(const Point& d);
};

