#include "time.h"
using namespace std;
time::time()
{
	hours = minutes = 0;
}
time::time(int h, int m)
{
	hours = h;
	minutes = m;
}
void time::addMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}
void time::addHr(int h)
{
	hours += h;
}
void time::reset(int h, int m)
{
	hours = h;
	minutes = m;
}
time time::sum(const time& t) const
{
	time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}
time time::operator+(const time& t) const
{
	time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}
time time::operator+(const int& m) const
{
	time sum;
	sum.minutes = minutes + m;
	sum.hours = hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

//ostream& time::operator<<(ostream& out)
//{
//	out << hours << "시간, " << minutes << "분" << endl;
//	return out;
//}






time time::operator*(const double& t) const
{
	time sum;
	int totalmin = minutes * t + hours * t * 60;
	sum.hours = totalmin / 60;
	sum.minutes = totalmin % 60;
	return sum;
}
void time::show() const
{
	cout << hours << "시간, " << minutes << "분" << endl;
}