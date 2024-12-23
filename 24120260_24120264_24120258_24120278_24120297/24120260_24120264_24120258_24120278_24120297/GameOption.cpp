#include "GameOption.h"

string de = "Asset/";

void PorEBackground() {
    DOGS(10, 7);
    SetConsoleOutputCP(CP_UTF8);
    setColor(Green);
    printAsciiArt(de + "Dog.txt", 66, 0);
    setColor(Yellow);
    printAsciiArt(de + "Magic.txt", 36, 2);
    setColor(Blue2);
    printAsciiArt(de + "Woof.txt", 40, 21);
    setColor(Pink);
    printAsciiArt(de + "Meow.txt", 66, 25);
    SetConsoleOutputCP(437);
    setColor(Red);
    GotoXY(60, 26);
    cout << "VS";
}

void BackChar() {
    SetConsoleOutputCP(CP_UTF8);
    setColor(White);
    printAsciiArt(de + "Clear.txt", 75, 0);
    setColor(Black);
    printAsciiArt(de + "PvP.txt", 80, 5);
    setColor(White);

    GotoXY(112, 18);
    cout << u8"▒▒";
    GotoXY(113, 19);
    cout << u8"▒";
    GotoXY(113, 20);
    cout << u8"▒▒";
    GotoXY(113, 21);
    cout << u8"▒▒";
    GotoXY(113, 22);
    cout << u8"▒▒";
    GotoXY(113, 23);
    cout << u8"▒▒";
    setColor(Yellow2);
    GotoXY(85, 12);
    cout << u8"▒▒▒▒▒▒▒▒";
    GotoXY(90, 13);
    cout << u8"▒▒▒";
    GotoXY(90, 14);
    cout << u8"▒▒▒▒";
    GotoXY(84, 13);
    cout << u8"▒";
    GotoXY(84, 14);
    cout << u8"▒";
    GotoXY(84, 15);
    cout << u8"▒▒▒▒▒▒";
    GotoXY(93, 15);
    cout << u8"▒▒▒▒▒";
    GotoXY(84, 16);
    cout << u8"▒▒▒▒▒▒▒";
    GotoXY(92, 16);
    cout << u8"▒▒▒▒▒▒";
    GotoXY(84, 17);
    cout << u8"▒▒▒▒▒▒";
    GotoXY(85, 13);
    cout << u8"▓";
    GotoXY(89, 13);
    cout << u8"▓";
    GotoXY(93, 13);
    cout << u8"▓▓";
    GotoXY(85, 14);
    cout << u8"▓";
    GotoXY(89, 14);
    cout << u8"▓";
    GotoXY(94, 14);
    cout << u8"▓";
    GotoXY(98, 14);
    cout << u8"▓";
    GotoXY(98, 15);
    cout << u8"▓▓";
    GotoXY(98, 16);
    cout << u8"▓▓";
    GotoXY(90, 17);
    cout << u8"▓";
    GotoXY(92, 17);
    cout << u8"▓▓▓▓▓▓▓▓▓▓▓";
    GotoXY(89, 18);
    cout << u8"▓▓▓▓▓▓▓▓▓";
    setColor(Red2);
    GotoXY(90, 15);
    cout << u8"▒▒▒▒";
    GotoXY(91, 16);
    cout << u8"▓";
    GotoXY(91, 17);
    cout << u8"▓";
    setColor(Yellow);
    GotoXY(80, 22);
    cout << u8"███";
    GotoXY(86, 21);
    cout << u8"██";
    GotoXY(88, 20);
    cout << u8"███████";
    GotoXY(95, 19);
    cout << u8"██████";
    GotoXY(101, 18);
    cout << u8"███████";
    GotoXY(108, 17);
    cout << u8"████";
    SetConsoleOutputCP(437);
    setColor(Black);
    GotoXY(0, 0);

}

void PvPChar() {
    SetConsoleOutputCP(CP_UTF8);
    setColor(White);
    printAsciiArt(de + "Clear.txt", 75, 0);
    veconmeo(75, 5);
    SetConsoleOutputCP(437);
    setColor(Black);
    GotoXY(0, 0);
}

void PvEChar() {
    SetConsoleOutputCP(CP_UTF8);
    setColor(White);
    printAsciiArt(de + "Clear.txt", 75, 0);
    ////// Vẽ meo
    // vẽ nền đen 
    setColor(0);
    GotoXY(81, 6);
    cout << "            ";
    setColor(0);
    GotoXY(80, 7);
    cout << "              ";

    setColor(119);
    GotoXY(84, 6);
    cout << "      ";// tai
    setColor(119);
    GotoXY(85, 11);
    cout << "    ";// tai

    setColor(0);
    GotoXY(79, 8);
    cout << "                ";
    setColor(0);
    GotoXY(78, 9);
    cout << "                  ";
    setColor(0);
    GotoXY(76, 10);
    cout << "                      ";
    setColor(0);
    GotoXY(75, 11);
    cout << "                        ";
    setColor(0);
    GotoXY(75, 12);
    cout << "                        ";
    setColor(0);
    GotoXY(75, 13);
    cout << "                        ";
    setColor(0);
    GotoXY(75, 14);
    cout << "                        ";
    setColor(0);
    GotoXY(76, 15);
    cout << "                         ";
    setColor(0);
    GotoXY(78, 16);
    cout << "                         ";
    setColor(0);
    GotoXY(78, 17);
    cout << "                                    ";
    setColor(0);
    GotoXY(78, 18);
    cout << "                                    ";
    setColor(0);
    GotoXY(78, 19);
    cout << "                                    ";
    setColor(0);
    GotoXY(78, 20);
    cout << "                                    ";
    setColor(0);
    GotoXY(80, 21);
    cout << "                                  ";
    setColor(0);
    GotoXY(82, 22);
    cout << "                                ";
    setColor(0);
    GotoXY(82, 23);
    cout << "                              ";
    setColor(0);
    GotoXY(84, 24);
    cout << "              ";
    // vẽ màu tai 
    // tai trái 
    setColor(200);
    GotoXY(82, 6);
    cout << " ";
    setColor(200);
    GotoXY(81, 7);
    cout << "   ";
    setColor(200);
    GotoXY(80, 8);
    cout << "     ";

    // tai phải
    setColor(200);
    GotoXY(91, 6);
    cout << " ";
    setColor(200);
    GotoXY(90, 7);
    cout << "   ";
    setColor(200);
    GotoXY(89, 8);
    cout << "     ";
    // vẽ màu nền 
    setColor(60);
    GotoXY(79, 9);
    cout << "                ";
    setColor(60);
    GotoXY(77, 10);
    cout << "                    ";
    setColor(60);
    GotoXY(76, 11);
    cout << "                      ";
    setColor(60);
    GotoXY(76, 12);
    cout << "                      ";
    setColor(119);
    GotoXY(76, 13);
    cout << "                      ";
    setColor(119);
    GotoXY(76, 14);
    cout << "                      ";
    setColor(119);
    GotoXY(78, 15);
    cout << "                  ";
    setColor(119);
    GotoXY(82, 16);
    cout << "          ";
    setColor(60);
    GotoXY(97, 15);
    cout << "   ";
    setColor(60);
    GotoXY(96, 16);
    cout << "      ";
    setColor(60);
    GotoXY(79, 17);
    cout << "                        ";
    setColor(119);
    GotoXY(108, 17);
    cout << "                    ";
    setColor(60);
    GotoXY(79, 18);
    cout << "                             ";
    setColor(60);
    GotoXY(79, 19);
    cout << "                                  ";
    setColor(60);
    GotoXY(80, 20);
    cout << "                                 ";
    setColor(60);
    GotoXY(82, 21);
    cout << "                               ";
    setColor(60);
    GotoXY(83, 22);
    cout << "                             ";
    setColor(60);
    GotoXY(83, 22);
    cout << "                             ";
    setColor(60);
    GotoXY(83, 23);
    cout << "                            ";
    // màu mắt
    setColor(0);
    GotoXY(81, 11);
    cout << "  ";
    setColor(0);
    GotoXY(80, 12);
    cout << "    ";
    setColor(100);
    GotoXY(81, 12);
    cout << "  ";

    setColor(0);
    GotoXY(91, 11);
    cout << "  ";
    setColor(0);
    GotoXY(90, 12);
    cout << "    ";
    setColor(100);
    GotoXY(91, 12);
    cout << "  ";

    setColor(100);
    GotoXY(91, 12);
    cout << "  ";
    setColor(119);
    GotoXY(84, 12);
    cout << "      ";
    setColor(119);
    GotoXY(85, 11);
    cout << "    ";
    setColor(119);
    GotoXY(86, 10);
    cout << "  ";
    setColor(0);
    GotoXY(86, 13);
    cout << "  ";
    setColor(0);
    GotoXY(84, 14);
    cout << "      ";
    setColor(119);
    GotoXY(81, 17);
    cout << "            ";
    setColor(119);
    GotoXY(83, 18);
    cout << "        ";
    setColor(119);
    GotoXY(85, 19);
    cout << "    ";
    // vẽ chân 
    setColor(0);
    GotoXY(83, 24);
    cout << " ";
    setColor(119);
    GotoXY(87, 24);
    cout << "   ";
    setColor(119);
    GotoXY(89, 24);
    cout << "    ";
    setColor(0);
    GotoXY(108, 23);
    cout << "   ";
    setColor(0);
    GotoXY(103, 23);
    cout << "    ";
    GotoXY(108, 22);
    cout << "   ";
    setColor(0);
    GotoXY(103, 22);
    cout << "    ";
    setColor(0);
    GotoXY(83, 23);
    cout << "    ";
    setColor(0);
    GotoXY(93, 23);
    cout << "    ";
    setColor(119);
    GotoXY(94, 23);
    cout << "  ";
    setColor(119);
    GotoXY(97, 24);
    cout << "    ";
    setColor(119);
    GotoXY(84, 23);
    cout << "  ";
    setColor(119);
    GotoXY(104, 22);
    cout << "  ";
    setColor(119);
    GotoXY(109, 22);
    cout << "  ";
    setColor(0);
    GotoXY(111, 22);
    cout << "   ";
    setColor(119);
    GotoXY(106, 17);
    cout << "   ";
    setColor(119);
    GotoXY(109, 18);
    cout << "         ";
    setColor(119);
    GotoXY(109, 19);
    cout << "         ";
    setColor(119);
    GotoXY(109, 20);
    cout << "         ";
    setColor(119);
    GotoXY(109, 21);
    cout << "         ";
    setColor(119);
    GotoXY(109, 22);
    cout << "         ";
    setColor(119);
    GotoXY(109, 23);
    cout << "         ";
    setColor(119);
    GotoXY(107, 23);
    cout << "    ";
    setColor(0);
    GotoXY(108, 22);
    cout << " ";
    setColor(0);
    GotoXY(108, 21);
    cout << " ";
    setColor(0);
    GotoXY(108, 20);
    cout << " ";
    setColor(0);
    GotoXY(108, 19);
    cout << " ";
    setColor(0);
    GotoXY(106, 18);
    cout << " ";
    setColor(0);
    GotoXY(107, 22);
    cout << "  ";
    setColor(0);
    GotoXY(107, 18);
    cout << "  ";
    setColor(0);
    GotoXY(98, 23);
    cout << "    ";
    setColor(0);
    GotoXY(98, 22);
    cout << "    ";
    setColor(119);
    GotoXY(99, 22);
    cout << "  ";
    setColor(130);
    GotoXY(87, 23);
    cout << "      ";
    setColor(130);
    GotoXY(97, 23);
    cout << " ";
    setColor(130);
    GotoXY(102, 23);
    cout << " ";
    // vẽ đuôi 
    setColor(0);
    GotoXY(108, 18);
    cout << "    ";
    setColor(0);
    GotoXY(109, 17);
    cout << "    ";
    setColor(0);
    GotoXY(110, 16);
    cout << "    ";
    setColor(0);
    GotoXY(111, 15);
    cout << "   ";
    setColor(0);
    GotoXY(111, 14);
    cout << "   ";
    setColor(0);
    GotoXY(111, 13);
    cout << " ";
    setColor(119);
    GotoXY(111, 13);
    cout << " ";
    setColor(60);
    GotoXY(112, 15);
    cout << " ";
    setColor(60);
    GotoXY(111, 14);
    cout << " ";
    setColor(119);
    GotoXY(113, 14);
    cout << " ";
    setColor(60);
    GotoXY(111, 16);
    cout << "  ";
    setColor(119);
    GotoXY(110, 17);
    cout << "  ";
    setColor(60);
    GotoXY(108, 18);
    cout << "   ";
    // vẽ viền xám 
    setColor(130);
    GotoXY(106, 29);
    cout << "  ";
    setColor(130);
    GotoXY(105, 20);
    cout << "  ";
    setColor(130);
    GotoXY(104, 21);
    cout << "  ";
    setColor(130);
    GotoXY(102, 17);
    cout << "   ";
    setColor(130);
    GotoXY(100, 18);
    cout << "   ";
    setColor(130);
    GotoXY(98, 19);
    cout << "   ";
    setColor(130);
    GotoXY(96, 20);
    cout << "   ";
    setColor(130);
    GotoXY(98, 15);
    cout << "  ";
    setColor(130);
    GotoXY(97, 16);
    cout << "  ";
    setColor(130);
    GotoXY(96, 17);
    cout << "  ";
    setColor(60);
    GotoXY(82, 17);
    cout << "          ";
    setColor(119);
    GotoXY(84, 18);
    cout << "      ";
    setColor(130);
    GotoXY(82, 16);
    cout << "  ";
    setColor(130);
    GotoXY(90, 16);
    cout << "  ";
    setColor(80);
    GotoXY(92, 15);
    cout << "   ";
    setColor(130);
    GotoXY(94, 14);
    cout << "    ";
    setColor(130);
    GotoXY(97, 13);
    cout << " ";
    setColor(80);
    GotoXY(78, 15);
    cout << "   ";
    setColor(130);
    GotoXY(76, 14);
    cout << "    ";
    setColor(130);
    GotoXY(76, 13);
    cout << " ";
    setColor(200);
    GotoXY(79, 14);
    cout << "   ";
    setColor(200);
    GotoXY(91, 14);
    cout << "   ";
    setColor(119);
    GotoXY(94, 14);
    cout << " ";
    setColor(119);
    GotoXY(78, 14);
    cout << " ";
    setColor(200);
    GotoXY(81, 9);
    cout << "   ";
    setColor(200);
    GotoXY(90, 9);
    cout << "   ";
    setColor(119);
    GotoXY(87, 22);
    cout << "      ";
    setColor(119);
    GotoXY(88, 21);
    cout << "    ";
    setColor(119);
    GotoXY(97, 22);
    cout << " ";
    setColor(119);
    GotoXY(102, 22);
    cout << " ";
    SetConsoleOutputCP(437);
    setColor(112);

    SetConsoleOutputCP(437);
    setColor(Black);
    GotoXY(0, 0);
}
void boxPvP() {
    BOX(48, 8, 24, 3);
    GotoXY(50, 8);
    cout << "Player VS Player";

}

void boxPvE() {
    BOX(48, 13, 24, 3);
    GotoXY(49, 13);
    cout << "Player VS Environment";

}

void boxBack() {
    BOX(48, 18, 24, 3);
    GotoXY(56, 18);
    cout << "Back";
}
void gameOptionScreen() {

    fixConsoleWindow();
    PorEBackground();
    boxPvP();
    boxPvE();
    boxBack();
    SetConsoleOutputCP(CP_UTF8);
    setColor(200);
    GotoXY(49, 6);
    cout << u8R"(☃︎ 🎅 🎄 ❄️ ☃️ 🎁 🦌)";
    GotoXY(49, 11);
    cout << u8R"(☃︎ 🎅 🎄 ❄️ ☃️ 🎁 🦌)";
    GotoXY(49, 16);
    cout << u8R"(☃︎ 🎅 🎄 ❄️ ☃️ 🎁 🦌)";

    int selection = 0, previousSelection = -1;

    while (true) {
        // Thực thi hành động theo lựa chọn
        if (selection != previousSelection) {
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
        }

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
void veconmeo(int x, int y) {
    // Khai báo mảng 12x14 với các giá trị đã cho
    int matrix[38][41] = {
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 0, 0},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 15, 15, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 12, 0, 7, 7, 0, 12, 0},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 15, 15, 0, 0, 0, 0, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 12, 0, 0, 0, 0, 12, 0},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 12, 12, 12, 15, 15, 15, 15, 15, 0, 7, 7, 7, 0, 15, 15, 15, 15, 15, 15, 15, 15, 0, 7, 0, 12, 0, 14, 14, 0, 12, 0},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 12, 12, 12, 12, 15, 15, 15, 15, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 12, 0, 0, 0, 0, 12, 0},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 12, 12, 12, 12, 12, 12, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 12, 0, 15, 15, 0, 12, 0},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 12, 12, 12, 12, 12, 12, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 15, 15, 15, 15, 0, 0},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 12, 12, 12, 12, 12, 12, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 12, 12, 12, 12, 12, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 12, 12, 12, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 12, 12, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 15, 15, 15, 12, 12, 12, 12, 12, 12, 12, 15, 15, 15, 15, 15, 15, 15, 15, 15, 12, 12, 12, 12, 12, 12, 12, 15, 15, 0},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 15, 15, 15, 15, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 0, 0, 0, 15, 15, 0},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 15, 15, 15, 15, 12, 12, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 12, 12, 0, 0, 0, 0, 15, 15 },
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 15, 15, 15, 15, 15, 15, 15, 12, 0, 0, 12, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 12, 0, 0, 12, 15, 15},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 15, 15, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 15, 15, 15, 15, 15, 15, 0, 0, 0, 15, 15, 15, 15, 15, 15, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 15, 15},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 15, 15, 15, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 15, 15, 15, 0, 0, 0, 0, 15, 15, 15, 15, 15, 0, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 15, 15},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 7, 7, 7,7, 7},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 7, 7, 7,7, 7},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 15, 15, 15, 15, 15, 15, 15, 6, 6, 15, 15, 15, 15, 15, 15, 15, 0, 7, 7, 7,7, 7},
        {7, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 15, 15, 15, 15, 15, 15, 6, 6, 6, 6, 15, 15, 15, 15, 15, 15, 0, 7, 7, 7, 7,7},
        {7, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 15, 0, 15, 0, 15, 15, 6, 6, 6, 6, 15, 15, 15, 15, 15, 15, 0, 0, 0, 7, 7, 7},
        {0, 0, 0, 12, 12, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 15, 15, 0, 15, 15, 15, 6, 6, 6, 6, 15, 15, 0, 15, 0, 15, 15, 15, 0, 7, 7, 7},
        {0, 0, 0, 12, 12, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 15, 15, 15, 15, 15, 15, 6, 6, 6, 6, 15, 15, 15, 0, 15, 15, 15, 15, 0, 0, 7, 7},
        {0, 0, 0, 12, 12, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 6, 6, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 7, 7},
        {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 7, 7},
        {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 12, 12, 12, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 12, 12, 12, 15, 15, 0, 7, 7},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 15, 15, 15, 15, 12, 12, 12, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 12, 12, 12, 15, 15, 0, 7, 7},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7}
    };

    SetConsoleOutputCP(CP_UTF8);
    for (int i = 0; i < 38; i = i + 2)
    {
        GotoXY(x, y + i / 2);
        for (int x = 0; x < 41; x++)
        {
            SSetColor(matrix[i][x], matrix[i + 1][x]);
            cout << u8"▄";
        }cout << endl;
    }
    SetConsoleOutputCP(437);
}

void DOGS(int x, int y) {
    // Ma trận 16x54 với các giá trị từ bảng số bạn cung cấp
    int matrix[34][27] = {
        {7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0},
        {7, 7, 7, 7, 7, 7, 0, 6, 6, 6, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 6, 6, 6, 0},
        {7, 7, 7, 7, 7, 7, 0, 6, 14, 14, 6, 0, 0, 7, 7, 7, 7, 7, 7, 7, 0, 0, 6, 14, 14, 6, 0},
        {7, 7, 7, 7, 7, 7, 0, 6, 14, 14, 14, 6, 6, 0, 0, 0, 0, 0, 0, 0, 6, 6, 14, 14, 14,6, 0},
        {7, 7, 7, 7, 7, 7, 7, 0, 6, 14, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 14, 6, 0, 7},
        {7, 7, 7, 7, 7, 7, 7, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 7},
        {7, 7, 7, 7, 7, 7, 7, 7, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 7, 7},
        {7, 7, 7, 7, 7, 7, 7, 7, 0, 6, 6, 15, 15, 6, 6, 6, 6, 6, 6, 6, 15, 15, 6, 6, 0, 7, 7},
        {7, 7, 7, 7, 7, 7, 7, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 7},
        {7, 7, 7, 7, 7, 7, 7, 0, 6, 6, 6, 0, 15, 0, 6, 6, 6, 6, 6, 0, 15, 0, 6, 6, 6, 0, 7},
        {7, 7, 7, 7, 7, 7, 0, 6, 6, 6, 6, 0, 0, 0, 6, 6, 6, 6, 6, 0, 0, 0, 6, 6, 6, 6, 0},
        {7, 7, 7, 7, 7, 7, 0, 6, 6, 6, 6, 6, 6, 6, 6, 15, 15, 15, 6, 6, 6, 6, 6, 6, 6, 6, 0},
        {7, 7, 7, 7, 7, 7, 0, 15, 15, 6, 6, 6, 6, 6, 15, 0, 0, 0, 15, 6, 6, 6, 6, 6, 15, 15, 0},
        {7, 7, 7, 7, 7, 7, 7, 0, 15, 15, 15, 6, 6, 15, 15, 15, 0, 15, 15, 15, 6, 6, 15, 15, 15, 0, 7},
        {7, 7, 7, 7, 7, 7, 7, 0, 15, 15, 15, 15, 15, 0, 15, 15, 0, 15, 15, 0, 15, 15, 15, 15, 15, 0, 7},
        {7, 7, 7, 7, 7, 7, 7, 7, 0, 15, 15, 15, 15, 15, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 0, 7, 7},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 15, 15, 15, 15, 15, 0,  4,  0, 15, 15, 15, 15, 15, 0, 7, 7, 7},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 0, 7,  0,  0,  0},
        {7, 7, 7, 7, 7, 7, 7, 7, 7,  0, 3,  0,  0, 15, 15, 15, 15, 15, 15, 15,  0,  0, 7,  0, 3, 3,  0},
        {7, 7, 7, 7, 7, 7, 7, 7, 7,  0, 3, 3, 3,  0,  0,  0,  0,  0,  0,  0, 3, 3,  0, 3,  0,  0, 7},
        {7, 7, 7, 7, 7, 7, 7, 7,  0, 6,  0,  0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,  0, 3, 3,  0},
        {7, 7, 7, 7, 7, 7, 7, 7,  0, 6, 6, 15,  0,  0, 3, 3, 3, 3, 3, 3, 3, 3,  0, 6,  0,  0,  0},
        {7, 7, 7, 7, 7, 7, 7, 7,  0, 6, 6, 15, 15, 15,  0,  0, 3, 3, 3, 3, 3,  0, 6, 6,  0, 7, 7},
        {7,  0, 7, 7, 7, 7, 7, 7,  0, 6, 6, 6, 15, 15, 15, 15,  0,  0, 3, 3,  0, 15, 6, 6,  0, 7, 7},
        { 0, 6,  0, 7, 7, 7, 7, 7,  0, 6, 6, 6, 15, 15, 15, 15, 15, 15,  0,  0, 15, 6, 6, 6,  0, 7, 7},
        { 0, 6,  0, 7, 7, 7, 7,  0, 6,  0, 6, 6, 6, 15, 15, 15, 15, 15, 15, 15, 6, 6, 6,  0, 6,  0, 7},
        { 0, 6, 6,  0, 7, 7,  0, 6, 6,  0, 6, 6, 6, 15,  0, 15, 15, 15,  0, 15, 6, 6, 6,  0, 6, 6,  0},
        { 0, 6, 6, 6,  0, 7,  0, 6, 6,  0, 6, 6, 6, 6,  0, 15, 15, 15,  0, 6, 6, 6, 6,  0, 6, 6,  0},
        {7,  0, 15, 6, 6,  0,  0, 6, 6, 6,  0, 6, 6, 6,  0, 15, 15, 15,  0, 6, 6, 6,  0, 6, 6, 6,  0},
        {7, 7,  0, 15, 15, 15, 6,  0, 6, 6,  0, 6, 6, 6,  0, 15, 15, 15,  0, 6, 6, 6,  0, 6, 6,  0, 7},
        {7, 7, 7,  0,  0, 15, 15, 15,  0, 6, 6,  0, 6, 6,  0, 6, 15, 6,  0, 6, 6,  0, 6, 6,  0, 7, 7},
        {7, 7, 7, 7, 7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 6, 6, 6,  0,  0,  0,  0,  0,  0, 7, 7, 7},
        {7, 7, 7, 7, 7, 7, 7, 7,  0, 15, 15,  0, 15, 15,  0, 6, 6, 6,  0, 15, 15,  0, 15, 15,  0, 7, 7},
        {7, 7, 7, 7, 7, 7, 7, 7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 7, 7}
    };


    // Duyệt qua ma trận và in màu tương ứng

    for (int i = 0; i < 34; i = i + 2)
    {
        GotoXY(x, y + i / 2);
        for (int x = 0; x < 27; x++)
        {
            SSetColor(matrix[i][x], matrix[i + 1][x]);
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"▄";
            SetConsoleOutputCP(437);
        }cout << endl;
    }
    SetConsoleOutputCP(437);

}