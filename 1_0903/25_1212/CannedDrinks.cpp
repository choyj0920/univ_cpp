
#include "���.h"
#include "CannedDrinks.h"

CannedDrinks::CannedDrinks(const string& name, int price, const string& madeBy) :
	Item(name, price), madeBy(madeBy)
{

}

CannedDrinks::CannedDrinks(const CannedDrinks& copy):Item(copy),madeBy(copy.madeBy)
{
}

int CannedDrinks::getprice()
{
	return 0;
}

void CannedDrinks::printItem()
{
	cout << "ǰ�� : " << name << endl;
	cout << "���� : " << price << endl;
	cout << "������ü : " << madeBy << endl;
	
}
