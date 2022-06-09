#include "Control.h"
#include "MainWindow.h"

void Control::Input() {
	if (wnd.kbd.KeyIsPressed(VK_UP && sel >= -3)) {
		y += 50;
		sel -= 1;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN && sel <= 3)) {
		y -= 50;
		sel += 1;
	}
	if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
		gfx.Print("play", 30, 500, 2);
		switch (sel) {
		case -3:
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
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_ESCAPE)) {
		gfx.Print("stop", 30, 500, 2);
		switch (sel) {
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
			PapyrusB.Play();
			break;
		}
	}
}