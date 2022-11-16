#pragma once

void Initialize();
void RunGame();
void GameDraw(bool exitWindow, Player& spaceShip, const Enemy& enemy, Parallax& parallax, PlayerBullet& playerBullet);
void Close();
