#pragma once
#include "raylib.h"

struct FlyEnemy
{
	Vector2 pos;
	
	float width;
	float height;

	float speed;

	int life;

	bool moveDown;
	bool isMoving;
	bool isActive;

	Texture tex;
	Color color;
};

FlyEnemy CreateFlyEnemy();

void DrawFlyEnemy(FlyEnemy& flyEnemy);