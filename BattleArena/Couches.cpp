#include "Couches.h"
#include <iostream>
#include <conio.h>
using namespace std;

Couches::Couches()
{
	health = 250;
	sanity = 150;
	sanityMax = 150;
}

Couches::~Couches()
{
}

int Couches::Attack(AttackType attackType)
{
	if (attackType == reclin)
	{
		return 5;
	}
	else if (attackType == recliner)
	{
		return 15;
	}
	else if (attackType == reclinerer)
	{
		return 100;
	}
	else
	{
		return 0;
	}
}

void Couches::takeDamage(int damage)
{
	health -= damage;

	cout << "   The couch has " << health << " remaining." << endl;

	if (health < 0)
	{
		health = 0;
	}

	_getch();
}

void Couches::lowerSanity(int damage)
{
	sanity -= damage;

	if (sanity < 100 && sanity > 20)
	{
		cout << endl << "   You see a tear forming under their eye.." << endl;
	}

	else if (sanity < 20 && sanity > 0)
	{
		cout << endl << "   You really seem to be getting to them now.. starting to cry a little.." << endl;
	}

	if (sanity < 0)
	{
		sanity = 0;
		insane = true;
	}

	_getch();
}

char* Couches::Taunts(int tauntId)
{
	return "";
}