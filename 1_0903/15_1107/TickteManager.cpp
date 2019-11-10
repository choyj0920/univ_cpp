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
	cout << "Ƽ�� ���\n";
	for (int i = 0; i < count; i++) {
		ticktes[i]->show();
	}
	cout << "�� Ƽ�� �ݾ��� " << getTotalprice() << endl;
}

void TickteManager::ticketing(Ticket * ticket)
{
	ticktes[count++] = ticket;
}

void TickteManager::ticketing(Ticket& ticket)
{
	ticktes[count++] = &ticket;

}

