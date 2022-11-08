#include "Parallax.h"
#include "raylib.h"

Parallax CreateParallax(Parallax& parallax)
{
	parallax.furtherBG1 = { 0, 0, 1024, 768};
	parallax.furtherBG2 = { -1024, 0, 1024, 768};	
	parallax.middleBG1 = { 0, 350, 1024, 500};
	parallax.middleBG2 = { -1024, 350, 1024, 500};
	parallax.closerBG1 = { 0, 675, 1024, 500};
	parallax.closerBG2 = { -1024, 675, 1024, 500};

	return parallax;
}

void DrawParallax(Parallax parallax)
{
	DrawRectangleRec(parallax.furtherBG1, BLUE);
	DrawRectangleRec(parallax.furtherBG2, DARKBLUE);
	DrawRectangleRec(parallax.middleBG1, RED);
	DrawRectangleRec(parallax.middleBG2, PINK);
	DrawRectangleRec(parallax.closerBG1, GREEN);
	DrawRectangleRec(parallax.closerBG2, DARKGREEN);
}