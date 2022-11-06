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
	enemy.enemyColor = RED;

	return enemy;
}

void DrawEnemy(Enemy enemy)
{
	DrawRectangle(enemy.position.x, enemy.position.y, enemy.size.x, enemy.size.y, enemy.enemyColor);
}