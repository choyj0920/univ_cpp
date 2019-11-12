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

void TickteManager::showAdvanceTicket()
{
	double ad_total = 0;
	int ad_count = 0;
	for (int i = 0; i < count; i++) {
		if (typeid(*ticktes[i]).name() == typeid(AdvanceTicket).name()) {

			ad_count++;
			ad_total += ticktes[i]->getPrice();
			
		}
	}
	cout << "advancedTicket�� �Ǹ� ������ " << ad_count << " �� �Ǹ� �ݾ��� " << ad_total << "�Դϴ�" << endl;
	
}

void TickteManager::showGeneralTicket()
{
	double ge_total = 0;
	int ge_count = 0;
	for (int i = 0; i < count; i++) {
		if (typeid(*ticktes[i]).name() == typeid(GeneralTicket).name()) {
			
			ge_count++;
			ge_total += ticktes[i]->getPrice();

		}
	}
	cout << "GeneralTicket�� �Ǹ� ������ " << ge_count << " �� �Ǹ� �ݾ��� " << ge_total << "�Դϴ�" << endl;

}

void TickteManager::showGeneral_creditTicket()
{
	double ge_total = 0;
	int ge_count = 0;
	for (int i = 0; i < count; i++) {
		if (typeid(*ticktes[i]).name() == typeid(GeneralTicket).name()) {
			GeneralTicket* gt = (GeneralTicket*)ticktes[i];
			if (gt->getPayBtCredit()) {
				ge_count++;
				ge_total += ticktes[i]->getPrice(); 
			}
		}
	}
	cout << "GeneralTicket�� ī�� ������ �Ǹ� ������ " << ge_count << " �� �Ǹ� �ݾ��� " << ge_total << "�Դϴ�" << endl;

}

void TickteManager::ticketing(Ticket * ticket)
{
	ticktes[count++] = ticket;
}

void TickteManager::ticketing(Ticket& ticket)
{
	ticktes[count++] = &ticket;

}

