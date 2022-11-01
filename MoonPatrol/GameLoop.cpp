#include "GameLoop.h"
#include "Enemy.h"
#include "Player.h"
#include "raylib.h"

static void Initialize();

static void Close();

bool CollisionRectangleRectangle(float r1x, float r1y, float r1w, float r1h, float r2x, float r2y, float r2w, float r2h);

void EnemyTp(Enemy& enemy);

void GameCollisions(Player& spaceShip, Enemy enemy);

void CheckInput(Player& spaceShip, bool& playingGame);

void RunGame()
{
	Initialize();
	HideCursor();
	SetExitKey(KEY_NULL);

	bool playingGame = true;

	Player spaceShip;

	Enemy enemy;

	CreatePlayerShip(spaceShip);
	CreateEnemy(enemy);

	while (playingGame && !WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);

		enemy.position.x += enemy.speed.x * GetFrameTime();

		CheckInput(spaceShip, playingGame);
		GameCollisions(spaceShip, enemy);
		EnemyTp(enemy);

		DrawRectangle(-10, 675, GetScreenWidth() + 20, 100, GRAY);
		if (spaceShip.isAlive)
		{
			DrawPlayerShip(spaceShip);
		}
		DrawEnemy(enemy);

		DrawText("GAME VERSION 0.1", 10, 10, 20, GREEN);

		EndDrawing();
	}

	Close();
}

static void Initialize()
{
	InitWindow(1024, 768, "MoonPatrol");
}

static void Close()
{
	CloseWindow();
}

bool CollisionRectangleRectangle(float r1x, float r1y, float r1w, float r1h, float r2x, float r2y, float r2w, float r2h)
{
	if (r1x + r1w >= r2x && r1x <= r2x + r2w && r1y + r1h >= r2y && r1y <= r2y + r2h) 
	{    
		return true;
	}
	return false;
}

void EnemyTp(Enemy& enemy)
{
	if (enemy.position.x < -50)
	{
		enemy.position.x = static_cast<float>(GetScreenWidth());
	}
}

void GameCollisions(Player& spaceShip, Enemy enemy)
{
	if (spaceShip.isAlive)
	{
		if (CollisionRectangleRectangle(spaceShip.position.x, spaceShip.position.y, spaceShip.size.x, spaceShip.size.y, enemy.position.x, enemy.position.y, enemy.size.x, enemy.size.y))
		{
			spaceShip.isAlive = false;
		}
	}
}

void CheckInput(Player& spaceShip, bool& playingGame)
{
	if (IsKeyPressed(KEY_ENTER))
	{
		playingGame = false;
	}

	if (IsKeyPressed(KEY_SPACE))
	{
		spaceShip.isJumping = !spaceShip.isJumping;

		if (spaceShip.isJumping)
		{
			spaceShip.position.y = 575;
		}
		else if(!spaceShip.isJumping)
		{
			spaceShip.position.y = 635;
		}
	}
}