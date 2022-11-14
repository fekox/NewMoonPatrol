#include "Player.h"
#include "PlayerBullet.h"
#include "raylib.h"

PlayerBullet CreatePlayerBullet(PlayerBullet playerBullet, Player spaceShip)
{
	playerBullet.position.x = spaceShip.position.x + 10;
	playerBullet.position.y = spaceShip.position.y;
	playerBullet.size.x = 20;
	playerBullet.size.y = 20;
	playerBullet.speed = 500;
	playerBullet.isActive = true;
	playerBullet.bulletColor = ORANGE;

	return playerBullet;
}

void DrawPlayerBullet(PlayerBullet playerBullet)
{
	DrawRectangle(static_cast<float>(playerBullet.position.x), static_cast<float>(playerBullet.position.y), static_cast<float>(playerBullet.size.x), static_cast<float>(playerBullet.size.y), playerBullet.bulletColor);
}