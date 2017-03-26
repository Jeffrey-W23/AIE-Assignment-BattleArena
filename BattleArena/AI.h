//#include, using etc
#pragma once
#include "Player.h"

// AI object inheriting player
class AI : public Player
{
public:

	// Default Constructor
	AI();

	// Constructor passing in the player typ
	AI(int playertype);

	// Default Destructor
	~AI();

	// Function for Attacking
	int Attack(int input) override;

	// Function for taunting
	int Taunt() override;
};