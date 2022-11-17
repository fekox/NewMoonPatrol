#include <iostream>
#include "Objects/Obstacle.h"

Obstacle CreateObstacle(int screenWidth, int screenHeight)
{
	Obstacle obstacle;

	obstacle.pos.x = static_cast<float>(screenWidth - 30);
	obstacle.pos.y = static_cast<float>(screenHeight / 1.2);

	obstacle.width = 30;
	obstacle.height = 60;

	obstacle.speed = 400;

	obstacle.color = BLUE;

	return obstacle;
}

void DrawObstacle(Obstacle& obstacle)
{
	DrawRectangle(static_cast<int>(obstacle.pos.x), static_cast<int>(obstacle.pos.y), static_cast<int>(obstacle.width), static_cast<int>(obstacle.height), obstacle.color);
}
