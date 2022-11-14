#pragma once
#include "raylib.h"

struct PlayerBullet
{
	Vector2 poisition{};
	Vector2 size{};
	float speed;
	bool isMoving;
	bool isActive;
	Color bulletColor;
};

PlayerBullet CreatePlayerBullet(PlayerBullet& playerBullet);

void DrawPlayerBullet(PlayerBullet playerBullet);