#pragma once
#include "raylib.h"

struct Obstacle
{
	Vector2 pos;

	float width;
	float height;

	float speed;

	Texture tex;
	Color color;
};

Obstacle CreateObstacle(int screenWidth, int screenHeight);

void DrawObstacle(Obstacle& obstacle);
