#pragma once
class ArrayData
{
private:
	double* data;
	int capacity;
	int used;
	static int count;
public:
	static int getCount();
	ArrayData(const int& capacity);
	ArrayData(const ArrayData& arr);
	ArrayData(ArrayData&& arr);
	
	ArrayData();
	~ArrayData();
	void addElement(double num);
	bool full() const;
	int getCapacity() const;
	int getUsed() const ;
	void emptyArray();
	void showData() const;
	friend double getArraySum(const ArrayData& arr);
	ArrayData getObject() {
		return *this;
	}

	static ArrayData getCopyInstance(const ArrayData&copy) ;
};

