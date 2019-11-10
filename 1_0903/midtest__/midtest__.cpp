#include "..\15_1107\Ticket.h"

#include <iostream>
#include <string>
using namespace std;
int main()
{
    std::cout << "201810754 조윤직!\n";
}

class User {
	string id, pw;
	User(){

	}
	User(string id, string pw) {

	}
};

class Ticket{
	string title;
	double price;
	string fname;
	int** map;
	User** user;
	Ticket() {

	}
	Ticket::~Ticket()
	{
	}
	Ticket(string _title, double _price, string _fname) {
		this->fname = _fname;
		this->title = _title;
		this -> price = _price;
		int height, width;
		ifstream rin(fname);
		cin >> width >> height;

	}
	void showseats() {
		for(int i=0; i)
	}
	void reserve() {
		
	}
};