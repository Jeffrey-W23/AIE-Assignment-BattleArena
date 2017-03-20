#pragma once
#include "Monsters.h"

enum AttackType
{
	reclin,
	recliner,
	reclinerer,
};

class Couches : public Monsters
{
public:
	Couches();
	~Couches();
	int Attack(AttackType attackType) override;
	void takeDamage(int damage) override;
};

