
#include "헤더.h"
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
	cout << "품목 : " << name << endl;
	cout << "가격 : " << price << endl;
	cout << "제조업체 : " << madeBy << endl;
	
}
