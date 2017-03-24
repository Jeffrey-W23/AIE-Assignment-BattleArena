#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

int Player::Attack(int input)
{
	return 0;
}

int Player::Taunt()
{
	return 0;
}

void Player::Cheer(int input)
{

}

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