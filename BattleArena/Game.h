//#include, using etc
#pragma once
#include "Zombies.h"
#include "Couches.h" 
#include "Player.h"
#include "Human.h"
#include "AI.h"

// game object
class Game
{
public:
	
	// Default Constructor
	Game();

	//  Constructor passing in the player type
	Game(int playertype);

	// Default Destructor
	~Game();

	// main game function
	void MainFunction();

	// function for checking if a team member is insane
	void CheckInsane();
	
	// display health function
	void ShowHealth();
	
	// Function to check if someone has won
	bool CheckWin();
	
	// Run the players turn
	void PlayerTurn(int input);
	
	// Run the AI teams turn
	void AITurn();

private:

	// Player and AI objects
	Human* human;
	AI* ai;
};