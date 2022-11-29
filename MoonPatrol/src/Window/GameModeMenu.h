#pragma once
#include "Window/GameLoop.h"

#include "Objects/Mouse.h"

#include "Objects/Player.h"

void InitGameModeMenu(SubMenu& gameModeMenu, Button& singlePlayerButton, Button& multiPlayerButton, int screenWidth, int screenHeight);
void GameModeMenuInputs(Mouse& mouse, Player& player2, SubMenu& gameModeMenu, int screenWidth, int screenHeight, bool& multiplayer, bool& runGam);
void GameModeMenuCollsions(Mouse& mouse, SubMenu& gameModeMenu, Button& singlePlayerButton, Button& multiPlayerButton, int screenWidth, int screenHeight);
void DrawGameModeMenu(Font gameFont, Texture& subMenusBackground, Button& singlePlayerButton, Button& multiPlayerButton, int screenWidth, int screenHeight);