#pragma once
#include "Monsters.h"
#include "Zombies.h"
#include "Couches.h" 
#include <conio.h>
#include <ctime>
#include <iostream>
using namespace std;

class Player
{
public:
	Player();
	~Player();
	virtual int Attack(int input);
	virtual int Taunt();
	virtual void Cheer(int input);
	virtual void BubbleSort();

	Monsters** army;
	int playerId;
	int monsterCount;
};