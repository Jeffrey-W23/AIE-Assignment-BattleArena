#pragma once
#include "Zombies.h"
#include "Couches.h" 

class Game
{
public:
	Game();
	~Game();
	void StartGame(int playertype);

private:
	Zombies* zombies[5];
	Couches* couches[3];
};

