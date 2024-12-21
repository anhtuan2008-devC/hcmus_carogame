#include "Menu.h"
#include "SoundManager.h"

void main() {

	playSound(1, 1);
    // Kich thuoc console = buffer = 120x30
	SetConsoleTitle(L"Caro");
	fixConsoleWindow();
	ShowScrollbar(false);
	menuScreen();
}