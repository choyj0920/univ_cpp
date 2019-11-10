#include "TickteManager.h"

TickteManager::TickteManager()
{
	count = 0;
}

TickteManager::~TickteManager()
{
}

double TickteManager::getTotalprice()
{
	double total = 0;
	for (int i = 0; i < count; i++) {
		total += ticktes[i]->getPrice();
	}
	return total;
}

void TickteManager::showTickets()
{
	cout << "티켓 출력\n";
	for (int i = 0; i < count; i++) {
		ticktes[i]->show();
	}
	cout << "총 티켓 금액은 " << getTotalprice() << endl;
}

void TickteManager::ticketing(Ticket * ticket)
{
	ticktes[count++] = ticket;
}

void TickteManager::ticketing(Ticket& ticket)
{
	ticktes[count++] = &ticket;

}

