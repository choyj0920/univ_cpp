#pragma once
#include "pch.h"
class User; //Lamph를 읽을 때 아직 포함되지 않은 user를 알려줌
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
	void setlamp(const User& use);
	~Lamp();
};