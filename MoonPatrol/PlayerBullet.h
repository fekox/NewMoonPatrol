#pragma once
#include "raylib.h"

struct PlayerBullet
{
	Vector2 position{};
	Vector2 size{};
	Vector2 direction{};
	float speed;
	bool isMoving;
	bool isActive;
	Color bulletColor;
};

PlayerBullet CreatePlayerBullet(PlayerBullet& playerBullet);

void DrawPlayerBullet(PlayerBullet playerBullet);