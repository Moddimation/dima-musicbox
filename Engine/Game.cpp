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
	DummyB(L"Music/mus_dummybattle.mp3"),
	Undyne(L"Music/mus_undyneboss.mp3"),
	Story(L"Music/mus_story.mp3")
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
	if (key(VK_UP) && sel>selmin) {
		Sleep(200);
		y += 50;
		sel -= 1;
	}
	if (key(VK_DOWN)&&sel<selmax) {
		Sleep(200);
		y -= 50;
		sel += 1;
	}
	key(VK_LEFT) ? repeat-- : repeat;
	key(VK_RIGHT) ? repeat++ : repeat;
	if (key(VK_RETURN)) {
		gfx.Print("play", 20, hei - 25, 2);
		Selection(1);
		Select();
		Sleep(500);
	}
	if (key(VK_ESCAPE)) {
		gfx.Print("stop", 20, hei - 25, 2);
		Selection(2);
		Stop();
	}
	Selection(0);
}
void Game::Selection(int selec) {
	switch (selec) {
	case 1:
		gfx.Print("OOOOOOOOOOOOOOOOOOO", widm, heim + 20, 1);
		gfx.Print("OOOOOOOOOOOOOOOOOOO", widm, heim - 20, 1);
		gfx.Print("O", widm + 126, 300, 1);
		gfx.Print("O", widm - 126, 300, 1);
		break;
	case 2:
		gfx.Print("XXXXXXXXXXXXXXXXXXX", widm, heim + 20, 1);
		gfx.Print("XXXXXXXXXXXXXXXXXXX", widm, heim - 20, 1);
		gfx.Print("X", widm + 126, 300, 1);
		gfx.Print("X", widm - 126, 300, 1);
		break;
	case 0:
		gfx.Print("IIIIIIIIIIIIIIIIIII", widm, heim + 20, 1);
		gfx.Print("IIIIIIIIIIIIIIIIIII", widm, heim - 20, 1);
		gfx.Print("I", widm + 126, 300, 1);
		gfx.Print("I", widm - 126, 300, 1);
		break;
	}
}
void Game::printname(string name, int pos){
	gfx.Print(name, widm, (pos * 50) + 300 + y, 1);
}
void Game::Draw() {
	gfx.Print("dima musicbox", widm, 30, 1);
	printname("story", -5);
	printname("megalovania", -2);
	printname("sans", -1);
	printname("asgore_battle", 0);
	printname("papyrus", 1);
	printname("mettaton_battle", 2);
	printname("papyrus_battle", 3);
	printname("fallen down", 4);
	printname("ruins", -3);
	printname("dummy_battle", -4);
	printname("undyne_battle", 5);
}
void Game::Select() {
	switch (sel) {
	case -5:
		Story.Play();
		break;
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
	case 5:
		Undyne.Play();
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
	case 5:
		Undyne.StopAll();
		break;
	default:
		Error.Play();
		break;
	}
}