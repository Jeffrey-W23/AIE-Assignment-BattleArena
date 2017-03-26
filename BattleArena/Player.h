//#include, using etc
#pragma once
#include "Monsters.h"
#include "Zombies.h"
#include "Couches.h" 
#include <conio.h>
#include <ctime>
#include <iostream>
using namespace std;

// player object
class Player
{
public:

	// Default Constructor
	Player();

	// Default Destructor
	~Player();
	
	// function for attacking
	virtual int Attack(int input);
	
	// Function for taunting
	virtual int Taunt();
	
	// Function for using the cheer store
	virtual void Cheer(int input);
	
	// Bubble sort function
	virtual void BubbleSort();
	
	// Insertion sort function
	virtual void InsertionSort();

	// monster object
	Monsters** army;

	// declare vars
	int playerId;
	int monsterCount;
};