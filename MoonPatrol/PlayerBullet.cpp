#include "PlayerBullet.h"
#include "raylib.h"

PlayerBullet CreatePlayerBullet(PlayerBullet& playerBullet)
{
	playerBullet.poisition.x = 5000;
	playerBullet.poisition.y = 5000;
	playerBullet.size.x = 10;
	playerBullet.size.y = 10;
	playerBullet.speed = 200;
	playerBullet.isActive = false;
	playerBullet.isMoving = false;
	playerBullet.bulletColor = WHITE;

	return playerBullet;
}

void DrawPlayerBullet(PlayerBullet playerBullet)
{
	DrawRectangle(playerBullet.poisition.x, playerBullet.poisition.y, playerBullet.size.x, playerBullet.size.y, playerBullet.bulletColor);
}