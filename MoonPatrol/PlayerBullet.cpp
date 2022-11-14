#include "PlayerBullet.h"
#include "raylib.h"

PlayerBullet CreatePlayerBullet(PlayerBullet& playerBullet)
{
	playerBullet.position.x = 5000;
	playerBullet.position.y = 5000;
	playerBullet.size.x = 10;
	playerBullet.size.y = 10;
	playerBullet.direction.x = 0;
	playerBullet.direction.y = 0;
	playerBullet.speed = 200;
	playerBullet.isActive = false;
	playerBullet.isMoving = false;
	playerBullet.bulletColor = WHITE;

	return playerBullet;
}

void DrawPlayerBullet(PlayerBullet playerBullet)
{
	DrawRectangle(playerBullet.position.x, playerBullet.position.y, playerBullet.size.x, playerBullet.size.y, playerBullet.bulletColor);
}