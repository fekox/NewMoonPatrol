#pragma once
#include "raylib.h"

struct Enemy
{
	Vector2 position{};
	Vector2 size;
	Vector2 speed{};
	bool isAlive;
	Color enemyColor;
};

Enemy CreateEnemy(Enemy& enemy);

void DrawEnemy(Enemy enemy);