#pragma once
#include "ArrayData.h"
class ArrayDataBak :
	public ArrayData
{
private:
	double* backdata;
	int usedB;
public:
	ArrayDataBak();
	ArrayDataBak(const int& capacity);
	ArrayDataBak(const ArrayDataBak& copy);
	ArrayDataBak( ArrayDataBak&& copy);
	~ArrayDataBak();
	void backup();
	void restore();
	static ArrayDataBak getCopyInstance(const ArrayDataBak& copy);
	void operator=(const ArrayDataBak& copy);
	void operator=(ArrayDataBak&& copy);

};

