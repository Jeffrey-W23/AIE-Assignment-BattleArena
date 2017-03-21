#pragma once
#include "Monsters.h"

class Zombies : public Monsters
{
public:
	Zombies();
	~Zombies();
	int Attack(AttackType attackType) override;
	void takeDamage(int damage) override;
};