#include "PauseGame.h"

void boxContinue() {

}

void boxSaveGame() {

}

void boxMenu() {

}

void boxVolume() {

}

void pauseGame() {
    fixConsoleWindow();
    int selection = 0, previousSelection = -1;
    while (true) {
        // Đổi màu và thực thi hành động dựa trên lựa chọn
        if (selection != previousSelection) {
            // Chỉ vẽ lại nếu có thay đổi
            for (int i = 0; i < 3; i++) {
                setColor(i == selection ? 124 : Black);
                if (i == 0) boxPvP();
                else if (i == 1) boxPvE();
                else boxBack();
            }
            previousSelection = selection;
        }

        // Thực thi hành động theo lựa chọn
        switch (selection) {
        case 0:
            PvPChar();
            break;
        case 1:
            PvEChar();
            break;
        case 2:
            BackChar();
            break;
        }

        Sleep(20);

        char ch = _getch(); // Đọc ký tự từ người dùng

        if (ch == 27) { // Phím Escape để thoát
            playSound(3, 0);
            clearScreen();
            menuScreen();
            break;
        }
        playSound(2, 0);
        if (ch == 13) { // Phím Enter để xác nhận lựa chọn
            switch (selection) {
            case 0:
                playSound(3, 0);
                clearScreen();
                PlayWithPlayer();
                break;
            case 1:
                playSound(3, 0);
                clearScreen();
                PlayWithBot();
                break;
            case 2:
                playSound(3, 0);
                clearScreen();
                menuScreen();
                break;
            }
        }
        // Dùng các phím mũi tên lên/xuống để di chuyển trong menu
        if (ch == 72 or ch == 'w' or ch == 'W') { // Phím mũi ten len (ASCII 72)
            if (selection > 0) {
                selection--;
            }
        }
        else if (ch == 80 or ch == 's' or ch == 'S') { // Phím mũi tên xuống (ASCII 80)
            if (selection < 2) {
                selection++;
            }
        }
    }
}