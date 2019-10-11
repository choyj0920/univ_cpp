#pragma once
#include "User.h"
#include <iostream>
using namespace std;
class Lamp
{
private:
	bool isOn;
	int illuminate;
public:
	Lamp();
	void powerOnOff();
	void changeLight();
	void show();
	void setlamp(User use);
	~Lamp();
};