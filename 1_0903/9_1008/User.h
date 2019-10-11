#pragma once
#include <iostream>
#include <string>
#include "Lamp.h"
using namespace std;
class User
{
private:
	string name;
	int want_illum;
public:
	User();
	void turnOnOff(Lamp& lamp);
	void init(const string& name,const int);
	void changeLight(Lamp& lamp);
	int iwantill();
	
	~User();
};

