#pragma once
#include "raylib.h"

struct Parallax
{
	float furtherSpeed;
	float middleSpeed;
	float closerSpeed;
	Vector2 furtherPosition1{};
	Vector2 furtherPosition2{};
	Vector2 middlePosition1{};
	Vector2 middlePosition2{};
	Vector2 closerPosition1{};
	Vector2 closerPosition2{};
	Rectangle furtherBG1{};
	Rectangle furtherBG2{};
	Rectangle middleBG1{};
	Rectangle middleBG2{};
	Rectangle closerBG1{};
	Rectangle closerBG2{};
};

Parallax CreateParallax(Parallax& parallax);

void DrawParallax(Parallax parallax);