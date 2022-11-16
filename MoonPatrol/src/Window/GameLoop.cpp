#include <iostream>

#include "raylib.h"

#include "Window/GameLoop.h"
#include "Window/Menu.h"
#include "Window/Parallax.h"

#include "Objects/Player.h"
#include "Objects/PlayerBullet.h"
#include "Objects/Background.h"
#include "Objects/Enemy.h"

using namespace std;

//Window
int screenWidth = 1024;
int screenHeight = 768;

//Player
Player spaceShip;
PlayerBullet playerBullets;
PlayerBullet maximumPlayerBullets[maxPlayerBullets];
int currentPlayerBullet = 0;

//Enemy
Enemy enemy;
Enemy flyingEnemy;
Enemy maximumFlyingEnemy[maxFlyingEnemy];
int currentFlyingEnemy = 0;

//Background
Background sky = CreateBackground(screenWidth, screenHeight);
Background sky2 = CreateBackground(screenWidth, screenHeight);

Background city = CreateBackground(screenWidth, screenHeight);
Background city2 = CreateBackground(screenWidth, screenHeight);

Background hill = CreateBackground(screenWidth, screenHeight);
Background hill2 = CreateBackground(screenWidth, screenHeight);

//Mouse

Vector2 mousePosition;

bool CollisionRectangleRectangle(float r1x, float r1y, float r1w, float r1h, float r2x, float r2y, float r2w, float r2h);

void EnemyTp(Enemy& enemy, Player& spaceShip);

void GameCollisions(Player& spaceShip, Enemy& enemy, PlayerBullet& playerBullet);

void CheckInput(Player& spaceShip, bool& playingGame, PlayerBullet& playerBullet);

void EnemyMovement(Enemy& enemy);

void RunGame()
{
	Initialize();
	bool playingGame = true;

	while (playingGame && !WindowShouldClose())
	{
		MenuCollisions(mousePosition);


	}

	Close();
}

void GameDraw(bool exitWindow, Player& spaceShip, const Enemy& enemy, Parallax& parallax, PlayerBullet& playerBullet)
{
	BeginDrawing();
	ClearBackground(BLACK);

	DrawText("Press 'ESC' to pause the game", static_cast<int>(GetScreenWidth() / 2) - 270, 10, 35, WHITE);

	DrawParallax(parallax);

	if (exitWindow)
	{
		DrawRectangleRounded({ static_cast<float>(GetScreenWidth() / 2 - 250), static_cast<float>(GetScreenHeight() / 2 - 200), 500, 400 }, static_cast<int>(0.5f), 1, BLACK);
		DrawRectangleRounded({ static_cast<float>(GetScreenWidth() / 2 - 245), static_cast<float>(GetScreenHeight() / 2 - 195), 490, 390 }, static_cast<int>(0.5f), 1, WHITE);

		DrawText("Do you want to", GetScreenWidth() - 705, GetScreenHeight() / 2 - 150, static_cast<int>(51.5f), BLACK);
		DrawText("keep playing?", GetScreenWidth() - 685, GetScreenHeight() / 2 - 80, static_cast<int>(51.5f), BLACK);

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

		DrawText("GAME OVER", GetScreenWidth() - 650, (GetScreenHeight() / 2) - 150, 50, BLACK);
		DrawText(TextFormat("SCORE: %i", spaceShip.score), GetScreenWidth() - 600, GetScreenHeight() / 2 - 90, 40, BLACK);

		DrawText("Do you want to", GetScreenWidth() - 620, (GetScreenHeight() / 2) - 30, 30, BLACK);
		DrawText("keep playing?", GetScreenWidth() - 610, GetScreenHeight() / 2, 30, BLACK);

		DrawRectangleRounded({ 350, 425, 150, 100 }, 0.5f, 1, BLACK);
		DrawRectangleRounded({ 355, 430, 140, 90 }, 0.5f, 1, WHITE);

		DrawText("MAIN", 380, 440, 35, BLACK);
		DrawText("MENU", 375, 480, 35, BLACK);

		DrawRectangleRounded({ 530, 425, 150, 100 }, 0.5f, 1, BLACK);
		DrawRectangleRounded({ 535, 430, 140, 90 }, 0.5f, 1, WHITE);

		DrawText("EXIT", 565, 460, 35, BLACK);
	}

	EndDrawing();
}

void Initialize()
{
	InitWindow(1024, 768, "MoonPatrol V0.4");

	SetExitKey(KEY_NULL);

	bool isPaused = false;
	bool exitWindow = false;
	bool gameFinished = false;

	CreatePlayerShip(spaceShip);
	CreateEnemy(enemy);

	for (int i = 0; i < maxFlyingEnemy; i++)
	{
		maximumFlyingEnemy[i] = CreateFlyingEnemy(flyingEnemy, i * 100.0f);
	}

	mousePosition = GetMousePosition();
}

void Close()
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