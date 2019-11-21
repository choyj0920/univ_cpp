#include "Point.h"

Point::Point(const int& x, const int& y):x(x),y(y)
{
	
}

int Point::getX()
{
	return x;
}

int Point::getY()
{
	return y;
}

bool Point::operator>(const Point& d)
{
	return x > d.x || (x == d.x && y > d.y);
	
}

bool Point::operator<(const Point& d)
{
	return x < d.x || (x==d.x && y<d.y) ;
}
