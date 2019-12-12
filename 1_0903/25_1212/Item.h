#pragma once
class  Item
{
protected:
	string name;
	int price;

public:
	Item() :Item("", 0) {

	}
	virtual~Item(){}
	Item(const string& name, const int& price):name(name),price(price) {

	}
	virtual void printItem() = 0;
	int getprice()const {
		return price;
	}
	string getname()const {
		return name;
	}
};

