#pragma once
#include "Player.h"

class Human : public Player
{
public:
	Human();
	Human(int playertype);
	~Human();
	virtual int Attack(int input);
	virtual int Taunt();
	virtual void Cheer(int input);
};