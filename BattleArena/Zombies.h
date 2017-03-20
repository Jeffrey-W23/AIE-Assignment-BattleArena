#pragma once
#include "Monsters.h"

enum AttackType
{
	bite,
	scratch,
	sit
};

class Zombies : public Monsters
{
public:
	Zombies();
	~Zombies();
	int Attack(AttackType attackType) override;
	void takeDamage(int damage) override;
};