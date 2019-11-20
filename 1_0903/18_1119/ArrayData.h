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
	virtual ~ArrayData();
	void addElement(double num);
	bool full() const;
	int getCapacity() const;
	int& getCapacity();
	int getUsed() const ;
	int& getUsed() ;
	void emptyArray();
	void showData() const;
	void operator=(const ArrayData& copy);
	void operator=( ArrayData&& copy);
	friend double getArraySum(const ArrayData& arr);
	ArrayData getObject() {
		return *this;
	}
	double& operator[](const int& i);

	static ArrayData getCopyInstance(const ArrayData&copy) ;
};

