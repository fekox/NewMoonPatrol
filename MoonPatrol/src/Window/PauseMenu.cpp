#include "Window/PauseMenu.h"
#include "Window/GameLoop.h"
#include "Window/RestartMenu.h"

#include "Objects/Mouse.h"

void InitPauseMenu(SubMenu& pauseMenu, Button& pauseButtonOff, Button& pauseButtonOn, Button& resumeButton, Button& returnMenuButton, Button& quitGameButton, int screenWidth, int screenHeight)
{
    //Pause Menu
    pauseMenu.width = 600;
    pauseMenu.height = 500;
    pauseMenu.pos.x = static_cast<float>(screenWidth / 4.5);
    pauseMenu.pos.y = static_cast<float>(screenHeight / 4.5);
    pauseMenu.isActive = false;
    pauseMenu.texture = LoadTexture("resources/Sprites/RestartGameMenu.png");

    //Pause Button Off
    pauseButtonOff.pos.x = static_cast<float>(screenWidth / 1.2);
    pauseButtonOff.pos.y = static_cast<float>(screenHeight / 20);
    pauseButtonOff.width = 64;
    pauseButtonOff.height = 64;
    pauseButtonOff.color = WHITE;
    pauseButtonOff.texture = LoadTexture("resources/Sprites/PauseButtonOff.png");

    //Pause Button On
    pauseButtonOn.pos.x = static_cast<float>(screenWidth / 1.2);
    pauseButtonOn.pos.y = static_cast<float>(screenHeight / 20);
    pauseButtonOn.width = 64;
    pauseButtonOn.height = 64;
    pauseButtonOn.color = WHITE;
    pauseButtonOn.texture = LoadTexture("resources/Sprites/PauseButtonOn.png");

    //Resume Button
    resumeButton.width = static_cast<float>(screenWidth / 2.5);
    resumeButton.height = static_cast<float>(screenHeight / 2.1);
    resumeButton.size = 40;
    resumeButton.color = BLACK;

    //Menu Button
    returnMenuButton.width = static_cast<float>(screenWidth / 2.3);
    returnMenuButton.height = static_cast<float>(screenHeight / 1.65);
    returnMenuButton.size = 40;
    returnMenuButton.color = BLACK;

    //Quit Button
    quitGameButton.width = static_cast<float>(screenWidth / 2.3);
    quitGameButton.height = static_cast<float>(screenHeight / 1.37);
    quitGameButton.size = 40;
    quitGameButton.color = BLACK;
}

void PauseMenusInputs(bool& gameOn, bool& runGame, bool& playGame, int& optionSelect, bool& pause, SubMenu& restartMenu, SubMenu& pauseMenu, Button& pauseButtonOff, Button& pauseButtonOn, Music& music, Mouse& mouse, int screenWidth, int screenHeight)
{
    if (!restartMenu.isActive && pauseMenu.isActive)
    {
        PauseMusicStream(music);

        //Resume Button
        if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(screenWidth / 2.5), static_cast<float>(screenHeight / 2.2), static_cast<float>(screenWidth / 4), static_cast<float>(screenHeight / 10) }))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                pause = false;
                pauseMenu.isActive = false;
                ResumeMusicStream(music);
            }
        }

        //Return Menu Button
        if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(screenWidth / 2.5), static_cast<float>(screenHeight / 1.7), static_cast<float>(screenWidth / 4), static_cast<float>(screenHeight / 12) }))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                RestartGame();
                runGame = false;

                pause = false;
                playGame = false;
                pauseMenu.isActive = false;
                optionSelect = 0;
                ResumeMusicStream(music);
            }
        }

        //Quit Game Button
        if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(screenWidth / 2.5), static_cast<float>(screenHeight / 1.4), static_cast<float>(screenWidth / 4), static_cast<float>(screenHeight / 12) }))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                gameOn = false;
            }
        }
    }

    //Pause menu
    if (!restartMenu.isActive && !pauseMenu.isActive)
    {
        if (IsKeyPressed(KEY_ESCAPE) || IsKeyPressed(KEY_P))
        {
            PauseMusicStream(music);
            pauseMenu.isActive = true;
            pause = true;
        }

        if (CheckCollisionPointRec(mouse.position, Rectangle{ pauseButtonOff.pos.x, pauseButtonOff.pos.y, pauseButtonOff.width, pauseButtonOff.height }))
        {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                PauseMusicStream(music);
                pauseMenu.isActive = true;
                pause = true;
            }
        }
    }

    else
    {
        if (!restartMenu.isActive)
        {
            if (IsKeyPressed(KEY_ESCAPE) || IsKeyPressed(KEY_P))
            {
                pauseMenu.isActive = false;
                pause = false;
                HideCursor();
                ResumeMusicStream(music);
            }

            if (CheckCollisionPointRec(mouse.position, Rectangle{ pauseButtonOn.pos.x, pauseButtonOn.pos.y, pauseButtonOn.width, pauseButtonOn.height }))
            {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                {
                    pauseMenu.isActive = false;
                    pause = false;
                    HideCursor();
                    ResumeMusicStream(music);
                }
            }
        }
    }
}

void PauseMenuCollisions(SubMenu& pauseMenu, Mouse& mouse, Button& resumeButton, Button& returnMenuButton, Button& quitGameButton, int screenWidth, int screenHeight)
{
    if (pauseMenu.isActive)
    {
        //Restart Button
        if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(screenWidth / 2.5), static_cast<float>(screenHeight / 2.2), static_cast<float>(screenWidth / 3.8), static_cast<float>(screenHeight / 10) }))
        {
            resumeButton.color = GOLD;
        }

        else
        {
            resumeButton.color = WHITE;
        }

        //Return Menu Button
        if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(screenWidth / 2.5), static_cast<float>(screenHeight / 1.7), static_cast<float>(screenWidth / 4), static_cast<float>(screenHeight / 12) }))
        {
            returnMenuButton.color = GOLD;
        }

        else
        {
            returnMenuButton.color = WHITE;
        }

        //Quit Game Button
        if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(screenWidth / 2.5), static_cast<float>(screenHeight / 1.4), static_cast<float>(screenWidth / 4), static_cast<float>(screenHeight / 12) }))
        {
            quitGameButton.color = GOLD;
        }

        else
        {
            quitGameButton.color = WHITE;
        }
    }
}

void DrawPauseMenu(SubMenu& pauseMenu, Button& resumeButton, Button& returnMenuButton, Button& quitGameButton, Font gameFont, int screenWidth, int screenHeight)
{
    DrawRectangle(static_cast<int>(pauseMenu.pos.x), static_cast<int>(pauseMenu.pos.y), static_cast<int>(pauseMenu.width), static_cast<int>(pauseMenu.height), BLANK);
    DrawTexture(pauseMenu.texture, static_cast<int>(pauseMenu.pos.x), static_cast<int>(pauseMenu.pos.y), WHITE);

    DrawTextEx(gameFont, "PAUSE", { static_cast<float>(screenWidth / 3), static_cast<float>(screenHeight / 3.1) }, 70, 0, GOLD);

    //Restart Button
    DrawRectangle(static_cast<int>(screenWidth / 2.5), static_cast<int>(screenHeight / 2.2), static_cast<int>(screenWidth / 3.8), static_cast<int>(screenHeight / 10), BLANK);
    DrawTextEx(gameFont, "RESUME", { static_cast<float>(resumeButton.width), static_cast<float>(resumeButton.height) }, static_cast<float>(resumeButton.size), 0, resumeButton.color);

    //Return Menu Button
    DrawRectangle(static_cast<int>(screenWidth / 2.5), static_cast<int>(screenHeight / 1.7), static_cast<int>(screenWidth / 4), static_cast<int>(screenHeight / 12), BLANK);
    DrawTextEx(gameFont, "MENU", { static_cast<float>(returnMenuButton.width), static_cast<float>(returnMenuButton.height) }, static_cast<float>(returnMenuButton.size), 0, returnMenuButton.color);

    //Quit Game Button
    DrawRectangle(static_cast<int>(screenWidth / 2.5), static_cast<int>(screenHeight / 1.4), static_cast<int>(screenWidth / 4), static_cast<int>(screenHeight / 12), BLANK);
    DrawTextEx(gameFont, "QUIT", { static_cast<float>(quitGameButton.width), static_cast<float>(quitGameButton.height) }, static_cast<float>(quitGameButton.size), 0, quitGameButton.color);
}