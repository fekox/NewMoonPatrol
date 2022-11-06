#include "Player.h"
#include "raylib.h"

Player CreatePlayerShip(Player& spaceShip)
{
	spaceShip.position.x = 70.f;
	spaceShip.position.y = 635.f;
	spaceShip.size.x = 40.f;
	spaceShip.size.y = 40.f;
	spaceShip.speed.x = 200;
	spaceShip.speed.y = 200;
	spaceShip.isAlive = true;
	spaceShip.playerColor = YELLOW;

	return spaceShip;
}

void DrawPlayerShip(Player spaceShip)
{
	DrawRectangle(spaceShip.position.x, spaceShip.position.y, spaceShip.size.x, spaceShip.size.y, spaceShip.playerColor);
}