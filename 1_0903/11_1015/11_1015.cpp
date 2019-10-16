#include <iostream>
#include <string>
#include "ArrayData.h"
using namespace std;

void showArray(ArrayData arr) { //여기서도 복사 생성자
	arr.showData();
}
double getArraySum(const ArrayData& arr) {
	double total = 0;
	for (int i = 0; i < arr.getUsed(); i++) {
		total += arr.data[i];
	}
	return total;
}

void lab01() {
	ArrayData a1(3);
	//ArrayData a2 = a1; //default 복사생성자 로 복사할경우 data가 같은 주소값으로 복사되어서 다른 복사 생성자 재정의 필요
	a1.addElement(1.1);
	a1.addElement(2.1);
	/*ArrayData a2(a1);
	a2.addElement(3.1);
	a1.addElement(5.1);*/
	showArray(a1);
}
void lab02() {
	ArrayData a1(3);
	a1.addElement(1.1);
	a1.addElement(2.1);
	ArrayData a2(a1);
	ArrayData* a3 = new ArrayData(2);
	cout << ArrayData::getCount() << endl;
	delete a3;
	cout << ArrayData::getCount() << endl;
}

int main()
{
    std::cout << "201810754 조윤직\n";
	lab02();
}
