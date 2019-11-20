#include "ArrayDataBak.h"
#include <iostream>
using namespace std;
ArrayDataBak::ArrayDataBak() :ArrayDataBak(5)
{
	
}

ArrayDataBak::ArrayDataBak(const int& capacity):ArrayData(capacity)
{
	cout << "백업데이터생성자" << endl;
	backdata = new double[getCapacity()];
	usedB = 0;
}

ArrayDataBak::ArrayDataBak(const ArrayDataBak& copy):ArrayData(copy),usedB(copy.usedB)
{
	cout << this->usedB << "백업데이터 복사 생성자" << endl;
	this->backdata = new double[this->usedB];
	for (int i = 0; i < usedB; i++)
		backdata[i] = copy.backdata[i];
}

ArrayDataBak::ArrayDataBak( ArrayDataBak&& copy) :ArrayData(copy), usedB(copy.usedB), backdata(copy.backdata)
{
	ArrayData::operator=(copy);
	cout << copy.usedB << "백업이동 생성자\n";
	copy.backdata = nullptr;
}

ArrayDataBak::~ArrayDataBak()
{
	//cout << "백업 데이터 삭제" << endl;
	if (backdata != nullptr) {
		delete[] backdata;
	}
}

void ArrayDataBak::backup()
{
	cout << "백업 실행\n";
	usedB = getUsed();
	for (int i = 0; i < usedB; i++) {
		backdata[i] = (*this)[i]; //연산자오버로딩
	}

}

void ArrayDataBak::restore()
{
	cout << "백업복구 실행\n";

	getUsed() = usedB;
	for (int i = 0; i < usedB; i++) {
		(*this)[i] = backdata[i]; //연산자오버로딩
	}
}

ArrayDataBak ArrayDataBak::getCopyInstance(const ArrayDataBak& copy)
{
	ArrayDataBak arr(copy);
	return arr;
}

void ArrayDataBak::operator=(const ArrayDataBak& copy)
{	
	cout << "자식 복사대입연산자실행" << endl;

	if (getCapacity() != copy.getCapacity()) {
		delete [] backdata;
		getCapacity() = copy.getCapacity();
		backdata = new double[copy.getCapacity()];
	}
	usedB = copy.usedB;
	for (int i = 0; i < copy.usedB; i++) {
		backdata[i] = copy.backdata[i];
	}
	ArrayData::operator=(copy);

}

void ArrayDataBak::operator=(ArrayDataBak&& copy)
{
	cout << "백업 이동 연산자 수행\n";
	ArrayData::operator=(copy);

	if (backdata != NULL) {
		delete[] backdata;
	}
	usedB = copy.usedB;
	backdata = copy.backdata;
	copy.backdata = NULL;
}
