#include "Queue.h"

Queue::Queue()
{
}

Queue::~Queue()
{
}

void Queue::push(const int& key)
{
	list.insert3(key);
}

void Queue::showlist()
{
	list.showList();
}

int Queue::pop(bool& suc)
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
