#include <iostream>
#include "Objects/Obstacle.h"

Obstacle CreateObstacle(int screenWidth, int screenHeight)
{
	Obstacle obstacle;

	obstacle.pos.x = static_cast<float>(screenWidth - 30);
	obstacle.pos.y = static_cast<float>(screenHeight / 1.25);

	obstacle.width = 60;
	obstacle.height = 100;

	obstacle.speed = 400;

	obstacle.tex = LoadTexture("resources/Sprites/EvilPingu.png");
	obstacle.color = WHITE;

	return obstacle;
}

void DrawObstacle(Obstacle& obstacle)
{
	DrawRectangle(static_cast<int>(obstacle.pos.x), static_cast<int>(obstacle.pos.y), static_cast<int>(obstacle.width), static_cast<int>(obstacle.height), BLANK);
	DrawTexture(obstacle.tex, static_cast<int>(obstacle.pos.x), static_cast<int>(obstacle.pos.y), obstacle.color);
}
