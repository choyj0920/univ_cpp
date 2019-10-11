#include "pch.h"
#include "Rectangle.h"


Rectangle::Rectangle()
{
	cout << "Rectangle 디폴트 생성자 " << endl;
}

Rectangle::Rectangle(const int & x1, const int & y1, const int & x2, const int & y2) : LT(x1, y1), RB(x2, y2)
{
	cout << "Rectangle 생성자2 " << endl;

}

void Rectangle::move(const int & dist)
{
	LT.move(dist);
	RB.move(dist);
}


void Rectangle::show()
{
	LT.show();
	RB.show();
}

Rectangle::~Rectangle()
{
	cout << "Rectangle 소멸자 호출 \n";
}
