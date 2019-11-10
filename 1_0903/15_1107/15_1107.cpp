
#include <iostream>
#include "TickteManager.h"
using namespace std;
int main()
{
	GeneralTicket gt(20, 1000, true);
	gt.show();
	Ticket* tt[3];
	tt[2] = &gt;
	tt[2]->show();
	//AdvanceTicket at(20, 1000, 20);
	//at.show();
	//Ticket tt(21, 1000);
	//tt.show();
	//TickteManager tm;
	//tm.showTickets();
	//
	//GeneralTicket* tt = new GeneralTicket(22, 2000, true);
	//tm.ticketing(gt);
	//tm.ticketing(at);
	//tm.ticketing(tt);
	//tm.ticketing(new GeneralTicket(22, 2000, true));
	//tm.showTickets();
	//tm.getTotalprice();
	return 0;
}

