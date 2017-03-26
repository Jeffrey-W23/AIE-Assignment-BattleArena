//#include, using etc
#pragma once
#include "Player.h"

// Human object inheriting player
class Human : public Player
{
public:
	// Default Constructor
	Human();

	// Constructor passing in the player type
	Human(int playertype);
	
	// Default Destructor
	~Human();

	// Function for attacking
	int Attack(int input) override;
	
	// Function for taunting
	int Taunt() override;
	
	// function for using the cheer store
	void Cheer(int input) override;
};