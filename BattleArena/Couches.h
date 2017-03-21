#pragma once
#include "Monsters.h"

class Couches : public Monsters
{
public:
	Couches();
	~Couches();
	int Attack(AttackType attackType) override;
	void takeDamage(int damage) override;
};

