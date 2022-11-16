#include "Objects/Player.h"

Player CreatePlayer(int screenWidth, int screenHeight)
{
	Player player;

	player.pos.x = static_cast<float>(screenWidth / 6);
	player.pos.y = static_cast<float>(screenHeight / 1.165);

	player.width = 80;
	player.height = 40;

	player.speed = 420;

	player.gravity = 0;

	player.jumpForce = 300;

	player.lifes = 3;

	player.points = 0;

	player.isJumping = false;
	player.isCollision = false;
	player.isAlive = true;
	player.win = false;

	player.color = GREEN;

	return player;
}

void DrawPlayer(Player& player)
{
	DrawRectangle(static_cast<int>(player.pos.x),
		static_cast<int>(player.pos.y),
		static_cast<int>(player.width),
		static_cast<int>(player.height), player.color);
}

void PlayerLimit(Player& player, int screenWidth)
{
	if (player.pos.x > screenWidth - player.width)
	{
		player.pos.x = screenWidth - player.width;
	}

	if (player.pos.x < screenWidth / screenWidth)
	{
		player.pos.x = static_cast<float>(screenWidth / screenWidth);
	}
}

void LoseLife(Player& player)
{
	if (player.isCollision == true)
	{
		player.lifes -= 1;
	}
}

bool IsAlive(Player& player)
{
	if (player.lifes <= 0)
	{
		return player.isAlive == false;
	}

	else
	{
		return player.isAlive == true;
	}
}

bool PlayerWin(Player& player)
{
	if (player.points < 1500000)
	{
		return player.win == true;
	}

	else
	{
		return player.win == false;
	}
}
