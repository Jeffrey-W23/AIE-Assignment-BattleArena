//#include, using etc
#pragma once
#include <iostream>
#include <conio.h>
using namespace std;

// Enums for different attack types
enum AttackType
{
	bite,
	scratch,
	sit,
	reclin,
	recliner,
	reclinerer,
};

// Monster object
class Monsters
{
public:

	// Default Constructor
	Monsters();

	// Default Destructor
	~Monsters();
	
	// Function for attacking
	virtual int Attack(AttackType attackType);
	
	// Function for applying damage to the monster
	virtual void takeDamage(int damage, int playerType);
	
	// Function for applying taunts to the monster
	virtual void lowerSanity(int damage, int playerType);
	
	// Function to taunt another monster
	virtual char* Taunts(int tauntId);
	
	// function for weather a monster is insane or not
	virtual void Insane();
	
	// declare vars
	int health;
	int sanity;
	int cheer;
	bool insane;
	int sanityMax;
};

