#pragma once
#include "Dice.h"
class Player
{
	string name;
	int total;
public:
	Player() = delete;
	Player(const string name);
	~Player();
	void setName(const string& name);
	string getName() const;
	void roll(Dice& dice1, Dice& dice2);
	int getTotal() const;
};