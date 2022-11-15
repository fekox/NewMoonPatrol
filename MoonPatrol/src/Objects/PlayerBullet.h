#pragma once
#include "Player.h"
#include "raylib.h"

const int maxPlayerBullets = 20;

struct PlayerBullet
{
	Vector2 position{};
	Vector2 size{};
	float speed;
	bool isActive;
	Color bulletColor;
};

PlayerBullet CreatePlayerBullet(PlayerBullet playerBullet, Player spaceShip);

void DrawPlayerBullet(PlayerBullet playerBullet);