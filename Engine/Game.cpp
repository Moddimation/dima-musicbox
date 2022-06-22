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
	Error(L"Music/mus_dance_of_dog.mp3"),
	Asgore(L"Music/mus_vsasgore.mp3"),
	Papyrus(L"Music/mus_papyrus.mp3"),
	Sans(L"Music/mus_muscle.mp3"),
	Mettaton(L"Music/mus_mettatonbattle.mp3"),
	Megalovania(L"Music/mus_zz_megalovania.mp3"),
	Fallen(L"Music/mus_fallendown2.mp3"),
	PapyrusB(L"Music/mus_papyrusboss.mp3"),
	Ruins(L"Music/mus_ruins.mp3"),
	DummyB(L"Music/mus_dummybattle.mp3")
{
}

void Game::Go()
{
	gfx.BeginFrame();
	std::thread draw(&Game::Draw, this);
	std::thread input(&Game::Input, this);
	draw.join(); input.join();
	gfx.EndFrame();
}

void Game::Input() {
	if (wnd.kbd.KeyIsPressed(VK_UP)&&sel>selmin) {
		Sleep(200);
		y += 50;
		sel -= 1;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN)&&sel<selmax) {
		Sleep(200);
		y -= 50;
		sel += 1;
	}
	if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
		gfx.Print("play", 30, 500, 2);
		gfx.Print("play", 30, 500, 2);
		gfx.Print("play", 30, 500, 2);
		gfx.Print("play", 30, 500, 2);
		gfx.Print("play", 30, 500, 2);
		gfx.Print("play", 30, 500, 2);
		Selection(1);
		Select();
		Sleep(500);
	}
	if (wnd.kbd.KeyIsPressed(VK_ESCAPE)) {
		gfx.Print("stop", 30, 500, 2);
		Selection(2);
		Stop();
	}
	Selection(0);
}
void Game::Selection(int selec) {
	switch(selec){
		case 1:
		gfx.Print("OOOOOOOOOOOOOOOOOOOO", 400, 320, 1);
		gfx.Print("OOOOOOOOOOOOOOOOOOOO", 400, 280, 1);
		gfx.Print("O", 526, 300, 1);
		gfx.Print("O", 260, 300, 1);
		break;
		case 2:
		gfx.Print("XXXXXXXXXXXXXXXXXXXX", 400, 320, 1);
		gfx.Print("XXXXXXXXXXXXXXXXXXXX", 400, 280, 1);
		gfx.Print("X", 526, 300, 1);
		gfx.Print("X", 260, 300, 1);
		break;
		case 0:
		gfx.Print("IIIIIIIIIIIIIIIIIIII", 400, 320, 1);
		gfx.Print("IIIIIIIIIIIIIIIIIIII", 400, 280, 1);
		gfx.Print("I", 526, 300, 1);
		gfx.Print("I", 260, 300, 1);
		break;
	}
}
void Game::Draw() {
	gfx.Print("dima musicbox", 400, 30, 1);
	gfx.Print("megalovania", 400, 200 + y, 1);
	gfx.Print("sans", 400, 250 + y, 1);
	gfx.Print("asgore_battle", 400, 300 + y, 1);
	gfx.Print("papyrus", 400, 350 + y, 1);
	gfx.Print("mettaton_battle", 400, 400 + y, 1);
	gfx.Print("papyrus_battle", 400, 450 + y, 1);
	gfx.Print("fallen down", 400, 500 + y, 1);
	gfx.Print("ruins", 400, 150 + y, 1);
}
void Game::Select() {
	switch (sel) {
	case -4:
		DummyB.Play();
		break;
	case -3:
		Ruins.Play();
		break;
	case -2:
		Megalovania.Play();
		break;
	case -1:
		Sans.Play();
		break;
	case 0:
		Asgore.Play();
		break;
	case 1:
		Papyrus.Play();
		break;
	case 2:
		Mettaton.Play();
		break;
	case 4:
		Fallen.Play();
		break;
	case 3:
		PapyrusB.Play();
		break;
	default:
		Error.Play();
	}
}
void Game::Stop() {
	switch (sel) {
	case -4:
		DummyB.StopAll();
		break;
	case -3:
		Ruins.StopAll();
		break;
	case -2:
		Megalovania.StopAll();
		break;
	case -1:
		Sans.StopAll();
		break;
	case 0:
		Asgore.StopAll();
		break;
	case 1:
		Papyrus.StopAll();
		break;
	case 2:
		Mettaton.StopAll();
		break;
	case 4:
		Fallen.StopAll();
		break;
	case 3:
		PapyrusB.StopAll();
		break;
	}
}