//#include, using etc
#pragma once
#include "Monsters.h"

// Couches object inheriting player
class Couches : public Monsters
{
public:

	// Default Constructor
	Couches();

	// Default Destructor
	~Couches();
	
	// Function for attacking
	int Attack(AttackType attackType) override;
	
	// Function for applying damage to the monster
	void takeDamage(int damage, int playerType) override;
	
	// Function for applying taunts to the monster
	void lowerSanity(int damage, int playerType) override;
	
	// Function to taunt another monster
	char* Taunts(int tauntId) override;
	
	// function for weather a monster is insane or not
	void Insane() override;
};

