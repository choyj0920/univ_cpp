#pragma once
#include <iostream>
using namespace std;
template<typename T>
class TArrayData
{
protected:
	T* data;
	int capacity;
	int used;
public:
	TArrayData(const int& capacity);
	TArrayData(const TArrayData& arr);
	TArrayData(TArrayData&& arr);

	TArrayData();
	virtual ~TArrayData();
	void addElement(T num);
	bool full() const;
	int getCapacity() const;
	int getUsed() const {
		return used;
	}
	void emptyArray();
	void showData() const;
	void operator=(const TArrayData& copy);
	void operator=(TArrayData&& copy);
	TArrayData getObject() {
		return *this;
	}

	

};

template<typename T>
TArrayData<T>::TArrayData(const int& capacity)
{
	used = 0;
	this->capacity = capacity;
	data = new T[capacity];
}

template<typename T>
inline TArrayData<T>::TArrayData(const TArrayData& arr):capacity(arr.capacity),used(arr.used)
{
	data = new T[capacity];
	for (int i = 0; i < used; i++) {
		data[i] = arr.data[i];
	}
}

template<typename T>
inline TArrayData<T>::TArrayData(TArrayData&& arr):used(arr.used),capacity(arr.capacity)
{
	data = arr.data;
	arr.data = NULL;
}

template<typename T>
TArrayData<T>::TArrayData() :TArrayData(10)
{
}

template<typename T>
inline TArrayData<T>::~TArrayData()
{
	if (data != NULL) {
		delete[] data;
 	}
}

template<typename T>
inline void TArrayData<T>::addElement(T num)
{
	if (!full())
		data[used++] = num;
	else
		cout << "data 꽉 참\n";
}

template<typename T>
inline bool TArrayData<T>::full() const
{
	return used >= capacity;
}

template<typename T>
inline int TArrayData<T>::getCapacity() const
{
	return capacity;
}

template<typename T>
inline void TArrayData<T>::emptyArray()
{
	used = 0;
}

template<typename T>
inline void TArrayData<T>::showData() const
{
	cout << "used :" << used << "배열 출력\n";
	for (int i = 0; i < used; i++) {
		cout << i<<" : "<<data[i] << endl;
	}
}

template<typename T>
inline void TArrayData<T>::operator=(const TArrayData& copy)
{
	if (data != NULL) {
		delete[] data;

	}
	data = new T[copy.capacity];


	capacity = copy.capacity;
	used = copy.used;
	for (int i = 0; i < used; i++) {
		data[i] = copy.data[i];
	}
}

template<typename T>
inline void TArrayData<T>::operator=(TArrayData&& copy)
{
	if (data != NULL) {
		delete[] data;
	}
	
	capacity = copy.capacity;
	used = copy.used;
	data = copy.data;
	copy.data = NULL;
}




