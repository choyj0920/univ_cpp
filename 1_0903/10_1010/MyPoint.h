#pragma once
class MyPoint
{
private:
	int x, y;
public:
	MyPoint();
	MyPoint(const int&x);
	MyPoint(const int &x, const int &y);
	~MyPoint();
	void SetXY(const int& x, const int &y);
	void move(const int& dist);
	void show() const;
};

