#pragma once

#include "Window/GameLoop.h"

#include "Objects/Mouse.h"

#include "Objects/Player.h"

void InitPauseMenu(SubMenu& pauseMenu, Button& pauseButtonOff, Button& pauseButtonOn, Button& resumeButton, Button& returnMenuButton, Button& quitGameButton, int screenWidth, int screenHeight);
void PauseMenusInputs(bool& gameOn, bool& runGame, bool& playGame, int& optionSelect, bool& pause, SubMenu& restartMenu, SubMenu& pauseMenu, Button& pauseButtonOff, Button& pauseButtonOn, Music& music, Mouse& mouse, int screenWidth, int screenHeight);
void PauseMenuCollisions(SubMenu& pauseMenu, Mouse& mouse, Button& resumeButton, Button& returnMenuButton, Button& quitGameButton, int screenWidth, int screenHeight);
void DrawPauseMenu(SubMenu& pauseMenu, Button& resumeButton, Button& returnMenuButton, Button& quitGameButton, Font gameFont, int screenWidth, int screenHeight);