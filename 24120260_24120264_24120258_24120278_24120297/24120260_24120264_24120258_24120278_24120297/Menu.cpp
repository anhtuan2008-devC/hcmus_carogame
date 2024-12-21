#include "Menu.h"

int x = 50;
int y = 5;

void boxPlayGame() {
    BOX(49, 10, 21, 3);
    GotoXY(54, 10);
    cout << "PLAY GAME";
}
void boxLoadGame() {
    BOX(49, 10 + 4, 21, 3);
    GotoXY(54, 10 + 4);
    cout << "LOAD GAME";
}
void boxHelp() {
    BOX(49, 10 + 8, 21, 3);
    GotoXY(56, 10 + 8);
    cout << "HELP";
}
void boxSetting() {
    BOX(49, 10 + 12, 21, 3);
    GotoXY(55, 10 + 12);
    cout << "SETTING";
}
void boxExit() {
    BOX(49, 10 + 16, 21, 3);
    GotoXY(56, 10 + 16);
    cout << "EXIT";
}

// Hàm hiển thị nội dung của menu



void trangtri() {

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    // Lấy chiều rộng và chiều cao của cửa sổ console
    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    // Chiều dài của chữ "CARO" là 7*4 (cho mỗi chữ), cộng thêm 3 khoảng cách giữa các chữ (3 khoảng trống)
    int textWidth = 7 * 4 + 3 * 3;  // 7 ký tự cho mỗi chữ và 3 khoảng cách giữa các chữ
    int textHeight = 5;  // Chữ "CARO" có 5 dòng (theo kích thước chữ)

    // Tính toán vị trí để căn giữa chữ "CARO" theo chiều ngang
    int startX = (consoleWidth - textWidth) / 2;
    int startY = 0;  // Đặt ở dòng đầu tiên (dòng 0)

    // Di chuyển đến vị trí căn giữa trên dòng đầu tiên
    setColor(124);
    GotoXY(startX, startY);

    int x = 25, y = 0;
    SetConsoleOutputCP(CP_UTF8);
    setColor(124);
    cout << u8R"(
                        ██████   █████  ███    ███ ███████      ██████  █████  ██████   ██████  
                       ██       ██   ██ ████  ████ ██          ██      ██   ██ ██   ██ ██    ██ 
                       ██   ███ ███████ ██ ████ ██ █████       ██      ███████ ██████  ██    ██ 
                       ██    ██ ██   ██ ██  ██  ██ ██          ██      ██   ██ ██   ██ ██    ██ 
                        ██████  ██   ██ ██      ██ ███████      ██████ ██   ██ ██   ██  ██████                                                                             
)";
    setColor(0);
    GotoXY(32, 7);
    cout << "       ";
    setColor(0);
    GotoXY(30, 8);
    cout << "           ";
    setColor(100);
    GotoXY(31, 8);
    cout << "         ";
    setColor(0);
    GotoXY(34, 8);
    cout << " ";
    setColor(0);
    GotoXY(29, 9);
    cout << "             ";
    setColor(100);
    GotoXY(30, 9);
    cout << "           ";
    setColor(0);
    GotoXY(33, 9);
    cout << " ";
    setColor(0);
    GotoXY(29, 10);
    cout << "             ";
    setColor(100);
    GotoXY(30, 10);
    cout << "           ";
    setColor(0);
    GotoXY(32, 10);
    cout << " ";
    setColor(0);
    GotoXY(28, 11);
    cout << "               ";
    setColor(0);
    GotoXY(29, 11);
    cout << "             ";
    setColor(100);
    GotoXY(30, 11);
    cout << " ";
    setColor(100);
    GotoXY(30, 11);
    cout << "           ";
    setColor(0);
    GotoXY(32, 11);
    cout << " ";
    setColor(0);
    GotoXY(28, 12);
    cout << "               ";
    setColor(100);
    GotoXY(29, 12);
    cout << "             ";
    setColor(0);
    GotoXY(32, 12);
    cout << " ";
    setColor(0);
    GotoXY(28, 13);
    cout << "              ";
    setColor(100);
    GotoXY(29, 13);
    cout << "            ";
    setColor(0);
    GotoXY(32, 13);
    cout << " ";
    // vẽ vùng trắng miệng 

    setColor(119);
    GotoXY(34, 13);
    cout << "      ";

    setColor(0);
    GotoXY(36, 13);
    cout << "   ";

    setColor(119);
    GotoXY(34, 12);
    cout << "      ";
    setColor(0);
    GotoXY(37, 12);
    cout << " ";
    setColor(119);
    GotoXY(35, 11);
    cout << "      ";
    // vẽ cửa sổ tâm hồn 
    setColor(60);
    GotoXY(35, 10);
    cout << " ";

    setColor(60);
    GotoXY(39, 10);
    cout << " ";

    // phần thân 

    setColor(0);
    GotoXY(29, 14);
    cout << "            ";
    setColor(119);
    GotoXY(35, 14);
    cout << "    ";
    setColor(0);
    GotoXY(27, 15);
    cout << "              ";
    setColor(0);
    GotoXY(25, 16);
    cout << "                ";
    setColor(0);
    GotoXY(24, 17);
    cout << "                 ";
    setColor(0);
    GotoXY(23, 18);
    cout << "                 ";
    setColor(0);
    GotoXY(21, 19);
    cout << "                   ";
    setColor(0);
    GotoXY(20, 20);
    cout << "                    ";
    setColor(0);
    GotoXY(19, 21);
    cout << "                     ";
    // phần trắng ngực 
    setColor(119);
    GotoXY(32, 16);
    cout << "      ";
    setColor(119);
    GotoXY(31, 17);
    cout << "        ";
    setColor(119);
    GotoXY(31, 18);
    cout << "        ";
    setColor(119);
    GotoXY(32, 19);
    cout << "      ";
    setColor(119);
    GotoXY(33, 20);
    cout << "    ";
    setColor(119);
    GotoXY(34, 21);
    cout << "  ";

    // vẽ nền vàng cho thân 
    setColor(100);
    GotoXY(28, 16);
    cout << "   ";
    setColor(100);
    GotoXY(29, 15);
    cout << "   ";
    setColor(100);
    GotoXY(29, 17);
    cout << "  ";
    setColor(100);
    GotoXY(29, 15);
    cout << "   ";
    setColor(100);
    GotoXY(28, 16);
    cout << "   ";
    setColor(100);
    GotoXY(27, 17);
    cout << "    ";
    setColor(100);
    GotoXY(26, 18);
    cout << "    ";
    setColor(100);
    GotoXY(27, 19);
    cout << "    ";
    setColor(100);
    GotoXY(28, 20);
    cout << "    ";
    setColor(100);
    GotoXY(26, 21);
    cout << "       ";
    setColor(100);
    GotoXY(39, 16);
    cout << " ";



    // vẽ màu trắng thân


    //// đuôi
    setColor(0);
    GotoXY(2, 22);
    cout << "                                      ";
    setColor(119);
    GotoXY(5, 22);
    cout << "             ";
    setColor(0);
    GotoXY(2, 23);
    cout << "                                      ";
    setColor(119);
    GotoXY(6, 23);
    cout << "          ";
    setColor(0);
    GotoXY(2, 24);
    cout << "                                      ";
    setColor(119);
    GotoXY(7, 24);
    cout << "       ";
    setColor(0);
    GotoXY(4, 25);
    cout << "                                    ";
    setColor(119);
    GotoXY(8, 25);
    cout << "    ";
    setColor(0);
    GotoXY(5, 26);
    cout << "                                    ";
    setColor(0);
    GotoXY(7, 27);
    cout << "                                  ";
    // vẽ màu từ chân sau lên cổ 
    setColor(100);
    GotoXY(21, 27);
    cout << "    ";
    setColor(100);
    GotoXY(17, 26);
    cout << "  ";
    setColor(100);
    GotoXY(17, 25);
    cout << "     ";
    setColor(100);
    GotoXY(21, 24);
    cout << "   ";
    setColor(100);
    GotoXY(22, 23);
    cout << " ";
    setColor(119);
    GotoXY(29, 27);
    cout << "   ";
    setColor(119);
    GotoXY(28, 26);
    cout << "  ";
    setColor(100);
    GotoXY(25, 26);
    cout << "     ";
    setColor(100);
    GotoXY(27, 27);
    cout << "    ";
    setColor(100);
    GotoXY(24, 25);
    cout << "      ";
    setColor(100);
    GotoXY(16, 27);
    cout << "   ";
    setColor(119);
    GotoXY(38, 27);
    cout << "  ";
    setColor(119);
    GotoXY(37, 26);
    cout << "  ";
    setColor(119);
    GotoXY(35, 25);
    cout << "    ";
    setColor(119);
    GotoXY(36, 24);
    cout << "   ";
    setColor(100);
    GotoXY(32, 24);
    cout << "    ";


    setColor(0);
    GotoXY(27, 27);
    cout << "  ";
    setColor(0);
    GotoXY(27, 26);
    cout << " ";
    setColor(0);
    GotoXY(27, 25);
    cout << " ";
    setColor(119);
    GotoXY(29, 26);
    cout << "  ";
    setColor(119);
    GotoXY(29, 25);
    cout << "   ";
    setColor(100);
    GotoXY(28, 23);
    cout << "    ";
    setColor(100);
    GotoXY(30, 25);
    cout << "    ";
    setColor(100);
    GotoXY(34, 23);
    cout << "    ";
    setColor(100);
    GotoXY(35, 22);
    cout << "    ";
    setColor(100);
    GotoXY(37, 21);
    cout << "  ";
    setColor(119);
    GotoXY(28, 24);
    cout << "   ";
    setColor(119);
    GotoXY(30, 27);
    cout << " ";
    setColor(119);
    GotoXY(27, 25);
    cout << "    ";
    setColor(100);
    GotoXY(28, 23);
    cout << "     ";
    setColor(100);
    GotoXY(29, 22);
    cout << "     ";
    setColor(119);
    GotoXY(24, 24);
    cout << "  ";
    setColor(119);
    GotoXY(24, 23);
    cout << "  ";
    setColor(119);
    GotoXY(25, 22);
    cout << "    ";
    setColor(119);
    GotoXY(26, 20);
    cout << "   ";
    setColor(119);
    GotoXY(24, 27);
    cout << "  ";
    setColor(119);
    GotoXY(19, 26);
    cout << "    ";
    setColor(0);
    GotoXY(19, 25);
    cout << "     ";
    setColor(100);
    GotoXY(19, 25);
    cout << " ";
    setColor(100);
    GotoXY(20, 26);
    cout << " ";
    setColor(0);
    GotoXY(22, 27);
    cout << " ";
    setColor(100);
    GotoXY(20, 27);
    cout << " ";
    setColor(70);
    GotoXY(24, 23);
    cout << "  ";
    // vẽ màu vùng trắng thân 
    setColor(0);
    GotoXY(12, 28);
    cout << "                              ";
    setColor(119);
    GotoXY(33, 27);
    cout << "  ";
    setColor(119);
    GotoXY(27, 28);
    cout << " ";// bàn chân 
    setColor(119);
    GotoXY(33, 28);
    cout << "    ";// bàn chân 
    setColor(100);
    GotoXY(18, 24);
    cout << "    ";
    setColor(100);
    GotoXY(20, 23);
    cout << "       ";
    setColor(100);
    GotoXY(24, 23);
    cout << "  ";
    setColor(119);
    GotoXY(3, 23);
    cout << " "; // đốm đuôi
    setColor(119);
    GotoXY(4, 24);
    cout << " ";
    setColor(100);
    GotoXY(5, 24);
    cout << " ";
    setColor(100);
    GotoXY(5, 25);
    cout << "  ";

    // icon
    setColor(20);
    GotoXY(53, 8);
    cout << u8R"(🎮   🎮   🎮)";
    GotoXY(53, 12);
    cout << u8R"(💾   💾   💾)";
    GotoXY(53, 16);
    cout << u8R"(🛟   🛟   🛟)";
    GotoXY(53, 20);
    cout << u8R"(⚙️   ⚙️   ⚙️)";
    GotoXY(53, 24);
    cout << u8R"(🚪   🚪   🚪)";

    ////// Vẽ meo
    // vẽ nền đen 
    setColor(0);
    GotoXY(81, 10);
    cout << "            ";
    setColor(0);
    GotoXY(80, 11);
    cout << "              ";

    setColor(119);
    GotoXY(84, 10);
    cout << "      ";// tai
    setColor(119);
    GotoXY(85, 11);
    cout << "    ";// tai

    setColor(0);
    GotoXY(79, 12);
    cout << "                ";
    setColor(0);
    GotoXY(78, 13);
    cout << "                  ";
    setColor(0);
    GotoXY(76, 14);
    cout << "                      ";
    setColor(0);
    GotoXY(75, 15);
    cout << "                        ";
    setColor(0);
    GotoXY(75, 16);
    cout << "                        ";
    setColor(0);
    GotoXY(75, 17);
    cout << "                        ";
    setColor(0);
    GotoXY(75, 18);
    cout << "                        ";
    setColor(0);
    GotoXY(76, 19);
    cout << "                         ";
    setColor(0);
    GotoXY(78, 20);
    cout << "                         ";
    setColor(0);
    GotoXY(78, 21);
    cout << "                                    ";
    setColor(0);
    GotoXY(78, 22);
    cout << "                                    ";
    setColor(0);
    GotoXY(78, 23);
    cout << "                                    ";
    setColor(0);
    GotoXY(78, 24);
    cout << "                                    ";
    setColor(0);
    GotoXY(80, 25);
    cout << "                                  ";
    setColor(0);
    GotoXY(82, 26);
    cout << "                                ";
    setColor(0);
    GotoXY(82, 27);
    cout << "                              ";
    setColor(0);
    GotoXY(84, 28);
    cout << "              ";
    // vẽ màu tai 
    // tai trái 
    setColor(200);
    GotoXY(82, 10);
    cout << " ";
    setColor(200);
    GotoXY(81, 11);
    cout << "   ";
    setColor(200);
    GotoXY(80, 12);
    cout << "     ";

    // tai phải
    setColor(200);
    GotoXY(91, 10);
    cout << " ";
    setColor(200);
    GotoXY(90, 11);
    cout << "   ";
    setColor(200);
    GotoXY(89, 12);
    cout << "     ";
    // vẽ màu nền 
    setColor(60);
    GotoXY(79, 13);
    cout << "                ";
    setColor(60);
    GotoXY(77, 14);
    cout << "                    ";
    setColor(60);
    GotoXY(76, 15);
    cout << "                      ";
    setColor(60);
    GotoXY(76, 16);
    cout << "                      ";
    setColor(119);
    GotoXY(76, 17);
    cout << "                      ";
    setColor(119);
    GotoXY(76, 18);
    cout << "                      ";
    setColor(119);
    GotoXY(78, 19);
    cout << "                  ";
    setColor(119);
    GotoXY(82, 20);
    cout << "          ";
    setColor(60);
    GotoXY(97, 19);
    cout << "   ";
    setColor(60);
    GotoXY(96, 20);
    cout << "      ";
    setColor(60);
    GotoXY(79, 21);
    cout << "                        ";
    setColor(119);
    GotoXY(108, 21);
    cout << "                    ";
    setColor(60);
    GotoXY(79, 22);
    cout << "                             ";
    setColor(60);
    GotoXY(79, 23);
    cout << "                                  ";
    setColor(60);
    GotoXY(80, 24);
    cout << "                                 ";
    setColor(60);
    GotoXY(82, 25);
    cout << "                               ";
    setColor(60);
    GotoXY(83, 26);
    cout << "                             ";
    setColor(60);
    GotoXY(83, 26);
    cout << "                             ";
    setColor(60);
    GotoXY(83, 27);
    cout << "                            ";
    // màu mắt
    setColor(0);
    GotoXY(81, 15);
    cout << "  ";
    setColor(0);
    GotoXY(80, 16);
    cout << "    ";
    setColor(100);
    GotoXY(81, 16);
    cout << "  ";

    setColor(0);
    GotoXY(91, 15);
    cout << "  ";
    setColor(0);
    GotoXY(90, 16);
    cout << "    ";
    setColor(100);
    GotoXY(91, 16);
    cout << "  ";

    setColor(100);
    GotoXY(91, 16);
    cout << "  ";
    setColor(119);
    GotoXY(84, 16);
    cout << "      ";
    setColor(119);
    GotoXY(85, 15);
    cout << "    ";
    setColor(119);
    GotoXY(86, 14);
    cout << "  ";
    setColor(0);
    GotoXY(86, 17);
    cout << "  ";
    setColor(0);
    GotoXY(84, 18);
    cout << "      ";
    setColor(119);
    GotoXY(81, 21);
    cout << "            ";
    setColor(119);
    GotoXY(83, 22);
    cout << "        ";
    setColor(119);
    GotoXY(85, 23);
    cout << "    ";
    // vẽ chân 
    setColor(0);
    GotoXY(83, 28);
    cout << " ";
    setColor(119);
    GotoXY(87, 28);
    cout << "   ";
    setColor(119);
    GotoXY(89, 28);
    cout << "    ";
    setColor(0);
    GotoXY(108, 27);
    cout << "   ";
    setColor(0);
    GotoXY(103, 27);
    cout << "    ";
    GotoXY(108, 26);
    cout << "   ";
    setColor(0);
    GotoXY(103, 26);
    cout << "    ";
    setColor(0);
    GotoXY(83, 27);
    cout << "    ";
    setColor(0);
    GotoXY(93, 27);
    cout << "    ";
    setColor(119);
    GotoXY(94, 27);
    cout << "  ";
    setColor(119);
    GotoXY(97, 28);
    cout << "    ";
    setColor(119);
    GotoXY(84, 27);
    cout << "  ";
    setColor(119);
    GotoXY(104, 26);
    cout << "  ";
    setColor(119);
    GotoXY(109, 26);
    cout << "  ";
    setColor(0);
    GotoXY(111, 26);
    cout << "   ";
    setColor(119);
    GotoXY(106, 21);
    cout << "   ";
    setColor(119);
    GotoXY(109, 22);
    cout << "         ";
    setColor(119);
    GotoXY(109, 23);
    cout << "         ";
    setColor(119);
    GotoXY(109, 24);
    cout << "         ";
    setColor(119);
    GotoXY(109, 25);
    cout << "         ";
    setColor(119);
    GotoXY(109, 26);
    cout << "         ";
    setColor(119);
    GotoXY(109, 27);
    cout << "         ";
    setColor(119);
    GotoXY(107, 27);
    cout << "    ";
    setColor(0);
    GotoXY(108, 26);
    cout << " ";
    setColor(0);
    GotoXY(108, 25);
    cout << " ";
    setColor(0);
    GotoXY(108, 24);
    cout << " ";
    setColor(0);
    GotoXY(108, 23);
    cout << " ";
    setColor(0);
    GotoXY(106, 22);
    cout << " ";
    setColor(0);
    GotoXY(107, 26);
    cout << "  ";
    setColor(0);
    GotoXY(107, 22);
    cout << "  ";
    setColor(0);
    GotoXY(98, 27);
    cout << "    ";
    setColor(0);
    GotoXY(98, 26);
    cout << "    ";
    setColor(119);
    GotoXY(99, 26);
    cout << "  ";
    setColor(130);
    GotoXY(87, 27);
    cout << "      ";
    setColor(130);
    GotoXY(97, 27);
    cout << " ";
    setColor(130);
    GotoXY(102, 27);
    cout << " ";
    // vẽ đuôi 
    setColor(0);
    GotoXY(108, 22);
    cout << "    ";
    setColor(0);
    GotoXY(109, 21);
    cout << "    ";
    setColor(0);
    GotoXY(110, 20);
    cout << "    ";
    setColor(0);
    GotoXY(111, 19);
    cout << "   ";
    setColor(0);
    GotoXY(111, 18);
    cout << "   ";
    setColor(0);
    GotoXY(111, 17);
    cout << " ";
    setColor(119);
    GotoXY(111, 17);
    cout << " ";
    setColor(60);
    GotoXY(112, 19);
    cout << " ";
    setColor(60);
    GotoXY(111, 18);
    cout << " ";
    setColor(119);
    GotoXY(113, 18);
    cout << " ";
    setColor(60);
    GotoXY(111, 20);
    cout << "  ";
    setColor(119);
    GotoXY(110, 21);
    cout << "  ";
    setColor(60);
    GotoXY(108, 22);
    cout << "   ";
    // vẽ viền xám 
    setColor(130);
    GotoXY(106, 23);
    cout << "  ";
    setColor(130);
    GotoXY(105, 24);
    cout << "  ";
    setColor(130);
    GotoXY(104, 25);
    cout << "  ";
    setColor(130);
    GotoXY(102, 21);
    cout << "   ";
    setColor(130);
    GotoXY(100, 22);
    cout << "   ";
    setColor(130);
    GotoXY(98, 23);
    cout << "   ";
    setColor(130);
    GotoXY(96, 24);
    cout << "   ";
    setColor(130);
    GotoXY(98, 19);
    cout << "  ";
    setColor(130);
    GotoXY(97, 20);
    cout << "  ";
    setColor(130);
    GotoXY(96, 21);
    cout << "  ";
    setColor(60);
    GotoXY(82, 21);
    cout << "          ";
    setColor(119);
    GotoXY(84, 22);
    cout << "      ";
    setColor(130);
    GotoXY(82, 20);
    cout << "  ";
    setColor(130);
    GotoXY(90, 20);
    cout << "  ";
    setColor(80);
    GotoXY(92, 19);
    cout << "   ";
    setColor(130);
    GotoXY(94, 18);
    cout << "    ";
    setColor(130);
    GotoXY(97, 17);
    cout << " ";
    setColor(80);
    GotoXY(78, 19);
    cout << "   ";
    setColor(130);
    GotoXY(76, 18);
    cout << "    ";
    setColor(130);
    GotoXY(76, 17);
    cout << " ";
    setColor(200);
    GotoXY(79, 18);
    cout << "   ";
    setColor(200);
    GotoXY(91, 18);
    cout << "   ";
    setColor(119);
    GotoXY(94, 18);
    cout << " ";
    setColor(119);
    GotoXY(78, 18);
    cout << " ";
    setColor(200);
    GotoXY(81, 13);
    cout << "   ";
    setColor(200);
    GotoXY(90, 13);
    cout << "   ";
    setColor(119);
    GotoXY(87, 26);
    cout << "      ";
    setColor(119);
    GotoXY(88, 25);
    cout << "    ";
    setColor(119);
    GotoXY(97, 26);
    cout << " ";
    setColor(119);
    GotoXY(102, 26);
    cout << " ";
    SetConsoleOutputCP(437);
    setColor(112);

    // Reset màu sắc về mặc định
}

void hienthimenu() {
    clearScreen();
    trangtri();
    // Vẽ các hộp với nội dung menu
    boxPlayGame();
    boxLoadGame();
    boxHelp();
    boxSetting();
    boxExit();

    // Xử lý nhập liệu cho việc chọn menu
    int selection = 0, previousSelection = -1;
    int _X = 52, _Y = 10;
    do {
        if (selection != previousSelection) {
            // Đổi màu cho ô được chọn
            for (int i = 0; i < 5; i++) {
                setColor(i == selection ? 124 : 112);
                if (i == 0) {
                    boxPlayGame();
                }
                else if (i == 1) {
                    boxLoadGame();
                }
                else if (i == 2) {
                    boxHelp();
                }
                else if (i == 3) {
                    boxSetting();
                }
                else {
                    boxExit();
                }
                previousSelection = selection;
            }
            Sleep(20);
        }
        char ch = _getch(); // Đọc ký tự từ người dùng
        playSound(2, 0);
        if (ch == 13) { // Phím Enter để xác nhận lựa chọn
            switch (selection) {
            case 0:
                playSound(3, 0);
                clearScreen();
                gameOptionScreen();
                break;
            case 1:
                playSound(3, 0);
                clearScreen();
                LoadGame();
                break;
            case 2: {
                playSound(3, 0);
                clearScreen();
                helpScreen(); // Hiển thị trợ giúp
                break;     // Sau khi quay lại, không tiếp tục xử lý menu chính
            }
            case 3:
                playSound(3, 0);
                clearScreen();
                settingScreen();
                break;
            case 4:
                clearScreen();
                cout << "Ban da thoat!!!" << endl << endl << endl << endl << endl << endl<< endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                exit(100);
                break;
            }
            break;
        }

        // Dùng các phím mũi tên lên/xuống để di chuyển trong menu
        if (ch == 72 or ch == 'w' or ch == 'W') { // Phím mũi tên lên (ASCII 72)
            if (selection > 0) {
                selection--;
                _Y -= 4;
            }
        }
        else if (ch == 80 or ch == 's' or ch == 'S') { // Phím mũi tên xuống (ASCII 80)
            if (selection < 4) {
                selection++;
                _Y += 4;
            }
        }

    } while (true);
}


int menuScreen() {
    ShowBlinkingCursor(false);
    hienthimenu(); // Hiển thị menu
    return 0;
}