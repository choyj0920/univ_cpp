#include "ArrayData.h"
#include<iostream>
using namespace std;
int ArrayData::getCount()
{
	return count;
}
ArrayData::ArrayData(const int& capacity):capacity(capacity), used(0)
{
	cout << this->capacity << "�迭 ����\n";
	count++;
	this->data = new double[capacity];
}

ArrayData::ArrayData(const ArrayData& arr) : capacity(arr.capacity),used(arr.used)
{
	cout << this->capacity << "�迭 ����\n";
	count++;
	this->data = new double[this->capacity];
	for (int i = 0; i < used; i++)
		data[i] = arr.data[i];
}

ArrayData::ArrayData(ArrayData&& copy) :capacity(copy.capacity), used(copy.used), data(copy.data)
{
	cout << this->capacity << "�̵� ������\n";
	copy.data = nullptr;
}

ArrayData::ArrayData() :ArrayData(5)
{
}

int ArrayData::count = 0;


ArrayData::~ArrayData()
{
	
	cout << this->capacity << "�迭 ����\n";
	count--;
	if (data != nullptr) {
		delete[] this->data;
		data = nullptr;
	}
	
}

void ArrayData::addElement(double num)
{
	if (!full())
		this->data[used++] = num;
	else
		cout << "�� ������ ����\n";
		
}

bool ArrayData::full() const
{
	return capacity==used;
}

int ArrayData::getCapacity() const
{
	return this->capacity;
}

int ArrayData::getUsed() const
{
	return this->used;
}

void ArrayData::emptyArray()
{
	this->used = 0;
}

void ArrayData::showData() const
{
	double* p = this->data;
	double* endp = p  + this->used;
	cout << "�迭 ��� :";
	while (p < endp) {
		cout << *(p++)<<"  ";
		
	}
	cout << endl;
}

void ArrayData::operator=(const ArrayData& copy)
{
	if (capacity != copy.capacity) {
		delete data;
		capacity = copy.capacity;
		data = new double[copy.capacity];
	}
	emptyArray();
	for (int i = 0; i < copy.used;i++) {
		addElement(*(copy.data + i));
	}
}

void ArrayData::operator=( ArrayData&& copy)
{
	cout << "�̵� ������ ����\n";
	if (data != NULL) {
		delete data;
	}
	capacity = copy.capacity;
	used = copy.used;
	data = copy.data;
	copy.data = NULL;

}

ArrayData ArrayData::getCopyInstance(const ArrayData& copy)
{
	ArrayData arr(copy);
	return arr;
}
