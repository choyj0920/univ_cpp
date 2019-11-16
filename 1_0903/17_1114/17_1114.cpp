#include "time.h"
#include "ArrayData.h"
using namespace std;

time operator*(double mult, const time& t)
{
	time result;
	long totalminutes = t.hours * mult * 60 + t.minutes * mult;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}
time operator+(int mult, const time& t)
{
	time result;
	result.minutes = t.minutes+mult;
	result.hours = t.hours+result.minutes / 60;
	result.minutes = result.minutes % 60;
	return result;
}

ostream& operator<<(ostream& out, const time& t) {
	out << t.hours << "시간, " << t.minutes << "분" << endl;
	return out;

}

int main()
{
	cout << "7조 박진영 양석준 송재원 조윤직\n";

	time t1(4,10);
	time t2(2, 55);
	t1.show();
	t2.show();
	t1.sum(t2).show();
	time t3 = t1 + t2;
	t3.show();
	t3 = t3 + 10;
	t3.show();
	t3=t3 * 10;
	t3.show();
	time t4 = 10 + t3;
	t4.show();
	cout << t4;


	/*
	ArrayData data(10);
	data.addElement(10.0);
	data.addElement(10.1);
	data.addElement(10.2);
	data.addElement(10.3);
	data.showData();
	
	ArrayData data2;
	data2 = data;
	data2.showData();

	ArrayData data3;
	data3 = ArrayData(10);
	*/

}

