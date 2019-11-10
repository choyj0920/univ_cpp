#include "CLinkedList.h"

CLinkedList::CLinkedList()
{
	head = new CNode();
	tail = new CNode();
	head->setNext(tail);
	tail->setNext(tail);
}

CLinkedList::~CLinkedList()
{
	delete_all();
	delete head;
	delete tail;
}

void CLinkedList::delete_all()
{
	CNode* p = head->getNext();
	while (p != tail) {
		CNode* temp = p->getNext();
		delete p;
		p =temp;
	}
}

void CLinkedList::insert1(const int& key)
{
	{
		CNode* temp = new CNode;
		temp->setkey(key);
		temp->setNext(head->getNext());
		head->setNext(temp);
	}
}

void CLinkedList::insertsort(const int& key)
{
	CNode* fp = head;
	CNode* p = head->getNext();
	CNode* temp = new CNode;
	temp->setkey(key);
	while (p != tail) {
		if (key < p->getkey()) {
			break;
		}
		else {
			fp = p;
			p = p->getNext();
		}
	}
	fp->setNext(temp);
	temp->setNext(p);
}

void CLinkedList::insert3(const int& key)
{
	CNode* fp = head;
	CNode* p = head->getNext();
	CNode* temp = new CNode;
	temp->setkey(key);
	while (p != tail) {
		fp = p;
		p = p->getNext();
	}
	fp->setNext(temp);
	temp->setNext(p);
}

CNode* CLinkedList::findNode(const int& key)
{
	CNode* s = head->getNext();
	while (s != tail && s->getkey() != key) {
		s = s->getNext();
	}
	return s;
}

void CLinkedList::delete_key1(const int& key)
{
	CNode* p = head;
	CNode* s = head->getNext();
	while (s != tail && s->getkey() != key) {
		p = s;
		s = p->getNext();
	}
	if (s != tail) {
		p->setNext(s->getNext());
		cout << "key : "<<s->getkey()<<" »èÁ¦ ÇÔ !\n";
		delete s;
	}
}

CNode* CLinkedList::gettail()
{
	return tail;
}

CNode* CLinkedList::gethead()
{
	return head;
}
