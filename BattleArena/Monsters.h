#pragma once

enum AttackType
{
};

class Monsters
{
public:
	Monsters();
	~Monsters();
	virtual int Attack(AttackType attackType);
	virtual void takeDamage(int damage);
	bool Alive();

	int health;
	int sanity;
	int cheer;
};

