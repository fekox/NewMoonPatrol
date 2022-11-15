#pragma once

enum class GameState
{
	GAMETITLE = 0,
	GAME,
	HOWTOPLAY,
	CREDITS,
	EXIT
};

void RunGame();
