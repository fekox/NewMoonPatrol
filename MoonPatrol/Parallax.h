#pragma once
#include "raylib.h"

struct Parallax
{
	Rectangle furtherBG1{};
	Rectangle furtherBG2{};
	Rectangle middleBG1{};
	Rectangle middleBG2{};
	Rectangle closerBG1{};
	Rectangle closerBG2{};
};

Parallax CreateParallax(Parallax& parallax);

void DrawParallax(Parallax parallax);