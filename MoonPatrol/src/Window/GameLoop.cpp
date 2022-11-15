#include <iostream>

#include "raylib.h"

#include "Window/GameLoop.h"
#include "Window/Parallax.h"

#include "Objects/Player.h"
#include "Objects/PlayerBullet.h"
#include "Objects/Enemy.h"

using namespace std;

PlayerBullet playerBullets;
PlayerBullet maximumPlayerBullets[maxPlayerBullets];
int currentPlayerBullet = 0;

Enemy flyingEnemy;
Enemy maximumFlyingEnemy[maxFlyingEnemy];
int currentFlyingEnemy = 0;

static void Initialize();

static void Close();

void ParallaxBG(Parallax& parallax);

bool CollisionRectangleRectangle(float r1x, float r1y, float r1w, float r1h, float r2x, float r2y, float r2w, float r2h);

void EnemyTp(Enemy& enemy, Player& spaceShip);

void GameCollisions(Player& spaceShip, Enemy& enemy, PlayerBullet& playerBullet);

void CheckInput(Player& spaceShip, bool& playingGame, PlayerBullet& playerBullet);

void EnemyMovement(Enemy& enemy);

void GameDraw(bool exitWindow, Player& spaceShip, const Enemy& enemy, Parallax& parallax, PlayerBullet& playerBullet);

void RunGame()
{
	Initialize();
	//HideCursor();
	SetExitKey(KEY_NULL);
	
	bool playingGame = true;
	bool isPaused = false;
	bool exitWindow = false;
	bool gameFinished = false;

	GameState gameState = GameState::GAMETITLE;
	
	Player spaceShip;

	PlayerBullet playerBullet;

	Enemy enemy;

	Parallax parallax;

	CreateParallax(parallax);
	CreatePlayerShip(spaceShip);
	CreateEnemy(enemy);
	
	for (int i = 0; i < maxFlyingEnemy; i++)
	{
		maximumFlyingEnemy[i] = CreateFlyingEnemy(flyingEnemy, i * 100);
	}

	Vector2 mousePosition = GetMousePosition();

	while (playingGame && !WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);

		switch (gameState)
		{
		case GameState::GAMETITLE:

			mousePosition = GetMousePosition();

			if (CheckCollisionPointRec(mousePosition, { static_cast<float>(GetScreenWidth() / 2) - 150 / 2, 200, 150, 50 }))
			{
				if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
				{
					gameState = GameState::GAME;
				}
			}

			if (CheckCollisionPointRec(mousePosition, { static_cast<float>(GetScreenWidth() / 2) - (375 / 2) + 5, 275, 375, 50 }))
			{
				if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
				{
					gameState = GameState::HOWTOPLAY;
				}
			}

			if (CheckCollisionPointRec(mousePosition, { static_cast<float>(GetScreenWidth() / 2) - (250 / 2), 350, 250, 50 }))
			{
				if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
				{
					gameState = GameState::CREDITS;
				}
			}

			if (CheckCollisionPointRec(mousePosition, { static_cast<float>(GetScreenWidth() / 2) - (150 / 2), 425, 150, 150 }))
			{
				if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
				{
					gameState = GameState::EXIT;
				}
			}

			DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), WHITE);

			DrawRectangle(GetScreenWidth() / 2 - (150 / 2), 197.5f, 150, 50, BLACK);
			DrawText("PLAY", GetScreenWidth() / 2 - 50 - 15, 200, 50, WHITE);

			DrawRectangle(GetScreenWidth() / 2 - (375 / 2) + 5, 272.5f, 375, 50, BLACK);
			DrawText("HOW TO PLAY", GetScreenWidth() / 2 - 50 - 125, 275, 50, WHITE);

			DrawRectangle(GetScreenWidth() / 2 - (250 / 2), 347.5f, 250, 50, BLACK);
			DrawText("CREDITS", GetScreenWidth() / 2 - 50 - 65, 350, 50, WHITE);

			DrawRectangle(GetScreenWidth() / 2 - (150 / 2), 422.5f, 150, 50, BLACK);
			DrawText("EXIT", GetScreenWidth() / 2 - 50 - 10, 425, 50, WHITE);

			break;

		case GameState::GAME:

			mousePosition = GetMousePosition();

			if (!isPaused && spaceShip.isAlive)
			{
				CheckInput(spaceShip, playingGame, playerBullet);
				GameCollisions(spaceShip, enemy, playerBullet);
				EnemyTp(enemy, spaceShip);
				ParallaxBG(parallax);
				EnemyMovement(enemy);

				for (int i = 0; i < maxPlayerBullets; i++)
				{
					if (maximumPlayerBullets[i].isActive)
					{
						maximumPlayerBullets[i].position.y -= maximumPlayerBullets[i].speed * GetFrameTime();
					}
				}
			}
			
			if (IsKeyPressed(KEY_ESCAPE) && !gameFinished)
			{
				isPaused = true;
				exitWindow = true;
			}

			if (exitWindow)
			{
				if (CheckCollisionPointRec(mousePosition, { 350, 425, 150, 100 }))
				{
					if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
					{
						exitWindow = false;
						isPaused = !isPaused;
					}
				}
				if (CheckCollisionPointRec(mousePosition, { 530, 425, 150, 100 }))
				{
					if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
					{
						gameState = GameState::GAMETITLE;

						exitWindow = false;
						isPaused = !isPaused;
					}
				}
			}

			if (!spaceShip.isAlive)
			{
				if (CheckCollisionPointRec(mousePosition, { 350, 425, 150, 100 }))
				{
					if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
					{
						gameState = GameState::GAMETITLE;

						spaceShip.isAlive;
					}
				}
				if (CheckCollisionPointRec(mousePosition, { 530, 425, 150, 100 }))
				{
					if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
					{
						gameState = GameState::EXIT;
					}
				}
			}

			GameDraw(exitWindow, spaceShip, enemy, parallax, playerBullet);

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

		DrawText("GAME VERSION 0.3", 10, 10, 20, GREEN);

		EndDrawing();
	}

	Close();
}

void GameDraw(bool exitWindow, Player& spaceShip, const Enemy& enemy, Parallax& parallax, PlayerBullet& playerBullet)
{
	DrawText("Press 'ESC' to pause the game", static_cast<float>(GetScreenWidth() / 2) - 270, 10, 35, WHITE);

	DrawParallax(parallax);

	if (exitWindow)
	{
		DrawRectangleRounded({ static_cast<float>(GetScreenWidth() / 2) - 250, static_cast<float>(GetScreenHeight() / 2) - 200, 500, 400 }, 0.5f, 1, BLACK);
		DrawRectangleRounded({ static_cast<float>(GetScreenWidth() / 2) - 245, static_cast<float>(GetScreenHeight() / 2) - 195, 490, 390 }, 0.5f, 1, WHITE);

		DrawText("Do you want to", static_cast<float>(GetScreenWidth() - 705), static_cast<float>(GetScreenHeight() / 2) - 150, 51.5f, BLACK);
		DrawText("keep playing?", static_cast<float>(GetScreenWidth() - 685), static_cast<float>(GetScreenHeight() / 2) - 80, 51.5f, BLACK);

		DrawRectangleRounded({ 350, 425, 150, 100 }, 0.5f, 1, BLACK);
		DrawRectangleRounded({ 355, 430, 140, 90 }, 0.5f, 1, WHITE);

		DrawText("YES", 390, 460, 35, BLACK);

		DrawRectangleRounded({ 530, 425, 150, 100 }, 0.5f, 1, BLACK);
		DrawRectangleRounded({ 535, 430, 140, 90 }, 0.5f, 1, WHITE);

		DrawText("NO", 580, 460, 35, BLACK);
	}

	if (spaceShip.isAlive)
	{
		for (int i = 0; i < maxPlayerBullets; i++)
		{
			if (maximumPlayerBullets[i].isActive)
			{
				DrawPlayerBullet(maximumPlayerBullets[i]);
			}
		}

		DrawPlayerShip(spaceShip);
	}

	DrawEnemy(enemy);
	
	for (int i = 0; i < maxFlyingEnemy; i++)
	{
		if (maximumFlyingEnemy[i].isAlive)
		{
			DrawEnemy(maximumFlyingEnemy[i]);
		}
	}

	DrawText(TextFormat("score: %i", spaceShip.score), 50, 50, 50, BLACK);

	if (!spaceShip.isAlive)
	{
		DrawRectangleRounded({ static_cast<float>(GetScreenWidth() / 2) - 250, static_cast<float>(GetScreenHeight() / 2) - 200, 500, 400 }, 0.5f, 1, BLACK);
		DrawRectangleRounded({ static_cast<float>(GetScreenWidth() / 2) - 245, static_cast<float>(GetScreenHeight() / 2) - 195, 490, 390 }, 0.5f, 1, WHITE);

		DrawText("GAME OVER", static_cast<float>(GetScreenWidth() - 650), static_cast<float>(GetScreenHeight() / 2) - 150, 50, BLACK);
		DrawText(TextFormat("SCORE: %i", spaceShip.score), static_cast<float>(GetScreenWidth() - 600), static_cast<float>(GetScreenHeight() / 2) - 90, 40, BLACK);

		DrawText("Do you want to", static_cast<float>(GetScreenWidth() - 620), static_cast<float>(GetScreenHeight() / 2) - 30, 30, BLACK);
		DrawText("keep playing?", static_cast<float>(GetScreenWidth() - 610), static_cast<float>(GetScreenHeight() / 2), 30, BLACK);

		DrawRectangleRounded({ 350, 425, 150, 100 }, 0.5f, 1, BLACK);
		DrawRectangleRounded({ 355, 430, 140, 90 }, 0.5f, 1, WHITE);

		DrawText("MAIN", 380, 440, 35, BLACK);
		DrawText("MENU", 375, 480, 35, BLACK);

		DrawRectangleRounded({ 530, 425, 150, 100 }, 0.5f, 1, BLACK);
		DrawRectangleRounded({ 535, 430, 140, 90 }, 0.5f, 1, WHITE);

		DrawText("EXIT", 565, 460, 35, BLACK);
	}
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

void EnemyMovement(Enemy& enemy)
{
	enemy.position.x += enemy.speed.x * GetFrameTime();

	for (int i = 0; i < maxFlyingEnemy; i++)
	{
		maximumFlyingEnemy[i].position.x += maximumFlyingEnemy[i].speed.x * GetFrameTime();
		maximumFlyingEnemy[i].position.y -= maximumFlyingEnemy[i].speed.y * GetFrameTime();

		if (maximumFlyingEnemy[i].position.y <= 200)
		{
			maximumFlyingEnemy[i].speed.y *= -1;
		}
		else if (maximumFlyingEnemy[i].position.y >= 400)
		{
			maximumFlyingEnemy[i].speed.y *= -1;
		}
	}
}

void ParallaxBG(Parallax& parallax)
{
	parallax.furtherPosition1.x += parallax.furtherSpeed * GetFrameTime();
	parallax.furtherPosition2.x += parallax.furtherSpeed * GetFrameTime();
	parallax.middlePosition1.x += parallax.middleSpeed * GetFrameTime();
	parallax.middlePosition2.x += parallax.middleSpeed * GetFrameTime();
	parallax.closerPosition1.x += parallax.closerSpeed * GetFrameTime();
	parallax.closerPosition2.x += parallax.closerSpeed * GetFrameTime();
	
	if (parallax.furtherPosition1.x > GetScreenWidth())
	{
		parallax.furtherPosition1.x = -1024 + parallax.furtherSpeed * GetFrameTime();
	}
	if (parallax.furtherPosition2.x > GetScreenWidth())
	{
		parallax.furtherPosition2.x = -1024 + parallax.furtherSpeed * GetFrameTime();
	}

	if (parallax.middlePosition1.x > GetScreenWidth())
	{
		parallax.middlePosition1.x = -1024 + parallax.middleSpeed * GetFrameTime();
	}
	if (parallax.middlePosition2.x > GetScreenWidth())
	{
		parallax.middlePosition2.x = -1024 + parallax.middleSpeed * GetFrameTime();
	}

	if (parallax.closerPosition1.x > GetScreenWidth())
	{
		parallax.closerPosition1.x = -1024 + parallax.closerSpeed * GetFrameTime();
	}
	if (parallax.closerPosition2.x > GetScreenWidth())
	{
		parallax.closerPosition2.x = -1024 + parallax.closerSpeed * GetFrameTime();
	}
}

void EnemyTp(Enemy& enemy, Player& spaceShip)
{
	if (enemy.position.x < -50)
	{
		enemy.position.x = static_cast<float>(GetScreenWidth());
		
		spaceShip.score++;
	}

	for (int i = 0; i < maxFlyingEnemy; i++)
	{
		if (maximumFlyingEnemy[i].position.x >= GetScreenWidth())
		{
			maximumFlyingEnemy[i].position.x = -50;
		}
	}
}

void GameCollisions(Player& spaceShip, Enemy& enemy, PlayerBullet& playerBullet)
{
	if (spaceShip.isAlive)
	{
		if (CollisionRectangleRectangle(spaceShip.position.x, spaceShip.position.y, spaceShip.size.x, spaceShip.size.y, enemy.position.x, enemy.position.y, enemy.size.x, enemy.size.y))
		{
			spaceShip.isAlive = false;
		}
	}

	for (int i = 0; i < maxFlyingEnemy; i++)
	{
		for (int j = 0; j < maxPlayerBullets; j++)
		{
			if (CollisionRectangleRectangle(maximumFlyingEnemy[i].position.x, maximumFlyingEnemy[i].position.y, maximumFlyingEnemy[i].size.x, maximumFlyingEnemy[i].size.y, maximumPlayerBullets[j].position.x, maximumPlayerBullets[j].position.y, maximumPlayerBullets[j].size.x, maximumPlayerBullets[j].size.y) && maximumFlyingEnemy[i].isAlive)
			{
				maximumFlyingEnemy[i].isAlive = false;
				maximumPlayerBullets[j].isActive = false;

				spaceShip.score++;
			}
		}
	}
}

void CheckInput(Player& spaceShip, bool& playingGame, PlayerBullet& playerBullet)
{
	if (IsKeyPressed(KEY_SPACE) && spaceShip.position.y == spaceShip.startJumpPosition)
	{
		spaceShip.isJumping = true;
	}

	if (spaceShip.isJumping)
	{
		do
		{
			spaceShip.position.y -= spaceShip.gravity * GetFrameTime();

			if (spaceShip.position.y <= spaceShip.maxHeightJump)
			{
				spaceShip.isJumping = false;
				break;
			}
		} while (spaceShip.position.y < spaceShip.maxHeightJump);
	}
	else if (!spaceShip.isJumping && spaceShip.position.y != spaceShip.startJumpPosition)
	{
		do
		{
			spaceShip.position.y += spaceShip.gravity * GetFrameTime();

			if (spaceShip.position.y >= spaceShip.startJumpPosition)
			{
				spaceShip.position.y = spaceShip.startJumpPosition;
				break;
			}
		} while (spaceShip.position.y > spaceShip.startJumpPosition);
	}

	if (IsKeyDown(KEY_D))
	{
		if (spaceShip.position.x <= GetScreenWidth())
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

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		if (currentPlayerBullet >= maxPlayerBullets)
		{
			currentPlayerBullet = 0;
		}

		maximumPlayerBullets[currentPlayerBullet] = CreatePlayerBullet(maximumPlayerBullets[currentPlayerBullet], spaceShip);

		currentPlayerBullet++;
	}
}