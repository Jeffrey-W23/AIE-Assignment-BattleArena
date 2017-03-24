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
	void Insane(); // add to player and ai
	bool Alive(); // add to player and ai

	int health;
	int sanity;
	int cheer;
	bool insane;
	int sanityMax;
};

