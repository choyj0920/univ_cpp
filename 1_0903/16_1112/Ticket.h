#pragma once
class Ticket
{
private:
	
protected:
	int number;
	double price;
public:
	Ticket();
	virtual ~Ticket();
	Ticket(int number, double price);
	Ticket(const Ticket& copy);
	int getNumber();
	virtual double getPrice() = 0;
	void setPrice(double price);
	virtual void show();
};

