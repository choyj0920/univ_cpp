#pragma once
class VendingMachine
{
private:
	string number;
	int num;
	int count;
	Item** items;

public:
	VendingMachine(const string& number, int num) :number(number), num(num), count(0){
		items = new Item * [num];
		
	}
	~VendingMachine();
	VendingMachine();
	void additem(Item* item);
	void operator=(const VendingMachine& copy);
	bool operator<(const VendingMachine& v)const {
		return count < v.count;
	}
	friend ostream& operator<<(ostream& out, const VendingMachine& vending);

	
};

