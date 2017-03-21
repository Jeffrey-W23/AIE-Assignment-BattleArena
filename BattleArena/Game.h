#pragma once
#include "Zombies.h"
#include "Couches.h" 

class Game
{
public:
	Game();
	Game(int playertype);
	~Game();
	void StartGame();
	void BubbleSort(Monsters** data, int count);

private:
	Monsters** player;
	Monsters** AI;
	int playerSize;
	int AISize;
};