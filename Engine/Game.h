/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include <iostream>
#include <string>
#include "Sound.h"
#include <thread>
#include <Windows.h>

using std::string;

class Game
{
public:
	Game(class MainWindow& wnd);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	void Go();
private:
	void Input();
	void Draw();
	void Selection(int selec); 
	void printname(string name, int pos);
	void Select();
	void Stop();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	int y = 0, sel = 0, repeat = 0;
	const int selmax = 5, selmin = selmax - selmax - selmax;
	const int wid = gfx.ScreenWidth, hei = gfx.ScreenHeight, heim = hei / 2, widm = wid / 2;
	/********************************/
	bool key(unsigned char key) { if (wnd.kbd.KeyIsPressed(key)) { return true; } else { return false; } }
	Sound Error;
	Sound Sans;
	Sound Papyrus;
	Sound Asgore;
	Sound Mettaton;
	Sound Megalovania;
	Sound Fallen;
	Sound PapyrusB;
	Sound Ruins;
	Sound DummyB;
	Sound Undyne;
	Sound Story;
};