#pragma once
#include "Zombies.h"
#include "Couches.h" 
#include "Player.h"
#include "Human.h"

class Game
{
public:
	Game();
	Game(int playertype);
	~Game();
	void MainFunction();

private:
	Human* human;
};