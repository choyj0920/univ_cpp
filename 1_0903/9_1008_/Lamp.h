#pragma once
#include "pch.h"
class User; //Lamph�� ���� �� ���� ���Ե��� ���� user�� �˷���
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