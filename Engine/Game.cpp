/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"

using std::string;

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	Asgore(L"Music/mus_vsasgore.mp3"),
	Papyrus(L"Music/mus_papyrus.mp3"),
	Sans(L"Music/mus_muscle.mp3"),
	Mettaton(L"Music/mus_mettatonbattle.mp3"),
	Megalovania(L"Music/mus_zz_megalovania.mp3"),
	Fallen(L"ASS"),
	PapyrusB(L"ASS")
{
}

void Game::Go()
{
	gfx.BeginFrame();
	/*if (init == 0) {
		BootScreen();
	}*/
	ComposeFrame();
	gfx.EndFrame();
}

void Game::ComposeFrame() {
	gfx.Print("dima  musicbox", 400, 20, 1);
	if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
		gfx.Print("OOOOOOOOOOOOOOOOOOOO", 400, 320, 1);
		gfx.Print("OOOOOOOOOOOOOOOOOOOO", 400, 280, 1);
		gfx.Print("O                  O", 400, 300, 1);
	} else if (wnd.kbd.KeyIsPressed(VK_ESCAPE)) {
		gfx.Print("XXXXXXXXXXXXXXXXXXXX", 400, 320, 1);
		gfx.Print("XXXXXXXXXXXXXXXXXXXX", 400, 280, 1);
		gfx.Print("X                  X", 400, 300, 1);
	} else {
		gfx.Print("IIIIIIIIIIIIIIIIIIII", 400, 320, 1);
		gfx.Print("IIIIIIIIIIIIIIIIIIII", 400, 280, 1);
		gfx.Print("I                  I", 400, 300, 1);
	}
	gfx.Print("megalovania", 400, 200 + y, 1);
	gfx.Print("sans", 400, 250 + y, 1);
	gfx.Print("asgore_battle", 400, 300 + y, 1);
	gfx.Print("papyrus", 400, 350 + y, 1);
	gfx.Print("mettaton_battle", 400, 400 + y, 1);
	gfx.Print("papyrus_battle", 400, 450 + y, 1);
	gfx.Print("fallen down", 400, 500 + y, 1);
}