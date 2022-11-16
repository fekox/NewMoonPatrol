#pragma once
#include "raylib.h"
#include "Objects/Mouse.h"

struct MenuButton
{
	Vector2 pos;

	float width;
	float height;

	int size;

	bool isActive;

	Texture texture;

	Color color;
};

enum class Menu
{
	MainMenu,
	Play,
	Controlls,
	Rules,
	Credits,
	Quit
};

void InitMenu();
void MenuCollisions(Mouse& mouse, int& optionSelect);
void MenuInputs(Mouse& mouse, int& optionSelect, bool& playGame);
void DrawMenu(Font gameFont);
void DrawControlls(Font gameFont);
void DrawRules(Font gameFont);
void DrawCredits(Font gameFont);
