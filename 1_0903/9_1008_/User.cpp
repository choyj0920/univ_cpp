#include "pch.h"
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
	this->want_illum= illu;
}

void User::changeLight(Lamp & lamp)
{
	lamp.changeLight();
}

int User::iwantill() const
{
	return want_illum;
}


User::~User()
{
}
