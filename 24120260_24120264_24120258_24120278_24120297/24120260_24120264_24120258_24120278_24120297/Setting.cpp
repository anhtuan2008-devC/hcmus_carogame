#include "Setting.h"

void vechuSETTING() {
    SetConsoleOutputCP(CP_UTF8);
    GotoXY(0, 0);
    setColor(Red2);
    cout << u8R"(                                                            
                 ██████                             ████                                 
               ██████████            █████   ████                                    
              ███████████  ███████  ████████ ██████ ████ ██████████   ███████████        
              ████       ███████████ ███████ ██████ ████ ███████████  ████████████       
               █████████ █████   ███ ███████ ██████ ████ ███████████  ████    ████       
               █████████ ███████████ ██████  ████   ████ █████  ████  ████    ████       
                   █████ ███████████ ██████  ████   ████ █████  ████  ████████████       
              ██████████ █████       ██████  ██████ ████ █████  ████  █████████       
                 ██████     ██████     █████  █████ ████ █████  ████  ████████████       
                                                                      ████  █████        
                                                                       ████████                                                                      
)";

    SetConsoleOutputCP(437);
}
// Hàm vẽ thanh âm lượng
void drawVolumeBar(short volume) {
    const int barLength = 50; // Kích thước thanh âm lượng
    int volumeWidth = (volume / 1000.0) * barLength;  // Tính chiều rộng của thanh âm lượng

    GotoXY(10, 15);  // Di chuyển con trỏ đến vị trí vẽ thanh âm lượng
    cout << "Volume: [";  // In phần đầu của thanh âm lượng

    // Vẽ phần thanh âm lượng đầy (với mã ASCII 219)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);  // Màu xanh lá cây
    for (int i = 0; i < volumeWidth; i++) {
        cout << char(219);  // Dùng mã ASCII 219 để vẽ thanh đầy
    }

    // Vẽ phần thanh âm lượng trống (màu xám, với mã ASCII 176)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  // Màu xám
    for (int i = volumeWidth; i < barLength; i++) {
        cout << char(176);  // Dùng mã ASCII 176 cho thanh trống
    }
    setColor(Black);
    cout << "] " << volume << "/1000" << endl;  // In giá trị âm lượng
}

// Hàm vẽ hướng dẫn sử dụng
void drawInstructions() {
    setColor(Red2);
    GotoXY(20, 17);
    cout << "Instructions:" << endl;
    setColor(Black);
    GotoXY(20, 18);
    cout << "Press U to increase volume" << endl;
    GotoXY(20, 19);
    cout << "Press D to decrease volume" << endl;
    GotoXY(20, 20);
    cout << "Press T to toggle between Background and Effect volume" << endl;
    GotoXY(20, 21);
    cout << "Press ESC to back to Menu" << endl;
}


void handleVolume() {
    short volume = 500; // Giá trị âm lượng ban đầu

    while (true) {
        // Chỉ vẽ lại những phần cần thiết
        drawVolumeBar(volume);  // Vẽ lại thanh âm lượng
        drawInstructions();  // Vẽ hướng dẫn

        // Tăng giảm âm lượng bằng cách nhấn phím
        if (_kbhit()) {
            char ch = _getch();  // Đọc phím nhấn
            if (ch == 'p') {  // Nếu nhấn phím 'p'
                volume = min(volume + 50, 1000);  // Tăng âm lượng, tối đa là 1000
            }
            else if (ch == 'o') {  // Nếu nhấn phím 'o'
                volume = max(volume - 50, 0);  // Giảm âm lượng, tối thiểu là 0
            }
            else if (ch == 27) {  // Nếu nhấn phím ESC (mã ASCII là 27)
                break;  // Thoát khỏi vòng lặp
            }
        }

        Sleep(100);  // Thời gian chờ (giảm tải CPU)
    }
}
void settingScreen() {
    system("color 70");
    short backgroundVolume = getBackgroundVolume();
    short effectVolume = getEffectVolume();
    Sleep(10);
    vechuSETTING();

    bool managingBackground = true; // Mặc định quản lý âm thanh nền

    while (true) {
        // Hiển thị trạng thái âm lượng hiện tại
        if (managingBackground) {
            GotoXY(10, 14);
            cout << "Managing: Background Volume" << endl;
            drawVolumeBar(backgroundVolume);
        }
        else {
            GotoXY(10, 14);
            cout << "Managing: Effect Volume    " << endl;
            drawVolumeBar(effectVolume);
        }
        drawInstructions();

        // Xử lý phím bấm
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'd' || ch == 'D') {  // Giảm âm lượng
                playSound(3, 0);
                if (managingBackground) {
                    backgroundVolume = max(backgroundVolume - 50, 0);
                    setBackgroundVolume(backgroundVolume);
                }
                else {
                    effectVolume = max(effectVolume - 50, 0);
                    setEffectVolume(effectVolume);
                }
            }
            else if (ch == 'u' || ch == 'U') {  // Tăng âm lượng
                playSound(3, 0);
                if (managingBackground) {
                    backgroundVolume = min(backgroundVolume + 50, 1000);
                    setBackgroundVolume(backgroundVolume);
                }
                else {
                    effectVolume = min(effectVolume + 50, 1000);
                    setEffectVolume(effectVolume);
                }
            }
            else if (ch == 't' || ch == 'T') {  // Chuyển đổi giữa âm thanh nền và trò chơi
                playSound(3, 0);
                managingBackground = !managingBackground;
            }
            else if (ch == 27) {  // Thoát
                playSound(3, 0);
                Sleep(50);
                clearScreen();
                menuScreen();
                break;
            }
        }

        Sleep(20);  // Giảm tải CPU
    }
}

