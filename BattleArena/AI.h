#pragma once
#include "Player.h"

class AI : public Player
{
public:
	AI();
	~AI();

	void Attack(int input) override;
	void Taunt() override;
	void Cheer(int input) override;
};

