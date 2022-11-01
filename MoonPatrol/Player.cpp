#include "Player.h"
#include "raylib.h"

Player CreatePlayerShip(Player& spaceShip)
{
	spaceShip.position.x = 70;
	spaceShip.position.y = 635;
	spaceShip.size.x = 40;
	spaceShip.size.y = 40;
	spaceShip.isAlive = true;
	spaceShip.playerColor = YELLOW;

	return spaceShip;
}

void DrawPlayerShip(Player spaceShip)
{
	DrawRectangle(spaceShip.position.x, spaceShip.position.y, spaceShip.size.x, spaceShip.size.y, spaceShip.playerColor);
}