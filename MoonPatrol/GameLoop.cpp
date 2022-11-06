#include "GameLoop.h"
#include "Enemy.h"
#include "Player.h"
#include "raylib.h"
#include <iostream>

static void Initialize();

static void Close();

bool CollisionRectangleRectangle(float r1x, float r1y, float r1w, float r1h, float r2x, float r2y, float r2w, float r2h);

void EnemyTp(Enemy& enemy);

void GameCollisions(Player& spaceShip, Enemy enemy);

void CheckInput(Player& spaceShip, bool& playingGame);

void RunGame()
{
	Initialize();
	//HideCursor();
	SetExitKey(KEY_NULL);

	bool playingGame = true;

	GameState gameState = GameState::CREDITS;
	
	Player spaceShip;

	Enemy enemy;

	CreatePlayerShip(spaceShip);
	CreateEnemy(enemy);

	Vector2 mousePosition = GetMousePosition();

	while (playingGame && !WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);

		switch (gameState)
		{
		case GameState::GAMETITLE:

			mousePosition = GetMousePosition();

			break;
		case GameState::GAME:

			mousePosition = GetMousePosition();

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

			break;
		case GameState::HOWTOPLAY:

			mousePosition = GetMousePosition();

			if (CheckCollisionPointRec(mousePosition, { 10, 40, 45, 45 }))
			{
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
				{
					gameState = GameState::GAMETITLE;
				}
			}

			DrawRectangle(10, 40, 45, 45, RED);
			DrawText("x", 20, 35, 50, WHITE);

			break;
		case GameState::CREDITS:

			mousePosition = GetMousePosition();

			if (CheckCollisionPointRec(mousePosition, { static_cast<float>(GetScreenWidth() / 2) - 87.5f, static_cast<float>(GetScreenHeight() / 2) - 20, 190, 85 }))
			{
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					OpenURL("https://nicorm.itch.io/"); 
				}
			}

			if (CheckCollisionPointRec(mousePosition, { 10, 40, 45, 45 }))
			{
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
				{
					gameState = GameState::GAMETITLE;
				}
			}

			DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), PINK);

			DrawRectangle(10, 40, 45, 45, RED);
			DrawText("x", 20, 35, 50, WHITE);

			DrawRectangle(static_cast<float>(GetScreenWidth() / 2) - 0 - 87.5f, static_cast<float>(GetScreenHeight() / 2) - 20, 190, 85, BLACK);
			DrawRectangle(static_cast<float>(GetScreenWidth() / 2) - 0 - 82.5f, static_cast<float>(GetScreenHeight() / 2) - 15, 180, 75, RED);
			DrawText("Itch.io", static_cast<float>(GetScreenWidth() / 2) - MeasureText("Itch.io", 25), static_cast<float>(GetScreenHeight() / 2), 50, BLACK);
			DrawRectangle(250, GetScreenHeight() / 2 - 115, 550, 85, BLACK);
			DrawRectangle(255, GetScreenHeight() / 2 - 110, 540, 75, WHITE);
			DrawText("Nicolas Ramos Marin", static_cast<float>(GetScreenWidth() / 2) - MeasureText("Nicolas Ramos Marin", 25), static_cast<float>(GetScreenHeight() / 2) - 100, 50, BLACK);

			break;
		case GameState::EXIT:

			playingGame = false;

			break;
		}

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

	if (IsKeyDown(KEY_D))
	{
		if (spaceShip.position.x <= 400)
		{
			spaceShip.position.x += spaceShip.speed.x * GetFrameTime();
		}
	}

	if (IsKeyDown(KEY_A))
	{
		if (spaceShip.position.x >= 0)
		{
			spaceShip.position.x -= spaceShip.speed.x * GetFrameTime();
		}
	}
}