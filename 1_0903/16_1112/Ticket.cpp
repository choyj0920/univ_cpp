#include "Ticket.h"
#include<iostream>

Ticket::Ticket():Ticket(0,0) {

}
Ticket::~Ticket() {
	std::cout << "Ticket 소멸자 실행 --티켓 번호 :" << number << std::endl;

}
Ticket::Ticket(int number, double price):number(number),price(price)
{
	
}
Ticket::Ticket(const Ticket& copy):Ticket(copy.number,copy.price) {
	
}
int Ticket::getNumber() {
	return number;
}

void Ticket:: setPrice(double price) {
	this->price = price;
}
void Ticket::show() {
	std::cout << "티켓 번호는 " << getNumber() << " 티켓 가격은 " << getPrice() << std::endl;

}