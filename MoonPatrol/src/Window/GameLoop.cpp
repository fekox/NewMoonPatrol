#include <iostream>

#include "raylib.h"

#include "Window/GameLoop.h"
#include "Window/Menu.h"
#include "Window/RestartMenu.h"
#include "Window/PauseMenu.h"
#include "Window/GameModeMenu.h"

#include "Objects/Player.h"
#include "Objects/PlayerBullet.h"
#include "Objects/Floor.h"
#include "Objects/Obstacle.h"
#include "Objects/FlyEnemy.h"
#include "Objects/Background.h"
#include "Objects/Mouse.h"

using namespace std;

//Collisions
void Collisions();
bool CheckCollisionRecRec(Vector2 r1, float r1w, float r1h, Vector2 r2, float r2w, float r2h);
void PlayerCollision();
void BulletCollision();
void BulletCollisonLimit();
void FlyEnemyCollisionLimit();

//Movement
void MouseMovement();
void ObstacleMovement();
void ObstacleTeleport();
void PlayerMovement();
void Player2Movement();
void PlayerJump(Player& player);
void PlayerBulletMovement();
void FlyEnemyMovement();
void BackgroundMovement();
void FlyEnemyRespawn();

//Window
int screenWidth = 1024;
int screenHeight = 768;

//Menu
int optionSelect = 0;
bool playGame = false;
Texture menuBackground;

Texture subMenusBackground;

//Pause
bool pause = false;
SubMenu pauseMenu;
Button pauseButtonOff;
Button pauseButtonOn;
Button resumeButton;
Button returnMenuButton;
Button quitGameButton;

//Game Mode Menu
bool multiplayer = false;
bool runGame = false;
SubMenu gameModeMenu;
Button singlePlayerButton;
Button multiPlayerButton;

//RestartMenu
SubMenu restartMenu;
Button restartButton;

//Player
Player player;
Player player2;

//Bullet
int const maxBullets = 30;
Bullet playerBullet[maxBullets];
Bullet player2Bullet[maxBullets];

//Floor
Ground ground;

//Obstacle
Obstacle obstacle;

//FlyEnemy
int const maxflyEnemy = 5;
FlyEnemy flyEnemy[maxflyEnemy];

//Background
Background sky;
Background sky2;

Background city;
Background city2;

Background hill;
Background hill2;

//Mouse
Mouse mouse;

//Music
Music music;
Sound playerDead;
Sound enemyDead;
Sound playerShot;
float musicPitch = 0.9f;

//Font
Font gameFont;

void PlayGame()
{
    InitGame();

    GameLoop();
}

void InitGame()
{
    InitWindow(screenWidth, screenHeight, "Pingu Attack v1.1");
    SetWindowState(FLAG_VSYNC_HINT);
    SetExitKey(NULL);

    //Music

    InitAudioDevice();


    music = LoadMusicStream("resources/Music/Twin Musicom - 8-bit March.mp3");
    music.looping = true;
    PlayMusicStream(music);
    SetMusicVolume(music, 0.5f);

    playerDead = LoadSound("resources/Music/PlayerDead.mp3");
    SetSoundVolume(playerDead, 0.5f);

    enemyDead = LoadSound("resources/Music/EnemyDead.mp3");
    SetSoundVolume(enemyDead, 0.5f);

    playerShot = LoadSound("resources/Music/Shoot.mp3");
    SetSoundVolume(playerShot, 0.2f);

    //Menu
    menuBackground = LoadTexture("resources/Sprites/MenuBackground.png");

    subMenusBackground = LoadTexture("resources/Sprites/SubMenusBackground.png");
    InitMenu();

    //Restart Menu
    InitRestartMenu(restartMenu, restartButton, returnMenuButton, quitGameButton, screenWidth, screenHeight);

    //Pause Menu
    InitPauseMenu(pauseMenu, pauseButtonOff, pauseButtonOn, resumeButton, returnMenuButton, quitGameButton, screenWidth, screenHeight);

    //GameMode Menu
    InitGameModeMenu(gameModeMenu, singlePlayerButton, multiPlayerButton, screenWidth, screenHeight);

    //Mouse
    mouse = CreateMouse();

    //Font
    gameFont = LoadFont("resources/Font/baby blocks.ttf");

    //Player1
    player = CreatePlayer(screenWidth, screenHeight);

    //Player2
    player2 = CreatePlayer(screenWidth, screenHeight);
    player2.pos.x = static_cast<float>(screenWidth / 4);
    player2.pos.y = static_cast<float>(screenHeight / 1.165);
    player2.width = 80;
    player2.height = 40;
    player2.speed = 420;
    player2.lifes = 3;
    player2.points = 0;
    player2.isCollision = false;
    player2.isAlive = true;
    player2.win = false;
    player2.isActive = false;
    player2.tex = LoadTexture("resources/Sprites/Player2.png");

    //Bullets
    for (int i = 0; i < maxBullets; i++)
    {
        playerBullet[i] = CreateBullet();
        player2Bullet[i] = CreateBullet();
        player2Bullet[i].color = SKYBLUE;
    }

    //Background
        //Sky
    sky = CreateBackground(screenWidth, screenHeight);
    sky.pos.x = static_cast<float>(screenWidth / screenWidth);
    sky.tex = LoadTexture("resources/Sprites/Sky.png");

    sky2 = CreateBackground(screenWidth, screenHeight);
    sky2.pos.x = static_cast<float>(screenWidth / screenWidth + sky.width);
    sky2.tex = LoadTexture("resources/Sprites/Sky.png");

    //City
    city = CreateBackground(screenWidth, screenHeight);
    city.pos.x = static_cast<float>(screenWidth / screenWidth);
    city.pos.y = static_cast<float>((screenHeight / screenHeight) - 60);
    city.tex = LoadTexture("resources/Sprites/City.png");
    city.speed = 200;

    city2 = CreateBackground(screenWidth, screenHeight);
    city2.pos.x = static_cast<float>(screenWidth / screenWidth + city.width);
    city2.pos.y = static_cast<float>((screenHeight / screenHeight) - 60);
    city2.tex = LoadTexture("resources/Sprites/City.png");
    city2.speed = 200;

    //Hill
    hill = CreateBackground(screenWidth, screenHeight);
    hill.pos.x = static_cast<float>(screenWidth / screenWidth);
    hill.pos.y = static_cast<float>((screenHeight / 1.28));
    hill.tex = LoadTexture("resources/Sprites/Hill.png");
    hill.speed = 400;

    hill2 = CreateBackground(screenWidth, screenHeight);
    hill2.pos.x = static_cast<float>(screenWidth / screenWidth + hill.width);
    hill2.pos.y = static_cast<float>((screenHeight / 1.28));
    hill2.tex = LoadTexture("resources/Sprites/Hill.png");
    hill2.speed = 400;

    //Enemy
    for (int i = 0; i < maxflyEnemy; i++)
    {
        flyEnemy[i] = CreateFlyEnemy();
        flyEnemy[0].pos.x = static_cast<float>(screenWidth / -2.5);
        flyEnemy[0].pos.y = static_cast<float>(screenHeight / -2.5);

        flyEnemy[1].pos.x = static_cast<float>(screenWidth / -1.9);
        flyEnemy[1].pos.y = static_cast<float>(screenHeight / -1.9);

        flyEnemy[2].pos.x = static_cast<float>(screenWidth / -1.5);
        flyEnemy[2].pos.y = static_cast<float>(screenHeight / -1.5);

        flyEnemy[3].pos.x = static_cast<float>(screenWidth / -1.22);
        flyEnemy[3].pos.y = static_cast<float>(screenHeight / -1.22);

        flyEnemy[4].pos.x = static_cast<float>(screenWidth / -1.05);
        flyEnemy[4].pos.y = static_cast<float>(screenHeight / -1.05);
    }

    //Ground 
    ground = CreateGround(screenWidth, screenHeight);
    ground.tex = LoadTexture("resources/Sprites/Ground.png");

    //Obstacle
    obstacle = CreateObstacle(screenWidth, screenHeight);
}

void GameLoop()
{
    bool gameOn = true;

    if (gameOn == true)
    {
        while (!WindowShouldClose() && gameOn)
        {
            UpdateMusicStream(music);
            SetMusicPitch(music, musicPitch);

            MouseMovement();
            MenuCollisions(mouse, optionSelect);
            MenuInputs(mouse, optionSelect, playGame, gameModeMenu);

            GameModeMenuCollsions(mouse, gameModeMenu, singlePlayerButton, multiPlayerButton, screenWidth, screenHeight);
            GameModeMenuInputs(mouse, player2, gameModeMenu, screenWidth, screenHeight, multiplayer, runGame);

            if (playGame == true && runGame == true)
            {
                RestartMenuInputs(restartMenu, pause, runGame, playGame, gameOn, optionSelect, mouse, screenWidth, screenHeight);
                PauseMenusInputs(gameOn, runGame, playGame, optionSelect, pause, restartMenu, pauseMenu, pauseButtonOff, pauseButtonOn, music, mouse, screenWidth, screenHeight);

                if (!pause)
                {
                    Update();
                    Collisions();
                }

                PauseMenuCollisions(pauseMenu, mouse, resumeButton, returnMenuButton, quitGameButton, screenWidth, screenHeight);
                RestarGameMenuCollisions(restartMenu, restartButton, returnMenuButton, quitGameButton, mouse, screenWidth, screenHeight);
            }

            switch (optionSelect)
            {
            case static_cast<int>(Menu::MainMenu):
                BeginDrawing();
                ClearBackground(BLACK);
                ShowCursor();
                DrawMenu(gameFont, menuBackground);
                EndDrawing();
                break;

            case static_cast<int>(Menu::Play):

                if (!runGame)
                {
                    BeginDrawing();
                    ClearBackground(BLACK);
                    DrawGameModeMenu(gameFont, subMenusBackground, singlePlayerButton, multiPlayerButton, screenWidth, screenHeight);
                    DrawMouse(mouse, mouse.mouseRec);
                    EndDrawing();
                }

                if (runGame)
                {
                    Draw();
                }

                break;

            case static_cast<int>(Menu::Controlls):
                BeginDrawing();
                ClearBackground(BLACK);
                DrawControlls(gameFont, subMenusBackground);
                EndDrawing();
                break;

            case static_cast<int>(Menu::Rules):
                BeginDrawing();
                ClearBackground(BLACK);
                DrawRules(gameFont, subMenusBackground);
                EndDrawing();
                break;

            case static_cast<int>(Menu::Credits):
                BeginDrawing();
                ClearBackground(BLACK);
                DrawCredits(gameFont, subMenusBackground);
                EndDrawing();
                break;

            case static_cast<int>(Menu::Quit):
                gameOn = false;
                break;
            }
            
        }
    }

    if (!gameOn)
    {
        UnloadData();
        CloseWindow();
    }
}

void Update()
{
    ObstacleMovement();
    PlayerMovement();
    
    if (multiplayer == true)
    {
        Player2Movement();
    }

    PlayerBulletMovement();
    BackgroundMovement();
    FlyEnemyMovement();
}

void Draw()
{
    BeginDrawing();

    ClearBackground(BLACK);

    DrawBackground(sky);
    DrawBackground(sky2);

    DrawBackground(city);
    DrawBackground(city2);

    DrawBackground(hill);
    DrawBackground(hill2);

    DrawGround(ground);

    for (int i = 0; i < maxBullets; i++)
    {
        if (player.isActive)
        {
            DrawBullet(playerBullet[i]);
        }

        if (multiplayer == true)
        {
            if (player2.isActive)
            {
                DrawBullet(player2Bullet[i]);
            }
        }
    }

    for (int i = 0; i < maxflyEnemy; i++)
    {
        if (flyEnemy[i].isActive == true)
        {
            DrawFlyEnemy(flyEnemy[i]);
        }
    }

    DrawObstacle(obstacle);

    if (player.isActive)
    {
        DrawPlayer(player);
    }

    if (multiplayer == true)
    {
        if (player2.isActive)
        {
            DrawPlayer(player2);
        }
    }

    DrawTextEx(gameFont, TextFormat("score %0i", player.points), { static_cast<float>(GetScreenWidth() / 2.5) , static_cast<float>(GetScreenHeight() / 1.1) }, 50, 0, WHITE);

    DrawMouse(mouse, mouse.mouseRec);

    if (!pauseMenu.isActive)
    {
        DrawRectangle(static_cast<int>(pauseButtonOff.pos.x), static_cast<int>(pauseButtonOff.pos.y), static_cast<int>(pauseButtonOff.width), static_cast<int>(pauseButtonOff.height), BLANK);
        DrawTexture(pauseButtonOff.texture, static_cast<int>(pauseButtonOff.pos.x), static_cast<int>(pauseButtonOff.pos.y), pauseButtonOff.color);
    }

    if (pauseMenu.isActive)
    {
        DrawRectangle(static_cast<int>(pauseButtonOff.pos.x), static_cast<int>(pauseButtonOff.pos.y), static_cast<int>(pauseButtonOff.width), static_cast<int>(pauseButtonOff.height), BLANK);
        DrawTexture(pauseButtonOn.texture, static_cast<int>(pauseButtonOn.pos.x), static_cast<int>(pauseButtonOn.pos.y), pauseButtonOn.color);

        DrawPauseMenu(pauseMenu, resumeButton, returnMenuButton, quitGameButton, gameFont, screenWidth, screenHeight);
    }
   
    if (multiplayer == false)
    {
        if (!IsAlive(player) || PlayerWin(player))
        {
            player.isActive = false;
            DrawRestarGameMenu(restartMenu, restartButton, returnMenuButton, quitGameButton, player, player2, gameFont, screenWidth, screenHeight);
        }
    }

    if (multiplayer == true)
    {
        if (!IsAlive(player))
        {
           player.isActive = false;
        }

        if (!IsAlive(player2))
        {
            player2.isActive = false;
        }

        if (!player.isActive && !player2.isActive || PlayerWin(player))
        {
            DrawRestarGameMenu(restartMenu, restartButton, returnMenuButton, quitGameButton, player, player2, gameFont, screenWidth, screenHeight);
        }
    }

    DrawMouse(mouse, mouse.mouseRec);

    EndDrawing();
}

void Collisions()
{
    PlayerCollision();
    BulletCollision();
    BulletCollisonLimit();
    FlyEnemyCollisionLimit();
}

bool CheckCollisionRecRec(Vector2 r1, float r1w, float r1h, Vector2 r2, float r2w, float r2h)
{
    if (r1.x + r1w >= r2.x &&
        r1.x <= r2.x + r2w &&
        r1.y + r1h >= r2.y &&
        r1.y <= r2.y + r2h)
    {
        return true;
    }
    return false;
}

void PlayerCollision()
{
    //Player
    if (player.isActive == true)
    {
        if (CheckCollisionRecRec(player.pos, player.width - 20, player.height - 5, obstacle.pos, obstacle.width, obstacle.height))
        {
            player.isCollision = true;
            PlaySound(playerDead);
            LoseLife(player);
        }

        if (!CheckCollisionRecRec(player.pos, player.width - 20, player.height - 5, obstacle.pos, obstacle.width, obstacle.height))
        {
            player.isCollision = false;
        }

        if (CheckCollisionRecRec(player.pos, player.width, player.height, ground.pos, ground.width, ground.height))
        {
            player.isJumping = false;
            player.gravity = 0;
        }
    }

    if (multiplayer == true)
    {
        if (player2.isActive == true)
        {
            //Player2
            if (CheckCollisionRecRec(player2.pos, player2.width - 20, player2.height - 5, obstacle.pos, obstacle.width, obstacle.height))
            {
                player2.isCollision = true;
                PlaySound(playerDead);
                LoseLife(player2);
            }

            if (!CheckCollisionRecRec(player2.pos, player2.width - 20, player2.height - 5, obstacle.pos, obstacle.width, obstacle.height))
            {
                player2.isCollision = false;
            }

            if (CheckCollisionRecRec(player2.pos, player2.width, player2.height, ground.pos, ground.width, ground.height))
            {
                player2.isJumping = false;
                player2.gravity = 0;
            }
        }
    }
}

void BulletCollision()
{
    for (int i = 0; i < maxBullets; i++)
    {
        for (int j = 0; j < maxflyEnemy; j++)
        {
            //Player
            if (CheckCollisionRecRec(playerBullet[i].pos, playerBullet[i].width, playerBullet[i].height, flyEnemy[j].pos, flyEnemy[j].width, flyEnemy[j].height))
            {
                playerBullet[i].isMoving = false;
                playerBullet[i].isActive = false;

                flyEnemy[j].life--;
            }
            if (flyEnemy[j].life <= 0)
            {
                flyEnemy[j].isActive = false;
                player.points = player.points + 50;
                PlaySound(enemyDead);
                FlyEnemyRespawn();
            }

            if (multiplayer == true)
            {
                //Player2
                if (CheckCollisionRecRec(player2Bullet[i].pos, player2Bullet[i].width, player2Bullet[i].height, flyEnemy[j].pos, flyEnemy[j].width, flyEnemy[j].height))
                {
                    player2Bullet[i].isMoving = false;
                    player2Bullet[i].isActive = false;

                    flyEnemy[j].life--;
                }
                if (flyEnemy[j].life <= 0)
                {
                    flyEnemy[j].isActive = false;
                    player.points = player.points + 50;
                    PlaySound(enemyDead);
                    FlyEnemyRespawn();
                }
            }
        }
    }
}

void BulletCollisonLimit()
{
    for (int i = 0; i < maxBullets; i++)
    {
        //Player
        if (playerBullet[i].isMoving)
        {
            if (playerBullet[i].pos.y < 0)
            {
                playerBullet[i].isMoving = false;
                playerBullet[i].isActive = false;
            }
            if (playerBullet[i].pos.y >= screenHeight)
            {
                playerBullet[i].isMoving = false;
                playerBullet[i].isActive = false;
            }
        }

        if (multiplayer == true)
        {
            //Player2
            if (player2Bullet[i].isMoving)
            {
                if (player2Bullet[i].pos.y < 0)
                {
                    player2Bullet[i].isMoving = false;
                    player2Bullet[i].isActive = false;
                }
                if (player2Bullet[i].pos.y >= screenHeight)
                {
                    player2Bullet[i].isMoving = false;
                    player2Bullet[i].isActive = false;
                }
            }
        }
    }
}

void FlyEnemyCollisionLimit()
{
    for (int i = 0; i < maxflyEnemy; i++)
    {
        if (flyEnemy[i].isMoving)
        {
            if (flyEnemy[i].pos.x >= screenWidth + flyEnemy[i].width)
            {
                flyEnemy[i].pos.x = static_cast<float>(screenWidth / -2.5);
                flyEnemy[i].pos.y = static_cast<float>(screenHeight / -2.5);
            }
        }
    }
}

void MouseMovement()
{
    mouse.position = GetMousePosition();
}

void ObstacleMovement()
{
    obstacle.pos.x -= obstacle.speed * GetFrameTime();

    ObstacleTeleport();
}

void ObstacleTeleport()
{
    if (obstacle.pos.x > screenWidth - obstacle.width)
    {
        obstacle.pos.x = static_cast<float>(screenWidth / screenWidth);
    }

    if (obstacle.pos.x < screenWidth / screenWidth - obstacle.width)
    {
        player.points = player.points + 25;
        obstacle.pos.x = screenWidth - obstacle.width;
    }
}

void PlayerMovement()
{
    if (player.isActive == true)
    {
        if (IsKeyDown(KEY_A))
        {
            player.pos.x -= player.speed * GetFrameTime();
        }

        if (IsKeyDown(KEY_D))
        {
            player.pos.x += player.speed * GetFrameTime();
        }

        if (IsKeyDown(KEY_W) && player.isJumping == false)
        {
            PlayerJump(player);
        }

        if (IsKeyPressed(KEY_SPACE))
        {
            if (!restartMenu.isActive && !pauseMenu.isActive)
            {
                PlaySound(playerShot);
            }

            for (int i = 0; i < maxBullets; i++)
            {
                if (playerBullet[i].isActive == false)
                {
                    if (!playerBullet[i].isMoving)
                    {
                        playerBullet[i].isActive = true;
                        playerBullet[i].isMoving = true;

                        break;
                    }
                }
            }
        }
        if (player.isJumping == true && player.pos.y < ground.pos.y)
        {
            player.gravity = player.gravity + player.jumpForce * GetFrameTime();
            player.pos.y = player.pos.y + player.gravity * GetFrameTime();
        }

        PlayerLimit(player, screenWidth);
    }
}

void Player2Movement()
{
    if (player2.isActive == true)
    {
        if (IsKeyDown(KEY_LEFT))
        {
            player2.pos.x -= player2.speed * GetFrameTime();
        }

        if (IsKeyDown(KEY_RIGHT))
        {
            player2.pos.x += player2.speed * GetFrameTime();
        }

        if (IsKeyDown(KEY_UP) && player2.isJumping == false)
        {
            PlayerJump(player2);
        }

        if (IsKeyPressed(KEY_ENTER))
        {
            if (!restartMenu.isActive && !pauseMenu.isActive)
            {
                PlaySound(playerShot);
            }
            for (int i = 0; i < maxBullets; i++)
            {
                if (player2Bullet[i].isActive == false)
                {
                    if (!player2Bullet[i].isMoving)
                    {
                        player2Bullet[i].isActive = true;
                        player2Bullet[i].isMoving = true;

                        break;
                    }
                }
            }
        }
        if (player2.isJumping == true && player2.pos.y < ground.pos.y)
        {
            player2.gravity = player2.gravity + player2.jumpForce * GetFrameTime();
            player2.pos.y = player2.pos.y + player2.gravity * GetFrameTime();
        }

        PlayerLimit(player2, screenWidth);
    }
}

void PlayerJump(Player& players)
{
    players.gravity = -250;
    players.pos.y = players.pos.y + players.gravity * GetFrameTime();

    if (players.pos.y < 650)
    {
        players.isJumping = true;
    }
}

void PlayerBulletMovement()
{
    for (int i = 0; i < maxBullets; i++)
    {
        //Player
        if (playerBullet[i].isMoving == false)
        {
            playerBullet[i].pos.y = player.pos.y;
            playerBullet[i].pos.x = player.pos.x;
        }
        if (playerBullet[i].isMoving)
        {
            playerBullet[i].pos.y -= playerBullet[i].speed * GetFrameTime();
        }

        if (multiplayer == true)
        {
            //Player2
            if (player2Bullet[i].isMoving == false)
            {
                player2Bullet[i].pos.y = player2.pos.y;
                player2Bullet[i].pos.x = player2.pos.x;
            }
            if (player2Bullet[i].isMoving)
            {
                player2Bullet[i].pos.y -= player2Bullet[i].speed * GetFrameTime();
            }
        }
    }
}

void FlyEnemyMovement()
{
    int maxLim = 300;
    int minLim = 15;
    int mov = 5;

    for (int i = 0; i < maxflyEnemy; i++)
    {
        if (flyEnemy[i].isMoving == true)
        {
            if (flyEnemy[i].moveDown == false)
            {
                flyEnemy[i].pos.x += flyEnemy[i].speed * GetFrameTime();
                flyEnemy[i].pos.y += sin(flyEnemy[i].speed * GetFrameTime()) * mov;

                if (flyEnemy[i].pos.y > maxLim)
                {
                    flyEnemy[i].moveDown = true;
                }
            }

            if (flyEnemy[i].moveDown == true)
            {
                flyEnemy[i].pos.x += flyEnemy[i].speed * GetFrameTime();
                flyEnemy[i].pos.y -= sin(flyEnemy[i].speed * GetFrameTime()) * mov;

                if (flyEnemy[i].pos.y < minLim)
                {
                    flyEnemy[i].moveDown = false;
                }
            }
        }
    }
}

void BackgroundMovement()
{
    sky.pos.x -= sky.speed * GetFrameTime();
    sky2.pos.x -= sky2.speed * GetFrameTime();

    city.pos.x -= city.speed * GetFrameTime();
    city2.pos.x -= city2.speed * GetFrameTime();

    hill.pos.x -= hill.speed * GetFrameTime();
    hill2.pos.x -= hill2.speed * GetFrameTime();

    BackgroundParallax(sky, screenWidth);
    BackgroundParallax(sky2, screenWidth);

    BackgroundParallax(city, screenWidth);
    BackgroundParallax(city2, screenWidth);

    BackgroundParallax(hill, screenWidth);
    BackgroundParallax(hill2, screenWidth);
}

void FlyEnemyRespawn()
{
    for (int i = 0; i < maxflyEnemy; i++)
    {
        if (flyEnemy[i].isActive == false)
        {
            flyEnemy[i].pos.x = static_cast<float>(screenWidth / -1.13);
            flyEnemy[i].pos.y = static_cast<float>(screenHeight / -1.13);

            flyEnemy[i].life = 2;
            flyEnemy[i].isActive = true;
        }
    }
}

void RestartGame()
{
    if (multiplayer == false)
    {
        //Player
        multiplayer = false;

        player.pos.x = static_cast<float>(screenWidth / 6);
        player.pos.y = static_cast<float>(screenHeight / 1.165);
        player.width = 80;
        player.height = 40;
        player.speed = 420;
        player.lifes = 1;
        player.points = 0;
        player.isCollision = false;
        player.isJumping = false;
        player.isAlive = true;
        player.win = false;
        player.isActive = true;
    }

    if (multiplayer == true)
    {
        multiplayer = true;
        
        //Player
        player.pos.x = static_cast<float>(screenWidth / 6);
        player.pos.y = static_cast<float>(screenHeight / 1.165);
        player.width = 80;
        player.height = 40;
        player.speed = 420;
        player.lifes = 1;
        player.points = 0;
        player.isCollision = false;
        player.isJumping = false;
        player.isAlive = true;
        player.win = false;
        player.isActive = true;

        //Player2
        player2.pos.x = static_cast<float>(screenWidth / 4);
        player2.pos.y = static_cast<float>(screenHeight / 1.165);
        player2.width = 80;
        player2.height = 40;
        player2.speed = 420;
        player2.lifes = 1;
        player2.points = 0;
        player2.isCollision = false;
        player2.isJumping = false;
        player2.isAlive = true;
        player2.win = false;
        player2.isActive = true;
    }

    //Bullet
        //PlayerBullets

    for (int i = 0; i < maxBullets; i++)
    {
        playerBullet[i].isActive = false;
        playerBullet[i].isMoving = false;
        playerBullet[i].pos.y = player.pos.y;
        playerBullet[i].pos.x = player.pos.x;

        player2Bullet[i].isActive = false;
        player2Bullet[i].isMoving = false;
        player2Bullet[i].pos.y = player.pos.y;
        player2Bullet[i].pos.x = player.pos.x;
    }

    //Obstacle
    obstacle.pos.x = static_cast<float>(screenWidth - 60);
    obstacle.pos.y = static_cast<float>(screenHeight / 1.25);
    obstacle.width = 60;
    obstacle.height = 100;
    obstacle.speed = 400;

    //Ground
    ground.pos.x = static_cast<float>(screenWidth / screenWidth);
    ground.pos.y = static_cast<float>(screenHeight / 1.1);
    ground.width = static_cast<float>(screenWidth);
    ground.height = 70;
    ground.color = YELLOW;

    //Mouse
    mouse.position.x = 0;
    mouse.position.y = 0;
    mouse.width = 30.0f;
    mouse.height = 30.0f;
    mouse.mouseRec = GetRecMouse(mouse);

    //Background
        //Sky
    sky.pos.x = static_cast<float>(screenWidth / screenWidth);

    sky2.pos.x = static_cast<float>(screenWidth / screenWidth + sky.width);

    //City
    city.pos.x = static_cast<float>(screenWidth / screenWidth);
    city.pos.y = static_cast<float>((screenHeight / screenHeight) - 60);
    city.speed = 200;

    city2.pos.x = static_cast<float>(screenWidth / screenWidth + city.width);
    city2.pos.y = static_cast<float>((screenHeight / screenHeight) - 60);
    city2.speed = 200;

    //Hill
    hill.pos.x = static_cast<float>(screenWidth / screenWidth);
    hill.pos.y = static_cast<float>((screenHeight / 1.28));
    hill.speed = 400;

    hill2.pos.x = static_cast<float>(screenWidth / screenWidth + hill.width);
    hill2.pos.y = static_cast<float>((screenHeight / 1.28));
    hill2.speed = 400;

    //FlyEnemy 

    for (int i = 0; i < maxflyEnemy; i++)
    {
        flyEnemy[0].pos.x = static_cast<float>(screenWidth / -2.5);
        flyEnemy[0].pos.y = static_cast<float>(screenHeight / -2.5);

        flyEnemy[1].pos.x = static_cast<float>(screenWidth / -1.9);
        flyEnemy[1].pos.y = static_cast<float>(screenHeight / -1.9);

        flyEnemy[2].pos.x = static_cast<float>(screenWidth / -1.5);
        flyEnemy[2].pos.y = static_cast<float>(screenHeight / -1.5);

        flyEnemy[3].pos.x = static_cast<float>(screenWidth / -1.22);
        flyEnemy[3].pos.y = static_cast<float>(screenHeight / -1.22);

        flyEnemy[4].pos.x = static_cast<float>(screenWidth / -1.05);
        flyEnemy[4].pos.y = static_cast<float>(screenHeight / -1.05);
    }

    //RestartMenu
    restartMenu.isActive = false;
    pause = false;
}

void UnloadData()
{
    UnloadFont(gameFont);

    UnloadTexture(player.tex);
    UnloadTexture(player2.tex);

    UnloadTexture(obstacle.tex);

    UnloadTexture(sky.tex);
    UnloadTexture(sky2.tex);

    UnloadTexture(city.tex);
    UnloadTexture(city2.tex);

    UnloadTexture(hill.tex);
    UnloadTexture(hill2.tex);

    UnloadTexture(mouse.texture);

    UnloadTexture(ground.tex);

    UnloadTexture(restartMenu.texture);
    UnloadTexture(pauseMenu.texture);
    UnloadTexture(pauseButtonOff.texture);
    UnloadTexture(pauseButtonOn.texture);

    UnloadTexture(menuBackground);
    UnloadTexture(subMenusBackground);

    UnloadMusicStream(music);
    UnloadSound(playerDead);
    UnloadSound(playerShot);
    UnloadSound(enemyDead);
}