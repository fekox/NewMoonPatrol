#include "Enemy.h"
#include "raylib.h"

Enemy CreateEnemy(Enemy& enemy)
{
	enemy.position.x = 800.f;
	enemy.position.y = 635.f;
	enemy.size.x = 40.f;
	enemy.size.y = 40.f;
	enemy.speed.x = -150;
	enemy.isAlive = true;
	enemy.enemyColor = PURPLE;

	return enemy;
}

void DrawEnemy(Enemy enemy)
{
	DrawRectangle(static_cast<float>(enemy.position.x), static_cast<float>(enemy.position.y), static_cast<float>(enemy.size.x), static_cast<float>(enemy.size.y), enemy.enemyColor);
}