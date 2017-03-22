#pragma once
#include "Monsters.h"

class Zombies : public Monsters
{
public:
	Zombies();
	~Zombies();
	int Attack(AttackType attackType) override;
	void takeDamage(int damage) override;
	void lowerSanity(int damage) override;
	char* Taunts(int tauntId) override;
};