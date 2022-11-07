#pragma once
#include "raylib.h"

struct Player
{
	Vector2 position{};
	Vector2 size;
	Vector2 speed{};
	float startJumpPosition;
	float maxHeightJump;
	float gravity;
	float jumpTimer;
	bool isJumping;
	bool isAlive;
	Color playerColor;
};

Player CreatePlayerShip(Player& spaceShip);

void DrawPlayerShip(Player spaceShip);