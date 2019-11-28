#pragma once
#include "ArrayData.h"
template <typename T>
class TArrayDataBak :
	public TArrayData<T>
{
private:
	T* backdata;
	int usedB;
public:
	TArrayDataBak();
	TArrayDataBak(const int& capacity);
	TArrayDataBak(const TArrayDataBak& copy);
	TArrayDataBak(TArrayDataBak&& copy);
	~TArrayDataBak();
	void backup();
	void restore();
	void operator=(const TArrayDataBak& copy);
	void operator=(TArrayDataBak&& copy);
	T& operator[] (const int& n);

};

template<typename T>
TArrayDataBak<T>::TArrayDataBak():TArrayData()
{
	usedB = 0;
	backdata = new T[this->getCapacity()];
}

template<typename T>
TArrayDataBak<T>::TArrayDataBak(const int& capacity): TArrayData<T>(capacity)
{
	usedB = 0;
	backdata = new T[capacity];
}

template<typename T>
inline TArrayDataBak<T>::TArrayDataBak(const TArrayDataBak& copy):TArrayData<T>(copy)
{
	usedB = copy.usedB;
	backdata = new T[this->capacity];
	for (int i = 0; i < usedB; i++) {
		backdata[i] = copy.backdata[i];
	}
}

template<typename T>
inline TArrayDataBak<T>::TArrayDataBak(TArrayDataBak&& copy):TArrayData<T>(move(copy))
{
	usedB = copy.usedB;
	backdata = copy.backdata;
	copy.backdata = NULL;
}

template<typename T>
inline TArrayDataBak<T>::~TArrayDataBak()
{
	if (backdata != NULL) {
		delete[] backdata;
	}
}

template<typename T>
inline void TArrayDataBak<T>::backup()
{
	usedB = this->getUsed();
	for (int i = 0; i < usedB; i++) {
		backdata[i] = this->data[i];

	}
}

template<typename T>
inline void TArrayDataBak<T>::restore()
{
	this->used = usedB;
	for (int i = 0; i < this->used; i++) {
		this->data[i] = backdata[i];
	}
}

template<typename T>
inline void TArrayDataBak<T>::operator=(const TArrayDataBak& copy)
{
	if (backdata != NULL) {
		delete[] backdata;
	}
	usedB = copy.usedB;
	backdata = new T[copy.capacity];
	for (int i = 0; i < usedB; i++) {
		backdata[i] = copy.backdata[i];
	}
}

template<typename T>
inline void TArrayDataBak<T>::operator=(TArrayDataBak&& copy)
{
	if (backdata != NULL)
		delete[] backdata;
	backdata = new T[copy.capacity];
	usedB = copy.usedB;
	TArrayData<T>::operator=(copy);
	for (int i = 0; i < usedB; i++) {
		backdata[i] = copy.backdata[i];
	}
}

template<typename T>
inline T& TArrayDataBak<T>::operator[](const int& n)
{
	return data[n];
}

