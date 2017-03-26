//#include, using etc
#include "Player.h"

// Default Constructor
Player::Player()
{
}

// Default Destructor
Player::~Player()
{
}

// function for attacking
int Player::Attack(int input)
{
	return 0;
}

// Function for taunting
int Player::Taunt()
{
	return 0;
}

// Function for using the cheer store
void Player::Cheer(int input)
{

}

// Bubble sort function
void Player::BubbleSort()
{
	Monsters* temp;

	for (int i = 0; i < (monsterCount - 1); i++)
	{
		for (int j = 0; j < (monsterCount - 1); j++)
		{
			if (army[j]->health < army[j + 1]->health)
			{
				temp = army[j];
				army[j] = army[j + 1];
				army[j + 1] = temp;
			}
		}
	}
}

// Insertion sort function
void Player::InsertionSort()
{
	for (int i = 0; i < monsterCount; i++)
	{
		int index_of_min = i;

		for (int j = i; j < monsterCount; j++)
		{
			if (army[index_of_min]->health < army[j]->health)
			{
				index_of_min = j;
			}
		}

		int temp = army[i]->health;
		army[i]->health = army[index_of_min]->health;
		army[index_of_min]->health = temp;
	}
}