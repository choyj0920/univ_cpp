#pragma once
#include "Ticket.h"
#include <iostream>
using namespace std;
class AdvanceTicket :public Ticket
{
private:
	int advanceDays;

public:
	AdvanceTicket();
	AdvanceTicket(AdvanceTicket&copy);
	~AdvanceTicket();
	AdvanceTicket(int number,double price,int advanceDays);
	double getPrice();
	int getAdvanceDays();
	void show();
};

