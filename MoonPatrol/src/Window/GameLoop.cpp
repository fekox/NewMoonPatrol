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

void MouseMovement();

//Window
int screenWidth = 1024;
int screenHeight = 768;

//Menu
int optionSelect = 0;

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
Mouse mouse = CreateMouse();

//Font
Font gameFont;

void RunGame()
{
	Initialize();
	bool playingGame = false;

	while (!playingGame && !WindowShouldClose())
	{
		MouseMovement();
		MenuCollisions(mouse, optionSelect);
		MenuInputs(mouse, optionSelect, playingGame);

        switch (optionSelect)
        {
        case static_cast<int>(Menu::MainMenu):
            BeginDrawing();
            ClearBackground(BLACK);
            ShowCursor();
            DrawMenu(gameFont);
            EndDrawing();
            break;

        case static_cast<int>(Menu::Play):
            break;

        case static_cast<int>(Menu::Controlls):
            BeginDrawing();
            ClearBackground(BLACK);
            DrawControlls(gameFont);
            EndDrawing();
            break;

        case static_cast<int>(Menu::Rules):
            BeginDrawing();
            ClearBackground(BLACK);
            DrawRules(gameFont);
            EndDrawing();
            break;

        case static_cast<int>(Menu::Credits):
            BeginDrawing();
            ClearBackground(BLACK);
            DrawCredits(gameFont);
            EndDrawing();
            break;

        case static_cast<int>(Menu::Quit):
            break;
        }

	}

	Close();
}

void Initialize()
{
	InitWindow(1024, 768, "MoonPatrol V0.4");

	//Menu
	InitMenu();

	//Font
	gameFont = LoadFont("resources/Font/baby blocks.ttf");

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

}

void MouseMovement()
{
	mouse.position = GetMousePosition();
}

void Close()
{
	CloseWindow();
}


//if (IsKeyPressed(KEY_SPACE) && spaceShip.position.y == spaceShip.startJumpPosition)
//{
//	spaceShip.isJumping = true;
//}
//
//if (spaceShip.isJumping)
//{
//	do
//	{
//		spaceShip.position.y -= spaceShip.gravity * GetFrameTime();
//
//		if (spaceShip.position.y <= spaceShip.maxHeightJump)
//		{
//			spaceShip.isJumping = false;
//			break;
//		}
//	} while (spaceShip.position.y < spaceShip.maxHeightJump);
//}
//else if (!spaceShip.isJumping && spaceShip.position.y != spaceShip.startJumpPosition)
//{
//	do
//	{
//		spaceShip.position.y += spaceShip.gravity * GetFrameTime();
//
//		if (spaceShip.position.y >= spaceShip.startJumpPosition)
//		{
//			spaceShip.position.y = spaceShip.startJumpPosition;
//			break;
//		}
//	} while (spaceShip.position.y > spaceShip.startJumpPosition);
//}
