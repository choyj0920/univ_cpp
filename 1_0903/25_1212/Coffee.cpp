#include "헤더.h"
#include "Coffee.h"

Coffee::Coffee(const Coffee& copy):Item(copy), nongdo(copy.nongdo), cream(copy.cream), sugar(copy.sugar), isCold(copy.isCold)
{
}

Coffee::Coffee(const string& name,
	int price, int nongdo, int cream, int sugar, bool isCold):
	Item(name,price),nongdo(nongdo),cream(cream),sugar(sugar),isCold(isCold)
{

}

void Coffee::printItem()
{
	cout << "품목 : " << name << endl;
	cout << "가격 : " << price << endl;
	cout << "커피 : " << nongdo << endl;
	cout << "크림 : " << cream << endl;
	cout << "설탕 : " << sugar << endl;
	cout << "냉온 : " << (isCold?"냉음료":"온음료") << endl;
}
