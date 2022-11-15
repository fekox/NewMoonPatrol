#pragma once
#include "raylib.h"

struct Background
{
	Vector2 pos;
		
	float width;
	float height;
	float scale;

	float speed;

	Texture tex;
};

Background CreateBackground(int screenWidth, int screenHeight);
void DrawBackground(Background& back);
void BackgroundParallax(Background& back, int screenWidth);
