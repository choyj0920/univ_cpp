#pragma once
class Ticket
{
private:
	int number;
	double price;
public:
	Ticket();
	~Ticket();
	Ticket(int number, double price);
	Ticket(const Ticket& copy);
	int getNumber();
	virtual double getPrice();
	void setPrice(double price);
	virtual void show();
};

