#pragma once
#include "raylib.h"

const int maxFlyingEnemy = 5;

struct Enemy
{
	Vector2 position{};
	Vector2 size;
	Vector2 speed{};
	bool isAlive;
	Color color;
};

Enemy CreateEnemy(Enemy& enemy);

Enemy CreateFlyingEnemy(Enemy& enemy, float x);

void DrawEnemy(Enemy enemy);