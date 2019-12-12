#include "���.h"
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
	cout << "ǰ�� : " << name << endl;
	cout << "���� : " << price << endl;
	cout << "Ŀ�� : " << nongdo << endl;
	cout << "ũ�� : " << cream << endl;
	cout << "���� : " << sugar << endl;
	cout << "�ÿ� : " << (isCold?"������":"������") << endl;
}
