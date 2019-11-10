#include "GeneralTicket.h"
using namespace std;
GeneralTicket::GeneralTicket() :GeneralTicket(0, 0, false)
{

}

GeneralTicket::GeneralTicket(GeneralTicket& copy):Ticket(copy),payBycredit(copy.payBycredit)
{
}

GeneralTicket::~GeneralTicket()
{
}

GeneralTicket::GeneralTicket(int number, double price, bool paybycredit) :Ticket(number, price),payBycredit(paybycredit)
{

}

double GeneralTicket::getPrice()
{
	return Ticket::getPrice()* (payBycredit ? 1.1 : 1);
}

bool GeneralTicket::getPayBtCredit()
{
	return payBycredit;
}

void GeneralTicket::show()
{
	cout << "�Ϲ� Ƽ�� ��ȣ�� " << getNumber() << " Ƽ�� ������ " << getPrice() << endl;

}
