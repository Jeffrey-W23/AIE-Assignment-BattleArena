#pragma once
#include "Zombies.h"
#include "Couches.h" 

class Game
{
public:
	Game();
	Game(int playertype);
	~Game();
	void MainFunction();
	void BubbleSort(Monsters** data, int count);
	void Attack(int input);
	void Taunt();
	void Cheer(int input);

private:
	Monsters** player;
	Monsters** AI;
	int playerSize;
	int AISize;
	int playerId;
};