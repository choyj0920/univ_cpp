#pragma once
class CannedDrinks:public Item
{
private:
	string madeBy;
public:
	CannedDrinks(const string& name, int price, const string& madeBy);
	CannedDrinks(const CannedDrinks& copy);
	int getprice();
	void printItem();
};

