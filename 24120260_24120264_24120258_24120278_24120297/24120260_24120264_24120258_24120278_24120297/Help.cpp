#include "Help.h"

void helpBackground() {
    SetConsoleOutputCP(CP_UTF8);
    setColor(124);
    GotoXY(_A[0][0].x, _A[0][0].y);
    cout << u8R"(
      █                  ██████████████████████████████████████████████████████        /\_____/\                █    
      █                  ███   █████   █            ██   ██████     █     █████       /  o   o  \               █    
      █                  ███   █████   ███   ████████    ████████   ███     ███      ( ==  ^  == )              █    
      █                  ███   █████   ███   ████████    ████████   █████   ███       )         (               █    
      █                  ███   █        ██         ██    ████████   ████    ███      (           )              █    
      █                  ███   █        ██        ███    ████████   █      ████     ( (  )   (  ) )             █    
      █                  ███   █████   ███   ████████    ████████   ███████████    (__(__)___(__)__)            █    
      █                  ███   █████   ███   ████████    ████████   ████                                        █    
      █                  ███   █████   ███          █         ███   ███                                         █    
      █                  ██████████████████████████████████████████████                                         █    
      █                                                                                                         █    
      █                                                                                                         █    
      █                                                                                                         █    
      █                                                                                                         █    
      █                                                                                                         █    
      █                                                                                                         █    
      █                                                                                                         █    
      █                                                                                                         █    
      █                                                                                                         █    
      █                                                                                                         █    
      █                                                                                                         █    
      █                                                                                                         █    
      █                                                                                                         █    
      █                                                                                                         █    
      █                                                                                                         █    
      █                                                                                                         █    
      █                                                                                                         █    
      █                                                                                                         █    
)";
    setColor(112);
    SetConsoleOutputCP(437);
}

void helpText() {
    GotoXY(45, 12);
    cout << "Press Enter to select" << endl;
    setColor(121);
    GotoXY(51, 12);
    cout << "Enter" << endl;
    setColor(112);
    GotoXY(45, 13);
    cout << "Press W or Up to move up" << endl;
    setColor(121);
    GotoXY(51, 13);
    cout << "W" << endl;
    GotoXY(56, 13);
    cout << "Up" << endl;
    setColor(112);
    GotoXY(45, 14);
    cout << "Press S or Down to move down" << endl;
    setColor(121);
    GotoXY(51, 14);
    cout << "S" << endl;
    GotoXY(56, 14);
    cout << "Down" << endl;
    setColor(112);
    GotoXY(45, 15);
    cout << "Press A or Left to move left" << endl;
    setColor(121);
    GotoXY(51, 15);
    cout << "A" << endl;
    GotoXY(56, 15);
    cout << "Left" << endl;
    setColor(112);
    GotoXY(45, 16);
    cout << "Press D or Right to move right";
    setColor(121);
    GotoXY(51, 16);
    cout << "D" << endl;
    GotoXY(56, 16);
    cout << "Right" << endl;
    setColor(112);
    GotoXY(45, 17);
    cout << "Press L to save the game" << endl;
    setColor(121);
    GotoXY(51, 17);
    cout << "L" << endl;
    setColor(112);
    GotoXY(25, 18);
    cout << "----------------------------------------------------------------------";
    GotoXY(55, 19);
    setColor(124);
    cout << "ABOUT US";
    setColor(112);
    GotoXY(45, 20);
    cout << "24CTT3 Class of US, VNU-HCM";
    GotoXY(54, 21);
    cout << "16th Group";
    GotoXY(45, 22);
    cout << "Lecturer: Truong Toan Thinh";
    setColor(124);
    GotoXY(43, 25);
    cout << "Press Enter to return to Menu...";
    setColor(112);
}

void helpScreen() {
    Sleep(10);
    helpBackground();
    helpText();
    // Đợi người dùng nhấn Enter 1 lần để quay lại menu chính
    cin.get();    // Đợi người dùng nhấn Enter
    clearScreen();
    playSound(3, 0);
    Sleep(50);
    // Quay lại menu chính sau khi người dùng nhấn Enter
    menuScreen();
}