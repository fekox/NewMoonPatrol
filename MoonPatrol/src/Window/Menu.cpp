#include "Window/Menu.h"

#include "Window/GameLoop.h"

MenuButton play;
MenuButton controlls;
MenuButton rules;
MenuButton credits;
MenuButton quit;
MenuButton returnMenu;

MenuButton ichiolinkF;
MenuButton ichiolinkN;

void InitMenu()
{

	//Play Button

	play.pos.x = static_cast<float>(GetScreenWidth() / 20);
	play.pos.y = static_cast<float>(GetScreenHeight() / 3.2);
	play.width = static_cast<float>(GetScreenWidth() / 5.7);
	play.height = static_cast<float>(GetScreenHeight() / 10);
	play.size = 40;
	play.isActive = false;

	play.color = WHITE;

	//Controlls Button

	controlls.pos.x = static_cast<float>(GetScreenWidth() / 20);
	controlls.pos.y = static_cast<float>(GetScreenHeight() / 2.35);
	controlls.width = static_cast<float>(GetScreenWidth() / 2.53);
	controlls.height = static_cast<float>(GetScreenHeight() / 10);
	controlls.size = 40;
	controlls.isActive = false;

	controlls.color = WHITE;

	//Rules Button

	rules.pos.x = static_cast<float>(GetScreenWidth() / 20);
	rules.pos.y = static_cast<float>(GetScreenHeight() / 1.84);
	rules.width = static_cast<float>(GetScreenWidth() / 4.55);
	rules.height = static_cast<float>(GetScreenHeight() / 10);
	rules.size = 40;
	rules.isActive = false;

	rules.color = WHITE;

	//Credits Button

	credits.pos.x = static_cast<float>(GetScreenWidth() / 1.5);
	credits.pos.y = static_cast<float>(GetScreenHeight() / 1.1);
	credits.width = static_cast<float>(GetScreenWidth() / 3.25);
	credits.height = static_cast<float>(GetScreenHeight() / 10);
	credits.size = 40;
	credits.isActive = false;

	credits.color = WHITE;

	//Quit Button

	quit.pos.x = static_cast<float>(GetScreenWidth() / 20);
	quit.pos.y = static_cast<float>(GetScreenHeight() / 1.53);
	quit.width = static_cast<float>(GetScreenWidth() / 5.7);
	quit.height = static_cast<float>(GetScreenHeight() / 10);
	quit.size = 40;
	quit.isActive = false;

	quit.color = WHITE;

	//ReturnMenu Button

	returnMenu.pos.x = static_cast<float>(GetScreenWidth() / 2.5);
	returnMenu.pos.y = static_cast<float>(GetScreenHeight() / 1.1);
	returnMenu.width = static_cast<float>(GetScreenWidth() / 5.6);
	returnMenu.height = static_cast<float>(GetScreenHeight() / 10);
	returnMenu.size = 40;
	returnMenu.isActive = false;

	returnMenu.color = WHITE;

	//itch.io Link Feko_Games

	ichiolinkF.pos.x = static_cast<float>(GetScreenWidth() / 8);
	ichiolinkF.pos.y = static_cast<float>(GetScreenHeight() / 2.6);
	ichiolinkF.width = static_cast<float>(GetScreenWidth() / 3.68);
	ichiolinkF.height = static_cast<float>(GetScreenHeight() / 10);
	ichiolinkF.size = 40;
	ichiolinkF.isActive = false;

	ichiolinkF.color = WHITE;

	//itch.io Link Nicorm

	ichiolinkN.pos.x = static_cast<float>(GetScreenWidth() / 1.6);
	ichiolinkN.pos.y = static_cast<float>(GetScreenHeight() / 2.6);
	ichiolinkN.width = static_cast<float>(GetScreenWidth() / 3.68);
	ichiolinkN.height = static_cast<float>(GetScreenHeight() / 10);
	ichiolinkN.size = 40;
	ichiolinkN.isActive = false;

	ichiolinkN.color = WHITE;
}

void MenuCollisions(Mouse& mouse, int& optionSelect)
{
	//Play Button
	if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 20), static_cast<float>(GetScreenHeight() / 3.5), static_cast<float>(play.width), static_cast<float>(play.height) }) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
	{
		play.color = GOLD;
	}

	else
	{
		play.color = WHITE;
	}

	//Controlls Button
	if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 20), static_cast<float>(GetScreenHeight() / 2.5), static_cast<float>(controlls.width), static_cast<float>(controlls.height) }) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
	{
		controlls.color = GOLD;
	}

	else
	{
		controlls.color = WHITE;
	}

	//Rules Button
	if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 20), static_cast<float>(GetScreenHeight() / 1.94), static_cast<float>(rules.width), static_cast<float>(rules.height) }) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
	{
		rules.color = GOLD;
	}

	else
	{
		rules.color = WHITE;
	}

	//Credits Button
	if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 1.5), static_cast<float>(GetScreenHeight() / 1.13), static_cast<float>(credits.width), static_cast<float>(credits.height) }) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
	{
		credits.color = GOLD;
	}

	else
	{
		credits.color = WHITE;
	}

	//itch.io Link Feko_Games
	if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 8), static_cast<float>(GetScreenHeight() / 2.8), static_cast<float>(ichiolinkF.width), static_cast<float>(ichiolinkF.height) }) && optionSelect == 4)
	{
		ichiolinkF.color = GOLD;
	}

	else
	{
		ichiolinkF.color = WHITE;
	}

	//itch.io Link Nicorm
	if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 1.6), static_cast<float>(GetScreenHeight() / 2.8), static_cast<float>(ichiolinkN.width), static_cast<float>(ichiolinkN.height) }) && optionSelect == 4)
	{
		ichiolinkN.color = GOLD;
	}

	else
	{
		ichiolinkN.color = WHITE;
	}

	//Quit Button
	if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 20), static_cast<float>(GetScreenHeight() / 1.59), static_cast<float>(quit.width), static_cast<float>(quit.height) }) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
	{
		quit.color = GOLD;
	}

	else
	{
		quit.color = WHITE;
	}

	//ReturnMenu Button
	if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 2.5), static_cast<float>(GetScreenHeight() / 1.1), static_cast<float>(quit.width), static_cast<float>(quit.height) }) && optionSelect != 1)
	{
		returnMenu.color = GOLD;
	}

	else
	{
		returnMenu.color = WHITE;
	}
}

void MenuInputs(Mouse& mouse, int& optionSelect, bool& playGame, SubMenu& gameModeMenu)
{
	if (!playGame)
	{
		//Play Button
		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 20), static_cast<float>(GetScreenHeight() / 3.5), static_cast<float>(play.width), static_cast<float>(play.height) }))
		{
			if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
			{
				optionSelect = 1;
				play.isActive = true;
				gameModeMenu.isActive = true;
				playGame = true;
				HideCursor();
			}
		}

		//Controlls Button
		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 20), static_cast<float>(GetScreenHeight() / 2.5), static_cast<float>(controlls.width), static_cast<float>(controlls.height) }))
		{
			if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
			{
				optionSelect = 2;
			}
		}

		//Rules Button
		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 20), static_cast<float>(GetScreenHeight() / 1.94), static_cast<float>(rules.width), static_cast<float>(rules.height) }))
		{
			if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
			{
				optionSelect = 3;
			}
		}

		//Credits Button
		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 1.5), static_cast<float>(GetScreenHeight() / 1.13), static_cast<float>(credits.width), static_cast<float>(credits.height) }))
		{
			if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
			{
				optionSelect = 4;
			}
		}

		//itch.io Link Feko_Games
		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 8), static_cast<float>(GetScreenHeight() / 2.8), static_cast<float>(ichiolinkF.width), static_cast<float>(ichiolinkF.height) }))
		{
			if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && optionSelect == 4)
			{
				OpenURL("https://feco-games.itch.io/");
			}
		}

		//itch.io Link Nicorm
		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 1.6), static_cast<float>(GetScreenHeight() / 2.8), static_cast<float>(ichiolinkN.width), static_cast<float>(ichiolinkN.height) }))
		{
			if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && optionSelect == 4)
			{
				OpenURL("https://nicorm.itch.io/");
			}
		}

		//Quit Button
		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 20), static_cast<float>(GetScreenHeight() / 1.59), static_cast<float>(quit.width), static_cast<float>(quit.height) }))
		{
			if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
			{
				optionSelect = 5;
			}
		}

		//ReturnMenu Button
		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 2.5), static_cast<float>(GetScreenHeight() / 1.1), static_cast<float>(quit.width), static_cast<float>(quit.height) }))
		{
			if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && optionSelect != 1)
			{
				optionSelect = 0;
				playGame = false;
			}
		}
	}
}

void DrawMenu(Font gameFont, Texture menuBackground)
{
	ClearBackground(BLACK);

	//Menu Background
	DrawTexture(menuBackground, 0, 0, WHITE);

	DrawTextEx(gameFont, "  Pingu\nAttack", { static_cast<float>(GetScreenWidth() / 20) , static_cast<float>(GetScreenHeight() / 20) }, 60, 0, GOLD);

	//Play Button

	DrawRectangle(static_cast<int>(GetScreenWidth() / 20), static_cast<int>(GetScreenHeight() / 3.5), static_cast<int>(play.width), static_cast<int>(play.height), BLANK);
	DrawTextEx(gameFont, "PLAY", play.pos, static_cast<float>(play.size), 0, play.color);

	//Controlls Button

	DrawRectangle(static_cast<int>(GetScreenWidth() / 20), static_cast<int>(GetScreenHeight() / 2.5), static_cast<int>(controlls.width), static_cast<int>(controlls.height), BLANK);
	DrawTextEx(gameFont, "CONTROLLS", controlls.pos, static_cast<float>(controlls.size), 0, controlls.color);

	//Rules Button

	DrawRectangle(static_cast<int>(GetScreenWidth() / 20), static_cast<int>(GetScreenHeight() / 1.94), static_cast<int>(rules.width), static_cast<int>(rules.height), BLANK);
	DrawTextEx(gameFont, "RULES", rules.pos, static_cast<float>(rules.size), 0, rules.color);

	//Credits Button

	DrawRectangle(static_cast<int>(GetScreenWidth() / 1.5), static_cast<int>(GetScreenHeight() / 1.13), static_cast<int>(credits.width), static_cast<int>(credits.height), BLANK);
	DrawTextEx(gameFont, "CREDITS", credits.pos, static_cast<float>(credits.size), 0, credits.color);

	//Quit Button

	DrawRectangle(static_cast<int>(GetScreenWidth() / 20), static_cast<int>(GetScreenHeight() / 1.59), static_cast<int>(quit.width), static_cast<int>(quit.height), BLANK);
	DrawTextEx(gameFont, "QUIT", quit.pos, static_cast<float>(quit.size), 0, quit.color);
}

void DrawControlls(Font gameFont, Texture subMenusBackground)
{
	ClearBackground(BLACK);

	//Sub Menu Background
	DrawTexture(subMenusBackground, 0, 0, WHITE);

	DrawTextEx(gameFont, "Controlls", { static_cast<float>(GetScreenWidth() / 2.8) , static_cast<float>(GetScreenHeight() / 15) }, 60, 0, GOLD);

	DrawTextEx(gameFont, "PLAYER ONE\t\t\tPLAYER TWO", { static_cast<float>(GetScreenWidth() / 12) , static_cast<float>(GetScreenHeight() / 5) }, 40, 0, GOLD);

	//Player One
	DrawTextEx(gameFont, "move\tA D", { static_cast<float>(GetScreenWidth() / 8) , static_cast<float>(GetScreenHeight() / 3) }, 40, 0, WHITE);
	DrawTextEx(gameFont, "jump\t  W", { static_cast<float>(GetScreenWidth() / 8) , static_cast<float>(GetScreenHeight() / 2.4) }, 40, 0, WHITE);
	DrawTextEx(gameFont, "shoot\tSPACE",{ static_cast<float>(GetScreenWidth() / 8) , static_cast<float>(GetScreenHeight() / 2) }, 40, 0, WHITE);

	//Player Two
	DrawTextEx(gameFont, "move", { static_cast<float>(GetScreenWidth() / 1.8) , static_cast<float>(GetScreenHeight() / 3) }, 40, 0, WHITE); 
	DrawTextEx(gameFont, "LEFT\nARROW", { static_cast<float>(GetScreenWidth() / 1.55) , static_cast<float>(GetScreenHeight() / 3) }, 30, 0, WHITE);
	DrawTextEx(gameFont, "RIGHT\nARROW", { static_cast<float>(GetScreenWidth() / 1.2) , static_cast<float>(GetScreenHeight() / 3) }, 30, 0, WHITE);
	DrawTextEx(gameFont, "jump\t", { static_cast<float>(GetScreenWidth() / 1.8) , static_cast<float>(GetScreenHeight() / 2.1) }, 40, 0, WHITE);
	DrawTextEx(gameFont, "UP\nARROW", { static_cast<float>(GetScreenWidth() / 1.55) , static_cast<float>(GetScreenHeight() / 2.1) }, 30, 0, WHITE);
	DrawTextEx(gameFont, "shoot\tENTER", { static_cast<float>(GetScreenWidth() / 1.8) , static_cast<float>(GetScreenHeight() / 1.63) }, 40, 0, WHITE);

	//Pause
	DrawTextEx(gameFont, "PAUSE", { static_cast<float>(GetScreenWidth() / 12) , static_cast<float>(GetScreenHeight() / 1.5) }, 40, 0, GOLD);
	DrawTextEx(gameFont, "esc\tp ", { static_cast<float>(GetScreenWidth() / 7) , static_cast<float>(GetScreenHeight() / 1.3) }, 40, 0, WHITE);
	DrawTextEx(gameFont, "pause ", { static_cast<float>(GetScreenWidth() / 7) , static_cast<float>(GetScreenHeight() / 1.2) }, 40, 0, WHITE);
	DrawTextEx(gameFont, "button", { static_cast<float>(GetScreenWidth() / 7) , static_cast<float>(GetScreenHeight() / 1.15) }, 40, 0, WHITE);


	//ReturnMenu Button
	DrawRectangle(static_cast<int>(GetScreenWidth() / 2.5), static_cast<int>(GetScreenHeight() / 1.1), static_cast<int>(returnMenu.width), static_cast<int>(returnMenu.height), BLANK);
	DrawTextEx(gameFont, "MENU", returnMenu.pos, static_cast<float>(returnMenu.size), 0, returnMenu.color);
}

void DrawRules(Font gameFont, Texture subMenusBackground)
{
	ClearBackground(BLACK);

	//Sub Menu Background
	DrawTexture(subMenusBackground, 0, 0, WHITE);

	DrawTextEx(gameFont, "RULES", { static_cast<float>(GetScreenWidth() / 2.7) , static_cast<float>(GetScreenHeight() / 15) }, 60, 0, GOLD);

	DrawTextEx(gameFont, "Play as a pilot who must escape from a city besieged by aliens.\nYou have 1 live, if you hit an obstacle you lose.\n\nTo win you must make 150000 points.\n\nGood luck pilot.",
		{ static_cast<float>(GetScreenWidth() / 8) , static_cast<float>(GetScreenHeight() / 4) }, 30, 0, WHITE);

	//ReturnMenu Button
	DrawRectangle(static_cast<int>(GetScreenWidth() / 2.5), static_cast<int>(GetScreenHeight() / 1.1), static_cast<int>(returnMenu.width), static_cast<int>(returnMenu.height), BLANK);
	DrawTextEx(gameFont, "MENU", returnMenu.pos, static_cast<float>(returnMenu.size), 0, returnMenu.color);
}

void DrawCredits(Font gameFont, Texture subMenusBackground)
{
	ClearBackground(BLACK);

	//Sub Menu Background
	DrawTexture(subMenusBackground, 0, 0, WHITE);

	DrawTextEx(gameFont, "CREDITS", { static_cast<float>(GetScreenWidth() / 3.8) , static_cast<float>(GetScreenHeight() / 15) }, 60, 0, GOLD);

	//itch.io Link Feko_Games
	DrawText("Facundo Santos", static_cast<int>(GetScreenWidth() / 12), static_cast<int>(GetScreenHeight() / 3.8), 50, WHITE);
	DrawRectangle(static_cast<float>(GetScreenWidth() / 8), static_cast<float>(GetScreenHeight() / 2.8), static_cast<float>(ichiolinkF.width), static_cast<float>(ichiolinkF.height), BLANK);
	DrawTextEx(gameFont, "ITCH.IO", ichiolinkF.pos, static_cast<float>(ichiolinkF.size), 0, ichiolinkF.color);
	
	//itch.io Link Nicorm
	DrawText("Nicolas Ramos Marin", static_cast<int>(GetScreenWidth() / 1.8), static_cast<int>(GetScreenHeight() / 3.8), 40, WHITE);
	DrawRectangle(static_cast<float>(GetScreenWidth() / 1.6), static_cast<float>(GetScreenHeight() / 2.8), static_cast<float>(ichiolinkN.width), static_cast<float>(ichiolinkN.height), BLANK);
	DrawTextEx(gameFont, "ITCH.IO", ichiolinkN.pos, static_cast<float>(ichiolinkN.size), 0, ichiolinkN.color);
	
	DrawTextEx(gameFont, "FONT", { static_cast<float>(GetScreenWidth() / 2.3) , static_cast<float>(GetScreenHeight() / 2) }, 30, 0, GOLD);
	DrawText("https://www.dafont.com/es/babyblocks.font", static_cast<float>(GetScreenWidth() / 7) , static_cast<float>(GetScreenHeight() / 1.8), 30, WHITE);

	DrawTextEx(gameFont, "SPRITES", { static_cast<float>(GetScreenWidth() / 2.6) , static_cast<float>(GetScreenHeight() / 1.6) }, 30, 0, GOLD);
	DrawText("https://www.wallpaperflare.com/artistic-pixel-art-red-no-people-night-beauty-in-nature-wallpaper-zgmd", static_cast<float>(GetScreenWidth() / 20), static_cast<float>(GetScreenHeight() / 1.5), 18, WHITE);
	DrawText("https://www.youtube.com/watch?v=ffPSgY7oRh8", static_cast<float>(GetScreenWidth() / 5), static_cast<float>(GetScreenHeight() / 1.4), 20, WHITE);

	//ReturnMenu Button
	DrawRectangle(static_cast<int>(GetScreenWidth() / 2), static_cast<int>(GetScreenHeight() / 1.1), static_cast<int>(returnMenu.width), static_cast<int>(returnMenu.height), BLANK);
	DrawTextEx(gameFont, "MENU", returnMenu.pos, static_cast<float>(returnMenu.size), 0, returnMenu.color);
}