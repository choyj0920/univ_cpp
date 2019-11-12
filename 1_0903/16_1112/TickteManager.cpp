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
	cout << "advancedTicket의 판매 갯수는 " << ad_count << " 총 판매 금액은 " << ad_total << "입니다" << endl;
	
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
	cout << "GeneralTicket의 판매 갯수는 " << ge_count << " 총 판매 금액은 " << ge_total << "입니다" << endl;

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
	cout << "GeneralTicket중 카드 결재의 판매 갯수는 " << ge_count << " 총 판매 금액은 " << ge_total << "입니다" << endl;

}

void TickteManager::ticketing(Ticket * ticket)
{
	ticktes[count++] = ticket;
}

void TickteManager::ticketing(Ticket& ticket)
{
	ticktes[count++] = &ticket;

}

