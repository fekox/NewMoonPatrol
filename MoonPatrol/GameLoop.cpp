#include "GameLoop.h"
#include "raylib.h"

static void Initialize();

static void Close();

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