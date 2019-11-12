
#include <iostream>
#include "TickteManager.h"
using namespace std;
int main()
{
	cout << "7조 : 송재원, 조윤직,양석준, 박진영" << endl;
	TickteManager tm;
	tm.showTickets();

	GeneralTicket* tt = new GeneralTicket(20, 2000, true);
	tm.ticketing(tt);

	tm.ticketing(new GeneralTicket(21, 1000, false));
	tm.ticketing(new GeneralTicket(22, 2000, true));
	tm.ticketing(new AdvanceTicket(23, 1000, 30));
	tm.ticketing(new AdvanceTicket(24, 1000, 30));
	tm.showTickets();

	tm.showAdvanceTicket();
	tm.showGeneralTicket();
	tm.showGeneral_creditTicket();




	return 0;
}

