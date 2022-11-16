#include "Window/Menu.h"


MenuButton play;
MenuButton controlls;
MenuButton rules;
MenuButton credits;
MenuButton quit;
MenuButton returnMenu;

void InitMenu()
{
	//Play Button

	play.pos.x = static_cast<float>(GetScreenWidth() / 20);
	play.pos.y = static_cast<float>(GetScreenHeight() / 3.2);
	play.width = static_cast<float>(GetScreenWidth() / 5.7);
	play.height = static_cast<float>(GetScreenHeight() / 10);
	play.size = 40;
	play.isActive = false;

	play.color = ORANGE;

	//Controlls Button

	controlls.pos.x = static_cast<float>(GetScreenWidth() / 20);
	controlls.pos.y = static_cast<float>(GetScreenHeight() / 2.35);
	controlls.width = static_cast<float>(GetScreenWidth() / 2.53);
	controlls.height = static_cast<float>(GetScreenHeight() / 10);
	controlls.size = 40;
	controlls.isActive = false;

	controlls.color = ORANGE;

	//Rules Button

	rules.pos.x = static_cast<float>(GetScreenWidth() / 20);
	rules.pos.y = static_cast<float>(GetScreenHeight() / 1.84);
	rules.width = static_cast<float>(GetScreenWidth() / 4.55);
	rules.height = static_cast<float>(GetScreenHeight() / 10);
	rules.size = 40;
	rules.isActive = false;

	rules.color = ORANGE;

	//Credits Button

	credits.pos.x = static_cast<float>(GetScreenWidth() / 1.5);
	credits.pos.y = static_cast<float>(GetScreenHeight() / 1.1);
	credits.width = static_cast<float>(GetScreenWidth() / 3.25);
	credits.height = static_cast<float>(GetScreenHeight() / 10);
	credits.size = 40;
	credits.isActive = false;

	credits.color = ORANGE;

	//Quit Button

	quit.pos.x = static_cast<float>(GetScreenWidth() / 20);
	quit.pos.y = static_cast<float>(GetScreenHeight() / 1.53);
	quit.width = static_cast<float>(GetScreenWidth() / 5.7);
	quit.height = static_cast<float>(GetScreenHeight() / 10);
	quit.size = 40;
	quit.isActive = false;

	quit.color = ORANGE;

	//ReturnMenu Button

	returnMenu.pos.x = static_cast<float>(GetScreenWidth() / 2.5);
	returnMenu.pos.y = static_cast<float>(GetScreenHeight() / 1.1);
	returnMenu.width = static_cast<float>(GetScreenWidth() / 5.6);
	returnMenu.height = static_cast<float>(GetScreenHeight() / 10);
	returnMenu.size = 40;
	returnMenu.isActive = false;

	returnMenu.color = ORANGE;
}

void MenuCollisions(Mouse& mouse, int& optionSelect)
{
	//Play Button
	if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 20), static_cast<float>(GetScreenHeight() / 3.5), static_cast<float>(play.width), static_cast<float>(play.height) }) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
	{
		play.color = BLUE;
	}

	else
	{
		play.color = ORANGE;
	}

	//Controlls Button
	if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 20), static_cast<float>(GetScreenHeight() / 2.5), static_cast<float>(controlls.width), static_cast<float>(controlls.height) }) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
	{
		controlls.color = BLUE;
	}

	else
	{
		controlls.color = ORANGE;
	}

	//Rules Button
	if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 20), static_cast<float>(GetScreenHeight() / 1.94), static_cast<float>(rules.width), static_cast<float>(rules.height) }) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
	{
		rules.color = BLUE;
	}

	else
	{
		rules.color = ORANGE;
	}

	//Credits Button
	if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 1.5), static_cast<float>(GetScreenHeight() / 1.13), static_cast<float>(credits.width), static_cast<float>(credits.height) }) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
	{
		credits.color = BLUE;
	}

	else
	{
		credits.color = ORANGE;
	}

	//

	//Quit Button
	if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 20), static_cast<float>(GetScreenHeight() / 1.59), static_cast<float>(quit.width), static_cast<float>(quit.height) }) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
	{
		quit.color = BLUE;
	}

	else
	{
		quit.color = ORANGE;
	}

	//ReturnMenu Button
	if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 2.5), static_cast<float>(GetScreenHeight() / 1.1), static_cast<float>(quit.width), static_cast<float>(quit.height) }) && optionSelect != 1)
	{
		returnMenu.color = BLUE;
	}

	else
	{
		returnMenu.color = ORANGE;
	}
}

void MenuInputs(Mouse& mouse, int& optionSelect, bool& playGame)
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

		if (CheckCollisionPointRec(mouse.position, { GetScreenWidth() / 2.5f, GetScreenHeight() / 2.5f, 190, 85 }))
		{
			if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
			{
				OpenURL("https://feco-games.itch.io/");
			}
		}

		if (CheckCollisionPointRec(mouse.position, { GetScreenWidth() / 2.5f, GetScreenHeight() / 1.4f, 190, 85, }))
		{
			if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
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

void DrawMenu(Font gameFont)
{
	ClearBackground(BLACK);
	DrawTextEx(gameFont, "  Moon\nPatrol", { static_cast<float>(GetScreenWidth() / 20) , static_cast<float>(GetScreenHeight() / 20) }, 60, 0, GOLD);

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

void DrawControlls(Font gameFont)
{
	ClearBackground(BLACK);

	DrawTextEx(gameFont, "Controlls", { static_cast<float>(GetScreenWidth() / 2.8) , static_cast<float>(GetScreenHeight() / 15) }, 60, 0, ORANGE);

	//ReturnMenu Button

	DrawRectangle(static_cast<int>(GetScreenWidth() / 2.5), static_cast<int>(GetScreenHeight() / 1.1), static_cast<int>(returnMenu.width), static_cast<int>(returnMenu.height), BLANK);
	DrawTextEx(gameFont, "MENU", returnMenu.pos, static_cast<float>(returnMenu.size), 0, returnMenu.color);
}

void DrawRules(Font gameFont)
{
	ClearBackground(BLACK);

	DrawTextEx(gameFont, "RULES", { static_cast<float>(GetScreenWidth() / 2.7) , static_cast<float>(GetScreenHeight() / 15) }, 60, 0, ORANGE);

	DrawTextEx(gameFont, "Play as a pilot who must escape from a city besieged by aliens.\nYou have 3 lives, if you hit an obstacle or an enemy\nprojectile you lose.",
		{ static_cast<float>(GetScreenWidth() / 8) , static_cast<float>(GetScreenHeight() / 5) }, 30, 0, ORANGE);

	//ReturnMenu Button
	DrawRectangle(static_cast<int>(GetScreenWidth() / 2.5), static_cast<int>(GetScreenHeight() / 1.1), static_cast<int>(returnMenu.width), static_cast<int>(returnMenu.height), BLANK);
	DrawTextEx(gameFont, "MENU", returnMenu.pos, static_cast<float>(returnMenu.size), 0, returnMenu.color);
}

void DrawCredits(Font gameFont)
{
	ClearBackground(BLACK);

	DrawTextEx(gameFont, "CREDITS", { static_cast<float>(GetScreenWidth() / 3.8) , static_cast<float>(GetScreenHeight() / 15) }, 60, 0, ORANGE);

	DrawRectangle(static_cast<int>(GetScreenWidth() / 2.5), GetScreenHeight() / 2.5, 190, 85, BLACK);
	DrawRectangle(static_cast<int>(GetScreenWidth() / 2.5), GetScreenHeight() / 2.5, 180, 75, RED);
	DrawText("Itch.io", static_cast<int>(GetScreenWidth() / 2.4), static_cast<int>(GetScreenHeight() / 2.4), 50, BLACK);
	DrawRectangle(250, GetScreenHeight() / 4, 550, 85, BLACK);
	DrawRectangle(255, GetScreenHeight() / 4, 540, 75, WHITE);
	DrawText("Facundo Santos", static_cast<int>(GetScreenWidth() / 3.2), static_cast<int>(GetScreenHeight() / 3.8), 50, BLACK);
	
	DrawRectangle(static_cast<int>(GetScreenWidth() / 2.5), GetScreenHeight() / 1.4, 190, 85, BLACK);
	DrawRectangle(static_cast<int>(GetScreenWidth() / 2.5), GetScreenHeight() / 1.4, 180, 75, RED);
	DrawText("Itch.io", static_cast<int>(GetScreenWidth() / 2.4), static_cast<int>(GetScreenHeight() / 1.35), 50, BLACK);
	DrawRectangle(GetScreenWidth() / 3.8, GetScreenHeight() / 1.7, 550, 85, BLACK);
	DrawRectangle(GetScreenWidth() / 3.8, GetScreenHeight() / 1.7, 540, 75, WHITE);
	DrawText("Nicolas Ramos Marin", static_cast<int>(GetScreenWidth() / 3.6), static_cast<int>(GetScreenHeight() / 1.7), 50, BLACK);

	DrawTextEx(gameFont, "FONT", { static_cast<float>(GetScreenWidth() / 2.3) , static_cast<float>(GetScreenHeight() / 2) }, 30, 0, GOLD);
	DrawRectangle(static_cast<int>(GetScreenWidth() / 2.5), GetScreenHeight() / 2.5, 190, 85, BLACK);

	//ReturnMenu Button
	DrawRectangle(static_cast<int>(GetScreenWidth() / 2.5), static_cast<int>(GetScreenHeight() / 1.1), static_cast<int>(returnMenu.width), static_cast<int>(returnMenu.height), BLANK);
	DrawTextEx(gameFont, "MENU", returnMenu.pos, static_cast<float>(returnMenu.size), 0, returnMenu.color);
}


//void DrawCredits()
//{
//	if (CheckCollisionPointRec(mousePosition, { GetScreenWidth() / 2.5f, GetScreenHeight() / 2.5f, 190, 85 }))
//	{
//		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
//		{
//			OpenURL("https://feco-games.itch.io/");
//		}
//	}
//
//	if (CheckCollisionPointRec(mousePosition, { GetScreenWidth() / 2.5f, GetScreenHeight() / 1.4f, 190, 85, }))
//	{
//		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
//		{
//			OpenURL("https://nicorm.itch.io/");
//		}
//	}
//
//	DrawRectangle(10, 40, 45, 45, RED);
//	DrawText("x", 20, 35, 50, WHITE);
//
//	DrawRectangle(static_cast<int>(GetScreenWidth() / 2.5), GetScreenHeight() / 2.5, 190, 85, BLACK);
//	DrawRectangle(static_cast<int>(GetScreenWidth() / 2.5), GetScreenHeight() / 2.5, 180, 75, RED);
//	DrawText("Itch.io", static_cast<int>(GetScreenWidth() / 2.4), static_cast<int>(GetScreenHeight() / 2.4), 50, BLACK);
//	DrawRectangle(250, GetScreenHeight() / 4, 550, 85, BLACK);
//	DrawRectangle(255, GetScreenHeight() / 4, 540, 75, WHITE);
//
//	DrawText("Facundo Santos", static_cast<int>(GetScreenWidth() / 3.2), static_cast<int>(GetScreenHeight() / 3.8), 50, BLACK);
//
//	DrawRectangle(static_cast<int>(GetScreenWidth() / 2.5), GetScreenHeight() / 1.4, 190, 85, BLACK);
//	DrawRectangle(static_cast<int>(GetScreenWidth() / 2.5), GetScreenHeight() / 1.4, 180, 75, RED);
//	DrawText("Itch.io", static_cast<int>(GetScreenWidth() / 2.4), static_cast<int>(GetScreenHeight() / 1.35), 50, BLACK);
//	DrawRectangle(GetScreenWidth() / 3.8, GetScreenHeight() / 1.7, 550, 85, BLACK);
//	DrawRectangle(GetScreenWidth() / 3.8, GetScreenHeight() / 1.7, 540, 75, WHITE);
//
//	DrawText("Nicolas Ramos Marin", static_cast<int>(GetScreenWidth() / 3.6), static_cast<int>(GetScreenHeight() / 1.7), 50, BLACK);
