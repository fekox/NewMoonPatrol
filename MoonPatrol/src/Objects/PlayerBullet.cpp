#include "Objects/PlayerBullet.h"

Bullet CreateBullet()
{
	Bullet bullet;

	bullet.pos.x = 0;
	bullet.pos.y = 0;

	bullet.width = 10;
	bullet.height = 10;

	bullet.speed = 200;

	bullet.isActive = false;
	bullet.isMoving = false;

	bullet.color = YELLOW;

	return bullet;
}

void DrawBullet(Bullet& bullet)
{
	DrawRectangle(static_cast<int>(bullet.pos.x), static_cast<int>(bullet.pos.y), static_cast<int>(bullet.width), static_cast<int>(bullet.height), bullet.color);
}