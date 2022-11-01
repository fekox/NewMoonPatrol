#pragma once
#include "raylib.h"

struct Player
{
	Vector2 position{};
	Vector2 size;
	Vector2 speed{};
	bool isJumping;
	bool isAlive;
	Color playerColor;
};

Player CreatePlayerShip(Player& spaceShip);

void DrawPlayerShip(Player spaceShip);