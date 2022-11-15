#include "Objects/Player.h"
#include "raylib.h"

Player CreatePlayerShip(Player& spaceShip)
{
	spaceShip.position.x = 70.0f;
	spaceShip.position.y = 635.0f;
	spaceShip.size.x = 40.f;
	spaceShip.size.y = 40.f;
	spaceShip.speed.x = 200;
	spaceShip.maxHeightJump = 520.0f;
	spaceShip.startJumpPosition = 635.0f;
	spaceShip.gravity = 175.0f;
	spaceShip.jumpTimer = 0;
	spaceShip.score = 0;
	spaceShip.isAlive = true;
	spaceShip.isJumping = false;
	spaceShip.playerColor = YELLOW;

	return spaceShip;
}

void DrawPlayerShip(Player spaceShip)
{
	DrawRectangle(static_cast<float>(spaceShip.position.x), static_cast<float>(spaceShip.position.y), static_cast<float>(spaceShip.size.x), static_cast<float>(spaceShip.size.y), spaceShip.playerColor);
}