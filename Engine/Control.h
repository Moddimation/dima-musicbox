#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

class Control
{
	friend class Game;
public:
	void Input();
	int y = 0, sel = 0;
private:
	MainWindow& wnd;
	Graphics gfx;
};