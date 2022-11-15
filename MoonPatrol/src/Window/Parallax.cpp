#include "Window/Parallax.h"
#include "raylib.h"

Parallax CreateParallax(Parallax& parallax)
{
	parallax.furtherSpeed = 50;
	parallax.middleSpeed = 100;
	parallax.closerSpeed = 200;
	parallax.furtherPosition1 = { 0, 0 };
	parallax.furtherPosition2 = { -1024, 0 };
	parallax.middlePosition1 = { 0, 350 };
	parallax.middlePosition2 = { -1024, 350 };
	parallax.closerPosition1 = { 0, 675 };
	parallax.closerPosition2 = { -1024, 675 };
	parallax.furtherBG1 = { parallax.furtherPosition1.x, parallax.furtherPosition1.y, 1024, 768 };
	parallax.furtherBG2 = { parallax.furtherPosition2.x, parallax.furtherPosition2.y, 1024, 768 };
	parallax.middleBG1 = { parallax.middlePosition1.x, parallax.middlePosition1.y, 1024, 500 };
	parallax.middleBG2 = { parallax.middlePosition2.x, parallax.middlePosition2.y, 1024, 500 };
	parallax.closerBG1 = { parallax.closerPosition1.x, parallax.closerPosition1.y, 1024, 675 };
	parallax.closerBG2 = { parallax.closerPosition2.x, parallax.closerPosition2.y, 1024, 675 };

	return parallax;
}

void DrawParallax(Parallax parallax)
{
	DrawRectangle(parallax.furtherPosition1.x, parallax.furtherPosition1.y, 1024, 675, BLUE);
	DrawRectangle(parallax.furtherPosition2.x, parallax.furtherPosition2.y, 1024, 675, DARKBLUE);
	DrawRectangle(parallax.middlePosition1.x, parallax.middlePosition1.y, 1024, 675, RED);
	DrawRectangle(parallax.middlePosition2.x, parallax.middlePosition2.y, 1024, 675, PINK);
	DrawRectangle(parallax.closerPosition1.x, parallax.closerPosition1.y, 1024, 675, GREEN);
	DrawRectangle(parallax.closerPosition2.x, parallax.closerPosition2.y, 1024, 675, DARKGREEN);
}