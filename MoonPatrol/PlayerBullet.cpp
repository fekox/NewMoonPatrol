#include "PlayerBullet.h"
#include "raylib.h"

PlayerBullet CreatePlayerBullet(PlayerBullet& playerBullet)
{
	playerBullet.position.x = 500;
	playerBullet.position.y = 500;
	playerBullet.size.x = 20;
	playerBullet.size.y = 20;
	playerBullet.direction.x = 0;
	playerBullet.direction.y = 0;
	playerBullet.speed = 200;
	playerBullet.isActive = true;
	playerBullet.isMoving = false;
	playerBullet.bulletColor = ORANGE;

	return playerBullet;
}

void DrawPlayerBullet(PlayerBullet playerBullet)
{
	DrawRectangle(static_cast<float>(playerBullet.position.x), static_cast<float>(playerBullet.position.y), static_cast<float>(playerBullet.size.x), static_cast<float>(playerBullet.size.y), playerBullet.bulletColor);
}