#include "Objects/Background.h"

Background CreateBackground(int screenWidth, int screenHeight)
{
	Background backG;

	backG.pos.x = static_cast<float>(screenWidth / screenWidth);
	backG.pos.y = static_cast<float>(screenHeight / screenWidth);

	backG.width = 1365;
	backG.height = static_cast<float>(screenHeight);

	backG.scale = 0.5;

	backG.speed = 70;

	return backG;
}
	
void DrawBackground(Background& back)
{
	DrawTexture(back.tex, static_cast<int>(back.pos.x), static_cast<int>(back.pos.y), WHITE);
}

void BackgroundParallax(Background& back, int screenWidth)
{
	float diff = back.width - screenWidth;

	if (back.pos.x > screenWidth + back.width)
	{
		back.pos.x = static_cast<float>(screenWidth + diff);
	}

	if (back.pos.x < screenWidth / screenWidth - back.width)
	{
		back.pos.x = static_cast<float>(screenWidth + diff);
	}
}
