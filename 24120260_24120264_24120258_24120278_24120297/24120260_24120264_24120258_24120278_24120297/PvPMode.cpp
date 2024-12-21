#include "PvPMode.h"

void gameBackground() {
    SetConsoleOutputCP(CP_UTF8);
//    setColor(116);
//    GotoXY(0, 20);
//    cout << u8R"(                                                                                                                        
//        ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⣦⣴⣶⣶⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣤⣤⣤⣤⣤⣤⣀⣀⣀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣶⠿⠟⠛⠛⠋⠉⠉⠉⠉⠉⠉⠛⠛⠛⠿⢷⣦⣤⣀⡹⠿⠿⠛⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⠀⠀⠀⣠⣤⣴⣶⣶⣾⠟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠻⣿⣿⣶⣶⣶⣤⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⠀⣴⣿⠟⠉⠀⠀⠙⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠟⠀⠀⠀⠉⠙⢿⣦⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⣠⣿⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢦⣽⣿⡄⠀⠀⠀⠀⠀
//⠀⠀⠀⣰⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣷⠀⠀⠀⠀⠀
//⠀⠀⢰⣿⡏⣤⠀⠀⠀⠀⠀⢀⡼⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣻⡀⠀⠀⢤⢠⣼⣿⡆⠀⠀⠀⠀
//⠀⠀⠀⢿⣿⠁⠀⠀⠀⠀⣴⡾⠁⠀⠀⠀⢀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣀⠀⠀⠀⠀⠀⠈⢻⣇⠀⠀⠈⣇⣿⣿⠀⠀⠀⠀⠀
//⠀⠀⠀⢸⣿⠀⡀⣀⠀⢠⣿⠃⠀⠀⢀⣾⣿⣿⡿⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⡷⠀⠀⠀⠀⠀⢸⣿⠀⢠⣠⣿⣿⠇⠀⠀⠀⠀⠀
//⠀⠀⠀⠈⢿⣷⣇⣽⠀⢈⡏⠀⠀⠀⠸⣿⣿⣿⣦⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣧⣤⠥⠀⠀⠀⠀⣿⣿⣧⣾⣿⠟⠁⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⠈⠛⠿⣿⣧⣾⣿⡄⠀⠀⠀⠙⠿⠿⠿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠛⠛⠋⠀⠀⠀⠀⠀⢸⣿⡿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⣿⡇⣴⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⢶⣼⣿⣀⣠⣤⣤⣤⣀⠀⠀⠀⠀⠀
//⠀⠀⣠⣶⣾⠿⠛⠛⠻⢷⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣿⡿⠋⠉⠉⠉⠛⢿⣦⡀⠀⠀
//⢀⣾⡿⠋⠀⠀⠀⠀⠀⠀⠙⣿⡆⢀⠀⠀⠀⠀⠀⠀⠀⠘⢿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣤⣿⡟⠀⠀⠀⠀⠀⠀⠀⠹⣿⡆⠀
//⣼⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⣸⣷⣿⣷⣧⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣄⠀⢠⡾⣠⣇⣠⣿⣿⣿⡇⠀⢀⠀⠀⠀⢀⠀⠀⢹⣷⠀
//⣿⣷⡀⠀⣷⠀⠀⠀⣼⣦⣴⣿⠏⠙⠻⠿⣷⡿⠷⣶⣶⡾⠿⠿⠷⢶⣶⣦⣤⣾⣿⣷⣿⣿⠿⠿⠛⠛⠙⠻⣿⣤⣾⣇⠀⢀⣸⣇⣀⣼⣿⠃
//⠘⢿⣿⣾⣿⣷⣴⣾⡿⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠛⠻⠿⠿⠿⠟⠛⠛⠁⠀                                                           
//)";
//    GotoXY(0, 13);
    SetConsoleOutputCP(437);
    setColor(112);
}
void vienPlayer() {
    // Viền X
    BOX(2, 16, 16, 10);
    // Viền O
    BOX(20, 16, 16, 10);
    GotoXY(_A[0][0].x + 49, _A[0][0].y + 11);
    turnPlayer();   // Cập nhật giao diện theo lượt
    playSound(3, 0);
}

void turnPlayer() {
    if (_TURN == true) {
        SetConsoleOutputCP(CP_UTF8);
        setColor(120);
        GotoXY(4, 17);
        cout << u8" ██╗  ██╗";
        GotoXY(4, 18);
        cout << u8" ╚██╗██╔╝  ";
        GotoXY(4, 19);
        cout << u8"  ╚███╔╝ ";
        GotoXY(4, 20);
        cout << u8"  ██╔██╗ ";
        GotoXY(4, 21);
        cout << u8" ██╔╝ ██╗";
        GotoXY(4, 22);
        cout << u8" ╚═╝  ╚═╝";
        SetConsoleOutputCP(437);

        // An O
        SetConsoleOutputCP(CP_UTF8);
        setColor(121);
        GotoXY(22, 17);
        cout << u8"  ██████╗ ";
        GotoXY(22, 18);
        cout << u8" ██╔═══██╗";
        GotoXY(22, 19);
        cout << u8" ██║   ██║";
        GotoXY(22, 20);
        cout << u8" ██║   ██║";
        GotoXY(22, 21);
        cout << u8" ╚██████╔╝";
        GotoXY(22, 22);
        cout << u8"  ╚═════╝";
        SetConsoleOutputCP(437);
    }
    else {
        // An X
        SetConsoleOutputCP(CP_UTF8);
        setColor(124);
        GotoXY(4, 17);
        cout << u8" ██╗  ██╗";
        GotoXY(4, 18);
        cout << u8" ╚██╗██╔╝  ";
        GotoXY(4, 19);
        cout << u8"  ╚███╔╝ ";
        GotoXY(4, 20);
        cout << u8"  ██╔██╗ ";
        GotoXY(4, 21);
        cout << u8" ██╔╝ ██╗";
        GotoXY(4, 22);
        cout << u8" ╚═╝  ╚═╝";
        SetConsoleOutputCP(437);
        // Hien thi O
        SetConsoleOutputCP(CP_UTF8);
        setColor(120);
        GotoXY(22, 17);
        cout << u8"  ██████╗ ";
        GotoXY(22, 18);
        cout << u8" ██╔═══██╗";
        GotoXY(22, 19);
        cout << u8" ██║   ██║";
        GotoXY(22, 20);
        cout << u8" ██║   ██║";
        GotoXY(22, 21);
        cout << u8" ╚██████╔╝";
        GotoXY(22, 22);
        cout << u8"  ╚═════╝";
        SetConsoleOutputCP(437);
    }
    setColor(112);
}

void gameText() {
    // Viet chu
        //X
    setColor(120);
    GotoXY(6, 25);
    cout << "W - up";
    GotoXY(6, 26);
    cout << "S - down";
    GotoXY(6, 27);
    cout << "A - left";
    GotoXY(6, 28);
    cout << "D - right";
    GotoXY(2, 29);
    cout << "Space - tick";

    //O
    SetConsoleOutputCP(CP_UTF8);
    GotoXY(24, 25);
    cout << u8"⭡ - up";
    GotoXY(24, 26);
    cout << u8"⭣ - down";
    GotoXY(24, 27);
    cout << u8"⭠ - left";
    GotoXY(24, 28);
    cout << u8"⭢ - right";
    GotoXY(20, 29);
    cout << "Enter - tick";
    SetConsoleOutputCP(437);

    // To mau chu
        // X
    setColor(124);
    GotoXY(6, 25);
    cout << "W";
    GotoXY(6, 26);
    cout << "S";
    GotoXY(6, 26);
    cout << "S";
    GotoXY(6, 27);
    cout << "A";
    GotoXY(6, 28);
    cout << "D";
    GotoXY(2, 29);
    cout << "Space";
    // O
    setColor(121);
    SetConsoleOutputCP(CP_UTF8);
    GotoXY(24, 25);
    cout << u8"⭡";
    GotoXY(24, 26);
    cout << u8"⭣";
    GotoXY(24, 27);
    cout << u8"⭠";
    GotoXY(24, 28);
    cout << u8"⭢";
    GotoXY(20, 29);
    cout << "Enter";
    SetConsoleOutputCP(437);
    // khac
    setColor(132);
    GotoXY(50, 29);
    cout << "Esc - pause";

    GotoXY(63, 29);
    cout << "L - save";

    setColor(112);
}
// Hàm xử lý khi người chơi thua
int ProcessFinish(int pWhoWin) {
    GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 2); // Nhảy tới vị trí thích hợp
    switch (pWhoWin) {
    case -1:
        playSound(4, 0);
        Sleep(800);
        SetConsoleOutputCP(CP_UTF8);
        setColor(124);
        GotoXY(85, 2);
        cout << u8"██╗  ██╗ ██╗    ██╗██╗███╗   ██╗██╗";
        GotoXY(85, 3);
        cout << u8"╚██╗██╔╝ ██║    ██║██║████╗  ██║██║";
        GotoXY(86, 4);
        cout << u8"╚███╔╝  ██║ █╗ ██║██║██╔██╗ ██║██║";
        GotoXY(86, 5);
        cout << u8"██╔██╗  ██║███╗██║██║██║╚██╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"██╔╝ ██╗ ╚███╔███╔╝██║██║ ╚████║██╗";
        GotoXY(85, 7);
        cout << u8"╚═╝  ╚═╝  ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝";
        Sleep(150);
        setColor(120);
        GotoXY(85, 2);
        cout << u8"██╗  ██╗ ██╗    ██╗██╗███╗   ██╗██╗";
        GotoXY(85, 3);
        cout << u8"╚██╗██╔╝ ██║    ██║██║████╗  ██║██║";
        GotoXY(86, 4);
        cout << u8"╚███╔╝  ██║ █╗ ██║██║██╔██╗ ██║██║";
        GotoXY(86, 5);
        cout << u8"██╔██╗  ██║███╗██║██║██║╚██╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"██╔╝ ██╗ ╚███╔███╔╝██║██║ ╚████║██╗";
        GotoXY(85, 7);
        cout << u8"╚═╝  ╚═╝  ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝";
        Sleep(150);
        setColor(124);
        GotoXY(85, 2);
        cout << u8"██╗  ██╗ ██╗    ██╗██╗███╗   ██╗██╗";
        GotoXY(85, 3);
        cout << u8"╚██╗██╔╝ ██║    ██║██║████╗  ██║██║";
        GotoXY(86, 4);
        cout << u8"╚███╔╝  ██║ █╗ ██║██║██╔██╗ ██║██║";
        GotoXY(86, 5);
        cout << u8"██╔██╗  ██║███╗██║██║██║╚██╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"██╔╝ ██╗ ╚███╔███╔╝██║██║ ╚████║██╗";
        GotoXY(85, 7);
        cout << u8"╚═╝  ╚═╝  ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝";
        Sleep(150);
        setColor(120);
        GotoXY(85, 2);
        cout << u8"██╗  ██╗ ██╗    ██╗██╗███╗   ██╗██╗";
        GotoXY(85, 3);
        cout << u8"╚██╗██╔╝ ██║    ██║██║████╗  ██║██║";
        GotoXY(86, 4);
        cout << u8"╚███╔╝  ██║ █╗ ██║██║██╔██╗ ██║██║";
        GotoXY(86, 5);
        cout << u8"██╔██╗  ██║███╗██║██║██║╚██╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"██╔╝ ██╗ ╚███╔███╔╝██║██║ ╚████║██╗";
        GotoXY(85, 7);
        cout << u8"╚═╝  ╚═╝  ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝";
        Sleep(150);
        setColor(124);
        GotoXY(85, 2);
        cout << u8"██╗  ██╗ ██╗    ██╗██╗███╗   ██╗██╗";
        GotoXY(85, 3);
        cout << u8"╚██╗██╔╝ ██║    ██║██║████╗  ██║██║";
        GotoXY(86, 4);
        cout << u8"╚███╔╝  ██║ █╗ ██║██║██╔██╗ ██║██║";
        GotoXY(86, 5);
        cout << u8"██╔██╗  ██║███╗██║██║██║╚██╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"██╔╝ ██╗ ╚███╔███╔╝██║██║ ╚████║██╗";
        GotoXY(85, 7);
        cout << u8"╚═╝  ╚═╝  ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝";
        Sleep(150);
        setColor(120);
        GotoXY(85, 2);
        cout << u8"██╗  ██╗ ██╗    ██╗██╗███╗   ██╗██╗";
        GotoXY(85, 3);
        cout << u8"╚██╗██╔╝ ██║    ██║██║████╗  ██║██║";
        GotoXY(86, 4);
        cout << u8"╚███╔╝  ██║ █╗ ██║██║██╔██╗ ██║██║";
        GotoXY(86, 5);
        cout << u8"██╔██╗  ██║███╗██║██║██║╚██╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"██╔╝ ██╗ ╚███╔███╔╝██║██║ ╚████║██╗";
        GotoXY(85, 7);
        cout << u8"╚═╝  ╚═╝  ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝";
        Sleep(150);
        setColor(124);
        GotoXY(85, 2);
        cout << u8"██╗  ██╗ ██╗    ██╗██╗███╗   ██╗██╗";
        GotoXY(85, 3);
        cout << u8"╚██╗██╔╝ ██║    ██║██║████╗  ██║██║";
        GotoXY(86, 4);
        cout << u8"╚███╔╝  ██║ █╗ ██║██║██╔██╗ ██║██║";
        GotoXY(86, 5);
        cout << u8"██╔██╗  ██║███╗██║██║██║╚██╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"██╔╝ ██╗ ╚███╔███╔╝██║██║ ╚████║██╗";
        GotoXY(85, 7);
        cout << u8"╚═╝  ╚═╝  ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝";
        Sleep(650);
        break;
    case 1:
        playSound(4, 0);
        Sleep(800);
        SetConsoleOutputCP(CP_UTF8);
        setColor(121);
        GotoXY(86, 2);
        cout << u8"█████╗  ██╗    ██╗██╗███╗   ██╗██╗";
        GotoXY(85, 3);
        cout << u8"██╔══██╗ ██║    ██║██║████╗  ██║██║";
        GotoXY(85, 4);
        cout << u8"██║  ██║ ██║ █╗ ██║██║██╔██╗ ██║██║";
        GotoXY(85, 5);
        cout << u8"██║  ██║ ██║███╗██║██║██║╚██╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"╚█████╔╝ ╚███╔███╔╝██║██║ ╚████║██╗";
        GotoXY(86, 7);
        cout << u8"╚════╝   ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝";
        Sleep(150);
        setColor(120);
        GotoXY(86, 2);
        cout << u8"█████╗  ██╗    ██╗██╗███╗   ██╗██╗";
        GotoXY(85, 3);
        cout << u8"██╔══██╗ ██║    ██║██║████╗  ██║██║";
        GotoXY(85, 4);
        cout << u8"██║  ██║ ██║ █╗ ██║██║██╔██╗ ██║██║";
        GotoXY(85, 5);
        cout << u8"██║  ██║ ██║███╗██║██║██║╚██╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"╚█████╔╝ ╚███╔███╔╝██║██║ ╚████║██╗";
        GotoXY(86, 7);
        cout << u8"╚════╝   ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝";
        Sleep(150);
        setColor(121);
        GotoXY(86, 2);
        cout << u8"█████╗  ██╗    ██╗██╗███╗   ██╗██╗";
        GotoXY(85, 3);
        cout << u8"██╔══██╗ ██║    ██║██║████╗  ██║██║";
        GotoXY(85, 4);
        cout << u8"██║  ██║ ██║ █╗ ██║██║██╔██╗ ██║██║";
        GotoXY(85, 5);
        cout << u8"██║  ██║ ██║███╗██║██║██║╚██╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"╚█████╔╝ ╚███╔███╔╝██║██║ ╚████║██╗";
        GotoXY(86, 7);
        cout << u8"╚════╝   ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝";
        Sleep(150);
        setColor(120);
        GotoXY(86, 2);
        cout << u8"█████╗  ██╗    ██╗██╗███╗   ██╗██╗";
        GotoXY(85, 3);
        cout << u8"██╔══██╗ ██║    ██║██║████╗  ██║██║";
        GotoXY(85, 4);
        cout << u8"██║  ██║ ██║ █╗ ██║██║██╔██╗ ██║██║";
        GotoXY(85, 5);
        cout << u8"██║  ██║ ██║███╗██║██║██║╚██╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"╚█████╔╝ ╚███╔███╔╝██║██║ ╚████║██╗";
        GotoXY(86, 7);
        cout << u8"╚════╝   ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝";
        Sleep(150);
        setColor(121);
        GotoXY(86, 2);
        cout << u8"█████╗  ██╗    ██╗██╗███╗   ██╗██╗";
        GotoXY(85, 3);
        cout << u8"██╔══██╗ ██║    ██║██║████╗  ██║██║";
        GotoXY(85, 4);
        cout << u8"██║  ██║ ██║ █╗ ██║██║██╔██╗ ██║██║";
        GotoXY(85, 5);
        cout << u8"██║  ██║ ██║███╗██║██║██║╚██╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"╚█████╔╝ ╚███╔███╔╝██║██║ ╚████║██╗";
        GotoXY(86, 7);
        cout << u8"╚════╝   ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝";
        Sleep(150);
        setColor(120);
        GotoXY(86, 2);
        cout << u8"█████╗  ██╗    ██╗██╗███╗   ██╗██╗";
        GotoXY(85, 3);
        cout << u8"██╔══██╗ ██║    ██║██║████╗  ██║██║";
        GotoXY(85, 4);
        cout << u8"██║  ██║ ██║ █╗ ██║██║██╔██╗ ██║██║";
        GotoXY(85, 5);
        cout << u8"██║  ██║ ██║███╗██║██║██║╚██╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"╚█████╔╝ ╚███╔███╔╝██║██║ ╚████║██╗";
        GotoXY(86, 7);
        cout << u8"╚════╝   ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝";
        Sleep(150);
        setColor(121);
        GotoXY(86, 2);
        cout << u8"█████╗  ██╗    ██╗██╗███╗   ██╗██╗";
        GotoXY(85, 3);
        cout << u8"██╔══██╗ ██║    ██║██║████╗  ██║██║";
        GotoXY(85, 4);
        cout << u8"██║  ██║ ██║ █╗ ██║██║██╔██╗ ██║██║";
        GotoXY(85, 5);
        cout << u8"██║  ██║ ██║███╗██║██║██║╚██╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"╚█████╔╝ ╚███╔███╔╝██║██║ ╚████║██╗";
        GotoXY(86, 7);
        cout << u8"╚════╝   ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝";
        Sleep(650);
        break;
    case 0:
        playSound(4, 0);
        Sleep(800);
        SetConsoleOutputCP(CP_UTF8);
        setColor(122);
        GotoXY(85, 2);
        cout << u8"█████╗ █████╗  █████╗ ██╗    ██╗██╗";
        GotoXY(85, 3);
        cout << u8"██╔═██╗██╔═██╗██╔══██╗██║    ██║██║";
        GotoXY(85, 4);
        cout << u8"██║ ██║█████╔╝███████║██║ █╗ ██║██║";
        GotoXY(85, 5);
        cout << u8"██║ ██║██╔═██╗██╔══██║██║███╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"█████╔╝██║ ██║██║  ██║╚███╔███╔╝██╗";
        GotoXY(85, 7);
        cout << u8"╚════╝ ╚═╝ ╚═╝╚═╝  ╚═╝ ╚══╝╚══╝ ╚═╝";
        Sleep(150);
        setColor(120);
        GotoXY(85, 2);
        cout << u8"█████╗ █████╗  █████╗ ██╗    ██╗██╗";
        GotoXY(85, 3);
        cout << u8"██╔═██╗██╔═██╗██╔══██╗██║    ██║██║";
        GotoXY(85, 4);
        cout << u8"██║ ██║█████╔╝███████║██║ █╗ ██║██║";
        GotoXY(85, 5);
        cout << u8"██║ ██║██╔═██╗██╔══██║██║███╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"█████╔╝██║ ██║██║  ██║╚███╔███╔╝██╗";
        GotoXY(85, 7);
        cout << u8"╚════╝ ╚═╝ ╚═╝╚═╝  ╚═╝ ╚══╝╚══╝ ╚═╝";
        Sleep(150);
        setColor(122);
        GotoXY(85, 2);
        cout << u8"█████╗ █████╗  █████╗ ██╗    ██╗██╗";
        GotoXY(85, 3);
        cout << u8"██╔═██╗██╔═██╗██╔══██╗██║    ██║██║";
        GotoXY(85, 4);
        cout << u8"██║ ██║█████╔╝███████║██║ █╗ ██║██║";
        GotoXY(85, 5);
        cout << u8"██║ ██║██╔═██╗██╔══██║██║███╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"█████╔╝██║ ██║██║  ██║╚███╔███╔╝██╗";
        GotoXY(85, 7);
        cout << u8"╚════╝ ╚═╝ ╚═╝╚═╝  ╚═╝ ╚══╝╚══╝ ╚═╝";
        Sleep(150);
        setColor(120);
        GotoXY(85, 2);
        cout << u8"█████╗ █████╗  █████╗ ██╗    ██╗██╗";
        GotoXY(85, 3);
        cout << u8"██╔═██╗██╔═██╗██╔══██╗██║    ██║██║";
        GotoXY(85, 4);
        cout << u8"██║ ██║█████╔╝███████║██║ █╗ ██║██║";
        GotoXY(85, 5);
        cout << u8"██║ ██║██╔═██╗██╔══██║██║███╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"█████╔╝██║ ██║██║  ██║╚███╔███╔╝██╗";
        GotoXY(85, 7);
        cout << u8"╚════╝ ╚═╝ ╚═╝╚═╝  ╚═╝ ╚══╝╚══╝ ╚═╝";
        Sleep(150);
        setColor(122);
        GotoXY(85, 2);
        cout << u8"█████╗ █████╗  █████╗ ██╗    ██╗██╗";
        GotoXY(85, 3);
        cout << u8"██╔═██╗██╔═██╗██╔══██╗██║    ██║██║";
        GotoXY(85, 4);
        cout << u8"██║ ██║█████╔╝███████║██║ █╗ ██║██║";
        GotoXY(85, 5);
        cout << u8"██║ ██║██╔═██╗██╔══██║██║███╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"█████╔╝██║ ██║██║  ██║╚███╔███╔╝██╗";
        GotoXY(85, 7);
        cout << u8"╚════╝ ╚═╝ ╚═╝╚═╝  ╚═╝ ╚══╝╚══╝ ╚═╝";
        Sleep(150);
        setColor(120);
        GotoXY(85, 2);
        cout << u8"█████╗ █████╗  █████╗ ██╗    ██╗██╗";
        GotoXY(85, 3);
        cout << u8"██╔═██╗██╔═██╗██╔══██╗██║    ██║██║";
        GotoXY(85, 4);
        cout << u8"██║ ██║█████╔╝███████║██║ █╗ ██║██║";
        GotoXY(85, 5);
        cout << u8"██║ ██║██╔═██╗██╔══██║██║███╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"█████╔╝██║ ██║██║  ██║╚███╔███╔╝██╗";
        GotoXY(85, 7);
        cout << u8"╚════╝ ╚═╝ ╚═╝╚═╝  ╚═╝ ╚══╝╚══╝ ╚═╝";
        Sleep(150);
        setColor(122);
        GotoXY(85, 2);
        cout << u8"█████╗ █████╗  █████╗ ██╗    ██╗██╗";
        GotoXY(85, 3);
        cout << u8"██╔═██╗██╔═██╗██╔══██╗██║    ██║██║";
        GotoXY(85, 4);
        cout << u8"██║ ██║█████╔╝███████║██║ █╗ ██║██║";
        GotoXY(85, 5);
        cout << u8"██║ ██║██╔═██╗██╔══██║██║███╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"█████╔╝██║ ██║██║  ██║╚███╔███╔╝██╗";
        GotoXY(85, 7);
        cout << u8"╚════╝ ╚═╝ ╚═╝╚═╝  ╚═╝ ╚══╝╚══╝ ╚═╝";
        Sleep(650);
        break;
    case 2:
        _TURN = !_TURN; // Đổi lượt nếu không có gì xảy ra
        break;
    }
    GotoXY(_X, _Y); // Trả về vị trí hiện hành của con trỏ màn hình bàn cờ
    SetConsoleOutputCP(437);
    return pWhoWin;
}

int AskContinue() {
    ShowBlinkingCursor(false);
    setColor(112);
    BOX(87, 10, 32, 3);
    GotoXY(88, 10);
    printf("Press Y/N to Play Again/Back"); // Nhập Y để chơi tiếp hoặc nhập N để quay về Menu
    char response = _getch();
    ShowBlinkingCursor(true);
    return toupper(response);
}

int PlayWithPlayer() {
    ShowBlinkingCursor(true);
    system("color 70");
    StartGame();
    SetConsoleOutputCP(437);
    gameText();
    GotoXY(_A[0][0].x + 1, _A[0][0].y);
    bool validEnter = true;
    while (true) {
        Sleep(100);
        char command = getInput(); // Lấy đầu vào từ phím
        if (command) {
            command = toupper(command);
            if (command == 27) { // ESC để thoát
                playSound(3, 0);
                Sleep(10);
                ExitGame();
                break;
            }
            else {
                if (command == 'A') {
                    MoveLeft();
                }
                else if (command == 'W') MoveUp();
                else if (command == 'S') MoveDown();
                else if (command == 'D') MoveRight();
                else if (command == 13) { // Nhấn Enter để đánh dấu
                    switch (CheckBoard(_X, _Y)) {
                    case -1:
                        playSound(3, 0);
                        vienPlayer();
                        moveCount(-1);
                        break; // Quân X đã được vẽ
                    case 1:
                        playSound(3, 0);
                        vienPlayer();
                        moveCount(1);
                        break; // Quân O đã được vẽ
                    case 0:
                        validEnter = false; // Ô đã được đánh dấu
                        break;
                    }
                    if (validEnter) {
                        switch (ProcessFinish(TestBoard())) {
                        case -1: case 1: case 0:
                            if (AskContinue() != 'Y') {
                                playSound(3, 0);
                                ExitGame();
                                return 0;
                            }
                            else if (AskContinue() == 'Y') {
                                continueGame();
                                // Viền X
                                BOX(2, 16, 16, 10);
                                // Viền O
                                BOX(20, 16, 16, 10);
                                // hien thi X truoc
                                SetConsoleOutputCP(CP_UTF8);
                                setColor(124);
                                GotoXY(4, 17);
                                cout << u8" ██╗  ██╗";
                                GotoXY(4, 18);
                                cout << u8" ╚██╗██╔╝  ";
                                GotoXY(4, 19);
                                cout << u8"  ╚███╔╝ ";
                                GotoXY(4, 20);
                                cout << u8"  ██╔██╗ ";
                                GotoXY(4, 21);
                                cout << u8" ██╔╝ ██╗";
                                GotoXY(4, 22);
                                cout << u8" ╚═╝  ╚═╝";
                                SetConsoleOutputCP(437);
                                // O den
                                SetConsoleOutputCP(CP_UTF8);
                                setColor(120);
                                GotoXY(22, 17);
                                cout << u8"  ██████╗ ";
                                GotoXY(22, 18);
                                cout << u8" ██╔═══██╗";
                                GotoXY(22, 19);
                                cout << u8" ██║   ██║";
                                GotoXY(22, 20);
                                cout << u8" ██║   ██║";
                                GotoXY(22, 21);
                                cout << u8" ╚██████╔╝";
                                GotoXY(22, 22);
                                cout << u8"  ╚═════╝";
                                gameText();
                                GotoXY(_A[0][0].x, _A[0][0].y);
                                break;
                            }
                            else {
                                break;
                            }
                        default:
                            break;
                        }
                    }
                    validEnter = true; // Mở khóa
                }
                else if (command == 'L') {
                    clearScreen();
                    SaveGame();
                    clearScreen();
                    break;
                }
            }
        }
    }
}