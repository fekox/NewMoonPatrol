#pragma once
#include "raylib.h"

struct SubMenu
{
    Vector2 pos;

    float width;
    float height;

    Texture texture;

    bool isActive;
};

struct Button
{
    Vector2 pos;

    float width;
    float height;

    int size;

    Texture texture;

    Color color;
};

void PlayGame();
void InitGame();
void GameLoop();
void Update();
void Draw();

void RestartGame();
void UnloadData();
