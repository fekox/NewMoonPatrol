#pragma once
#include "raylib.h"

struct Bullet
{
	Vector2 pos;

	float height;
	float width;

	float speed;

	bool isMoving;
	bool isActive;

	Color color;
};

Bullet CreateBullet();

void DrawBullet(Bullet& bullet);