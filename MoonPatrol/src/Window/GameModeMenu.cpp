#include "Window/GameModeMenu.h"
#include "Window/GameLoop.h"

#include "Objects/Mouse.h"
#include "Objects/Player.h"


void InitGameModeMenu(SubMenu& gameModeMenu, Button& singlePlayerButton, Button& multiPlayerButton, int screenWidth, int screenHeight)
{
    //GameMode Menu
    gameModeMenu.width = static_cast<float>(screenWidth);
    gameModeMenu.height = static_cast<float>(screenHeight);
    gameModeMenu.isActive = false;

    //Single Button
    singlePlayerButton.width = static_cast<float>(screenWidth / 4.5);
    singlePlayerButton.height = static_cast<float>(screenHeight / 2.5);
    singlePlayerButton.size = 45;
    singlePlayerButton.color = GOLD;

    //MultiPlayer Button
    multiPlayerButton.width = static_cast<float>(screenWidth / 4.5);
    multiPlayerButton.height = static_cast<float>(screenHeight / 1.5);
    multiPlayerButton.size = 45;
    multiPlayerButton.color = GOLD;
}

void GameModeMenuInputs(Mouse& mouse, Player& player2, SubMenu& gameModeMenu, int screenWidth, int screenHeight, bool& multiplayer, bool& runGame)
{
    if (gameModeMenu.isActive)
    {
        //Single Player Button
        if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(screenWidth / 4.5), static_cast<float>(screenHeight / 2.6), static_cast<float>(screenWidth / 1.8), static_cast<float>(screenHeight / 10) }))
        {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                multiplayer = false;
                runGame = true;
                gameModeMenu.isActive = false;
            }
        }

        //Multi Player Button
        if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(screenWidth / 4.5), static_cast<float>(screenHeight / 1.55), static_cast<float>(screenWidth / 1.8), static_cast<float>(screenHeight / 10) }))
        {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                multiplayer = true;
                player2.isActive = true;
                runGame = true;
                gameModeMenu.isActive = false;
            }
        }
    }
}

void GameModeMenuCollsions(Mouse& mouse, SubMenu& gameModeMenu, Button& singlePlayerButton, Button& multiPlayerButton, int screenWidth, int screenHeight)
{
    if (gameModeMenu.isActive)
    {
        //Return Menu Button
        if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(screenWidth / 4.5), static_cast<float>(screenHeight / 2.6), static_cast<float>(screenWidth / 1.8), static_cast<float>(screenHeight / 10) }))
        {
            singlePlayerButton.color = GOLD;
        }

        else
        {
            singlePlayerButton.color = WHITE;
        }

        //Quit Game Button
        if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(screenWidth / 4.5), static_cast<float>(screenHeight / 1.55), static_cast<float>(screenWidth / 1.8), static_cast<float>(screenHeight / 10) }))
        {
            multiPlayerButton.color = GOLD;
        }

        else
        {
            multiPlayerButton.color = WHITE;
        }
    }
}

void DrawGameModeMenu(Font gameFont, Texture& subMenusBackground, Button& singlePlayerButton, Button& multiPlayerButton, int screenWidth, int screenHeight)
{
    //Sub Menus Background
    DrawTexture(subMenusBackground, 0, 0, WHITE);

    DrawTextEx(gameFont, "GAME MODE", { static_cast<float>(screenWidth / 5.5), static_cast<float>(screenHeight / 8) }, 70, 0, GOLD);

    //Single Player Button
    DrawRectangle(static_cast<int>(screenWidth / 4.5), static_cast<int>(screenHeight / 2.6), static_cast<int>(screenWidth / 1.8), static_cast<int>(screenHeight / 10), BLANK);
    DrawTextEx(gameFont, "SIGLE PLAYER", { static_cast<float>(singlePlayerButton.width), static_cast<float>(singlePlayerButton.height) }, static_cast<float>(singlePlayerButton.size), 0, singlePlayerButton.color);

    //Multi Player Button
    DrawRectangle(static_cast<int>(screenWidth / 4.5), static_cast<int>(screenHeight / 1.55), static_cast<int>(screenWidth / 1.8), static_cast<int>(screenHeight / 10), BLANK);
    DrawTextEx(gameFont, "MULTI PLAYER", { static_cast<float>(multiPlayerButton.width), static_cast<float>(multiPlayerButton.height) }, static_cast<float>(multiPlayerButton.size), 0, multiPlayerButton.color);
}