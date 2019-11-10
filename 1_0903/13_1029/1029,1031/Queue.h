#pragma once
#include "CLinkedList.h"
class Queue
{
private:
	CLinkedList list;

public:
	Queue();
	~Queue();
	void push(const int& key);
	void showlist();

	int pop(bool& suc);

};

