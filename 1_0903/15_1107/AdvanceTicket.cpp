#include "AdvanceTicket.h"
using namespace std;

AdvanceTicket::AdvanceTicket() :AdvanceTicket(0,0,0)
{

}

AdvanceTicket::AdvanceTicket(AdvanceTicket& copy):Ticket(copy),advanceDays(copy.advanceDays)
{
}

AdvanceTicket::~AdvanceTicket()
{
}

AdvanceTicket::AdvanceTicket(int number, double price, int advanceDays):Ticket(number,price), advanceDays(advanceDays)
{
}

double AdvanceTicket::getPrice()
{
	double dd;
	if (advanceDays > 30)
		dd = 0.6;
	else if (advanceDays > 20)
		dd = 0.7;
	else if (advanceDays > 10)
		dd = 0.8;
	else if (advanceDays > 5)
		dd = 0.9;
	else
		dd = 1;
	
	return Ticket::getPrice() * dd;
}

int AdvanceTicket::getAdvanceDays()
{
	return advanceDays;
}

void AdvanceTicket::show()
{
	cout << "사전 티켓 번호는 " << getNumber() << " 티켓 가격은 " << getPrice() << endl;
}
