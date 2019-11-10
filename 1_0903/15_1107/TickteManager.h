#pragma once
#include "GeneralTicket.h"
#include "AdvanceTicket.h"
class TickteManager
{
private:
	Ticket* ticktes[10];
	std::string m_name;
	int count;
public:
	TickteManager();
	~TickteManager();
	double getTotalprice();
	void showTickets();
	void ticketing(Ticket * ticket);
	void ticketing(Ticket & ticket);
};
