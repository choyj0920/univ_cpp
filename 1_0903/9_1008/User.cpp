#include "User.h"
class Lamp;
User::User()
{
}

void User::turnOnOff(Lamp& lamp)
{
	lamp.powerOnOff();
}

void User::init(const string& name, const int illu)
{
	this->name = name;
	this->iwantill = illu;
}

void User::changeLight(Lamp & lamp)
{
	lamp.changeLight();
}

int User::iwantill()
{
	return want_illum;
}


User::~User()
{
}
