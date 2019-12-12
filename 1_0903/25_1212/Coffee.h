#pragma once
class Coffee :
	public Item
{
private:
	int nongdo;
	int cream;
	int sugar;
	bool isCold;
public:

	~Coffee(){}
	Coffee(const Coffee& copy);
	Coffee(const string& name, int price, int nongdo,
		int cream, int sugar, bool isCold);
	void printItem();
	
};

