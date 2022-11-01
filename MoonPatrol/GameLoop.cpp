#include "GameLoop.h"
#include "raylib.h"

static void Initialize();

static void Close();

bool CollisionRectangleRectangle(float r1x, float r1y, float r1w, float r1h, float r2x, float r2y, float r2w, float r2h);

void RunGame()
{
	Initialize();
	HideCursor();
	SetExitKey(KEY_NULL);

	bool playingGame = true;

	while (playingGame && !WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);

		DrawText("VERSION 0.1", 10, 10, 20, GREEN);

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