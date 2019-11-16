#ifndef MYTIME_H_
#define MYTIME_H_
#include <iostream>
using namespace std;

class time
{
private:
	int hours;
	int minutes;
public:
	time();
	time(int h, int m);
	void addMin(int m);
	void addHr(int h);
	void reset(int h, int m);
	time sum(const time& t) const;
	time operator+(const time& t) const;
	time operator+(const int& m) const;
	friend ostream& operator <<(ostream& out, const time& t);

	//ostream& operator<<(ostream &out );
	time operator*(const double& d) const;
	friend time operator*(double m, const time& t); //ÇÁ·»µå ¼±¾ð
	friend time operator+(int m, const time& t);  //ÇÁ·»µå ¼±¾ð


	void show() const;
};

#endif