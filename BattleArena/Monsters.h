#pragma once

enum AttackType
{
	bite,
	scratch,
	sit,
	reclin,
	recliner,
	reclinerer,
};

class Monsters
{
public:
	Monsters();
	~Monsters();
	virtual int Attack(AttackType attackType);
	virtual void takeDamage(int damage);
	virtual void lowerSanity(int damage);
	virtual char* Taunts(int tauntId);
	bool Alive();

	int health;
	int sanity;
	int cheer;
	bool insane;
	int sanityMax;
};

