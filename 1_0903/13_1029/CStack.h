#pragma once
#include "CLinkedList.h"
class CStack
{
private:
	CLinkedList list;

public:
	CStack();
	~CStack();
	void push(const int& key);
	void showlist();
	int pop(bool &suc);

};

