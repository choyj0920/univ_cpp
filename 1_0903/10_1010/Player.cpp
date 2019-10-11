#include "pch.h"
#include "Player.h"


Player::Player()
{
	total = 0;
}

Player::Player(const string name)
{
	this->name = name;
}

Player::~Player()
{
}

void Player::setName(const string & name)
{
	this->name = name;
}

string Player::getName() const
{
	return name;
}

void Player::roll(Dice & dice1, Dice & dice2)
{
	cout << name << "(이)가 주사위를 돌림\n";
	dice1.roll();
	dice2.roll();
	total = dice1.getFaceValue() + dice2.getFaceValue();
}

int Player::getTotal() const
{
	return total;
}
