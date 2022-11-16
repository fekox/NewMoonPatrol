#include "Objects/FlyEnemy.h"

FlyEnemy CreateFlyEnemy()
{
	FlyEnemy flyEnemy;

	flyEnemy.pos.x = 0;
	flyEnemy.pos.y = 0;

	flyEnemy.width = 60;
	flyEnemy.height = 60;

	flyEnemy.speed = 40;

	flyEnemy.life = 2;

	flyEnemy.moveDown = false;
	flyEnemy.isActive = true;
	flyEnemy.isMoving = true;

	flyEnemy.color = ORANGE;

	return flyEnemy;
}

void DrawFlyEnemy(FlyEnemy& flyEnemy)
{
	DrawRectangle(static_cast<int>(flyEnemy.pos.x), static_cast<int>(flyEnemy.pos.y), static_cast<int>(flyEnemy.width), static_cast<int>(flyEnemy.height), flyEnemy.color);
}