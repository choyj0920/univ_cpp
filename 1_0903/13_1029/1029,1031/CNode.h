#pragma once
class CNode
{
private:
	int key;
	CNode* next;
public :
	CNode();
	~CNode();
	int getkey() {
		return key;
	}
	void setkey(const int& key) {
		this->key = key;
	}
	CNode* getNext() {
		return next;
	}
	void setNext(CNode* next) {
		this->next = next;
	}
};

