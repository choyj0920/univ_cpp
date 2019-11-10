#pragma once
#include "Ticket.h"
#include <iostream>
class GeneralTicket :
	public Ticket
{
private:

	bool payBycredit;

public:
	GeneralTicket();
	GeneralTicket(GeneralTicket& copy);
	~GeneralTicket();
	GeneralTicket(int number,double price,bool paybycredit);
	double getPrice();
	bool getPayBtCredit();
	void show();
};

