#pragma once
#include <iostream>
using namespace std;
#include "CNode.h"
class CLinkedList
{
private:
	CNode* head;
	CNode* tail;


public:
	CLinkedList();
	~CLinkedList();
	void delete_all();
	void insert1(const int& key);
	void insertsort(const int& key);
	void insert3(const int& key);
	void showList() {
		CNode* p = head->getNext();
		while (p != tail) {
			cout << p->getkey() << endl;
			p = p->getNext();
		}
	}
	CNode* findNode(const int& key);
	void delete_key1(const int& key);
	CNode* gettail();
	CNode* gethead();

};

