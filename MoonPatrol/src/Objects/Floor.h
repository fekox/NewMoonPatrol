#pragma once
#include "raylib.h"

struct Ground
{
	Vector2 pos;

	float width;
	float height;

	Texture tex;

	Color color;
};

Ground CreateGround(int screenWidth, int screenHeight);

void DrawGround(Ground& ground);
