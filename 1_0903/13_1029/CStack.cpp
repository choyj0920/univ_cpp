#include "CStack.h"

CStack::CStack()
{

}

CStack::~CStack()
{
}

void CStack::push(const int& key)
{
	list.insert1(key);
}

void CStack::showlist()
{
	list.showList();
}

int CStack::pop(bool& suc)
{
	CNode* temp = list.gethead()->getNext();
	if (temp != list.gettail()) {
		int n = temp->getkey();
		list.delete_key1(n);
		suc = true;
		return n;
	}
	else
		cout << "리스트가 비어 있어 pop할수 없습니다\n";
	suc = false;
	return false;
}
