#include "ArrayDataBak.h"
#include <iostream>
using namespace std;
ArrayDataBak::ArrayDataBak() :ArrayDataBak(5)
{
	
}

ArrayDataBak::ArrayDataBak(const int& capacity):ArrayData(capacity)
{
	cout << "��������ͻ�����" << endl;
	backdata = new double[getCapacity()];
	usedB = 0;
}

ArrayDataBak::ArrayDataBak(const ArrayDataBak& copy):ArrayData(copy),usedB(copy.usedB)
{
	cout << this->usedB << "��������� ���� ������" << endl;
	this->backdata = new double[this->usedB];
	for (int i = 0; i < usedB; i++)
		backdata[i] = copy.backdata[i];
}

ArrayDataBak::ArrayDataBak( ArrayDataBak&& copy) :ArrayData(copy), usedB(copy.usedB), backdata(copy.backdata)
{
	ArrayData::operator=(copy);
	cout << copy.usedB << "����̵� ������\n";
	copy.backdata = nullptr;
}

ArrayDataBak::~ArrayDataBak()
{
	//cout << "��� ������ ����" << endl;
	if (backdata != nullptr) {
		delete[] backdata;
	}
}

void ArrayDataBak::backup()
{
	cout << "��� ����\n";
	usedB = getUsed();
	for (int i = 0; i < usedB; i++) {
		backdata[i] = (*this)[i]; //�����ڿ����ε�
	}

}

void ArrayDataBak::restore()
{
	cout << "������� ����\n";

	getUsed() = usedB;
	for (int i = 0; i < usedB; i++) {
		(*this)[i] = backdata[i]; //�����ڿ����ε�
	}
}

ArrayDataBak ArrayDataBak::getCopyInstance(const ArrayDataBak& copy)
{
	ArrayDataBak arr(copy);
	return arr;
}

void ArrayDataBak::operator=(const ArrayDataBak& copy)
{	
	cout << "�ڽ� ������Կ����ڽ���" << endl;

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
	cout << "��� �̵� ������ ����\n";
	ArrayData::operator=(copy);

	if (backdata != NULL) {
		delete[] backdata;
	}
	usedB = copy.usedB;
	backdata = copy.backdata;
	copy.backdata = NULL;
}
