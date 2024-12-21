#include "PvEMode.h"

void BotMove(int mode) {
    Sleep(10);
    if (mode == 1) {
        hardMode();
    }
}

void gameBotText() {
    SetConsoleOutputCP(CP_UTF8);
    GotoXY(6, 25);
    cout << u8"⭡ - up";
    GotoXY(6, 26);
    cout << u8"⭣ - down";
    GotoXY(6, 27);
    cout << u8"⭠ - left";
    GotoXY(6, 28);
    cout << u8"⭢ - right";
    GotoXY(2, 29);
    cout << "Enter - tick";
    SetConsoleOutputCP(437);
    setColor(121);
    SetConsoleOutputCP(CP_UTF8);
    GotoXY(6, 25);
    cout << u8"⭡";
    GotoXY(6, 26);
    cout << u8"⭣";
    GotoXY(6, 27);
    cout << u8"⭠";
    GotoXY(6, 28);
    cout << u8"⭢";
    GotoXY(2, 29);
    cout << "Enter";
    SetConsoleOutputCP(437);
    // khac
    setColor(132);
    GotoXY(50, 29);
    cout << "Esc - exit";

    GotoXY(63, 29);
    cout << "L - save";

    setColor(112);
}

int countConsecutive(int row, int col, int dx, int dy, int player) {
    int count = 0;
    int r = row + dx, c = col + dy;
    while (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && _A[r][c].c == player) {
        count++;
        r += dx;
        c += dy;
    }
    return count;
}

bool isThreat(int row, int col, int player) {
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue; // Bỏ qua hướng không hợp lệ
            int count = countConsecutive(row, col, dx, dy, player) +
                countConsecutive(row, col, -dx, -dy, player);
            if (count == 3) { // Chuỗi 3 quân liên tiếp
                // Kiểm tra hai đầu có trống không
                int r1 = row + dx * (count + 1), c1 = col + dy * (count + 1);
                int r2 = row - dx * (count + 1), c2 = col - dy * (count + 1);
                if ((r1 >= 0 && r1 < BOARD_SIZE && c1 >= 0 && c1 < BOARD_SIZE && _A[r1][c1].c == 0) ||
                    (r2 >= 0 && r2 < BOARD_SIZE && c2 >= 0 && c2 < BOARD_SIZE && _A[r2][c2].c == 0)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int evaluateMove(int row, int col, int player) {
    int score = 0;

    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue; // Bỏ qua hướng không hợp lệ

            int countPlayer = countConsecutive(row, col, dx, dy, player) +
                countConsecutive(row, col, -dx, -dy, player);

            int r1 = row + dx * (countPlayer + 1), c1 = col + dy * (countPlayer + 1);
            int r2 = row - dx * (countPlayer + 1), c2 = col - dy * (countPlayer + 1);

            // Kiểm tra hai đầu có trống
            bool open1 = (r1 >= 0 && r1 < BOARD_SIZE && c1 >= 0 && c1 < BOARD_SIZE && _A[r1][c1].c == 0);
            bool open2 = (r2 >= 0 && r2 < BOARD_SIZE && c2 >= 0 && c2 < BOARD_SIZE && _A[r2][c2].c == 0);

            // Tính điểm dựa trên chuỗi quân liên tiếp và số đầu trống
            if (countPlayer >= 4 && (open1 || open2)) score += 1000; // Chuỗi 4, có tiềm năng thắng
            else if (countPlayer == 3 && open1 && open2) score += 500; // Chuỗi 3, hai đầu trống
            else if (countPlayer == 3 && (open1 || open2)) score += 200; // Chuỗi 3, một đầu trống
            else if (countPlayer == 2 && open1 && open2) score += 100; // Chuỗi 2, hai đầu trống
        }
    }

    return score;
}

void hardMode() {
    srand(static_cast<unsigned>(time(0))); // Khởi tạo seed cho random
    int bestScore = -1;
    int bestX = -1, bestY = -1;

    // 1. Ưu tiên hoàn thành chuỗi 5 của bot
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (_A[i][j].c == 0) { // Ô trống
                _A[i][j].c = 1; // Giả định bot đánh O
                if (checkWin(i, j, 1)) { // Nếu bot thắng
                    bestX = i;
                    bestY = j;
                    _A[i][j].c = 0; // Trả lại trạng thái ban đầu
                    goto CHOOSE_MOVE; // Ngay lập tức chọn nước đi này
                }
                _A[i][j].c = 0; // Trả lại trạng thái ban đầu
            }
        }
    }

    // 2. Ưu tiên hoàn thành chuỗi 4 của bot
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (_A[i][j].c == 0 && isThreat(i, j, 1)) { // Ô trống và có thể tạo chuỗi 4
                bestX = i;
                bestY = j;
                goto CHOOSE_MOVE; // Chọn ngay nước đi này
            }
        }
    }

    // 3. Chặn chuỗi 5 của đối thủ
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (_A[i][j].c == 0) { // Ô trống
                _A[i][j].c = -1; // Giả định đối thủ đánh X
                if (checkWin(i, j, -1)) { // Nếu đối thủ thắng
                    bestX = i;
                    bestY = j;
                    _A[i][j].c = 0; // Trả lại trạng thái ban đầu
                    goto CHOOSE_MOVE; // Chặn ngay
                }
                _A[i][j].c = 0; // Trả lại trạng thái ban đầu
            }
        }
    }

    // 4. Chặn chuỗi 4 của đối thủ
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (_A[i][j].c == 0 && isThreat(i, j, -1)) { // Ô trống và là mối đe dọa từ X
                bestX = i;
                bestY = j;
                goto CHOOSE_MOVE; // Chặn ngay
            }
        }
    }

    // 5. Tấn công hoặc đánh random
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (_A[i][j].c == 0) { // Ô trống
                _A[i][j].c = 1; // Giả định bot đánh O
                int score = evaluateMove(i, j, 1); // Đánh giá nước đi
                _A[i][j].c = 0; // Trả lại trạng thái ban đầu

                if (score > bestScore) {
                    bestScore = score;
                    bestX = i;
                    bestY = j;
                }
            }
        }
    }

    // Nếu không có nước đi đặc biệt, đánh random
    if (bestX == -1 && bestY == -1) {
        do {
            bestX = rand() % BOARD_SIZE;
            bestY = rand() % BOARD_SIZE;
        } while (_A[bestX][bestY].c != 0); // Tìm ô trống
    }

CHOOSE_MOVE:
    _A[bestX][bestY].c = 1; // Máy đánh O (giá trị 1)
    GotoXY(_A[bestX][bestY].x + 1, _A[bestX][bestY].y);
    cout << O(); // Hiển thị nước đi của máy
}




bool checkWin(int row, int col, int player) {
    // player: -1 (X), 1 (O)
    int count = 1; // Số lượng quân liên tiếp, tính cả quân hiện tại

    // Kiểm tra hàng ngang
    for (int i = col - 1; i >= 0 && _A[row][i].c == player; --i) count++;
    for (int i = col + 1; i < BOARD_SIZE && _A[row][i].c == player; ++i) count++;
    if (count >= 5) return true;

    // Kiểm tra cột dọc
    count = 1; // Reset đếm
    for (int i = row - 1; i >= 0 && _A[i][col].c == player; --i) count++;
    for (int i = row + 1; i < BOARD_SIZE && _A[i][col].c == player; ++i) count++;
    if (count >= 5) return true;

    // Kiểm tra đường chéo chính (trái trên -> phải dưới)
    count = 1; // Reset đếm
    for (int i = 1; row - i >= 0 && col - i >= 0 && _A[row - i][col - i].c == player; ++i) count++;
    for (int i = 1; row + i < BOARD_SIZE && col + i < BOARD_SIZE && _A[row + i][col + i].c == player; ++i) count++;
    if (count >= 5) return true;

    // Kiểm tra đường chéo phụ (phải trên -> trái dưới)
    count = 1; // Reset đếm
    for (int i = 1; row - i >= 0 && col + i < BOARD_SIZE && _A[row - i][col + i].c == player; ++i) count++;
    for (int i = 1; row + i < BOARD_SIZE && col - i >= 0 && _A[row + i][col - i].c == player; ++i) count++;
    if (count >= 5) return true;

    return false; // Không có chuỗi đủ dài
}

void PlayWithBot() {
    ShowBlinkingCursor(true);
    system("color 70");
    fixConsoleWindow();
    StartGame();
    gameBotText();
    int x = 0, y = 0; // Tọa độ bắt đầu (trên bàn cờ)
    bool isPlaying = true;
    int result;

    while (isPlaying) {
        if (_TURN) {
            // Lượt người chơi
            bool validMove = false;
            while (!validMove) {
                GotoXY(_A[x][y].x, _A[x][y].y); // Di chuyển con trỏ đến vị trí hiện tại
                char key = _getch(); // Đợi người chơi nhập phím

                switch (key) {
                case 27:
                    playSound(3, 0);
                    ExitGame();
                    break;
                case 72: // Mũi tên lên
                    if (x > 0) { x--; playSound(2, 0); }
                    break;
                case 80: // Mũi tên xuống
                    if (x < BOARD_SIZE - 1) { x++; playSound(2, 0); }
                    break;
                case 75: // Mũi tên trái
                    if (y > 0) { y--; playSound(2, 0); }
                    break;
                case 77: // Mũi tên phải
                    if (y < BOARD_SIZE - 1) { y++; playSound(2, 0); }
                    break;
                case 13: // Phím Enter
                    if (_A[x][y].c == 0) { // Nếu ô trống
                        _A[x][y].c = -1; // Người chơi luôn đánh X (giá trị -1)
                        GotoXY(_A[x][y].x + 1, _A[x][y].y);
                        cout << X(); // Hiển thị nước đi
                        playSound(3, 0);
                        setColor(112);
                        moveCount(-1);
                        validMove = true; // Thoát khỏi vòng lặp
                    }
                    break;
                default:
                    break;
                }
            }
            _TURN = false;
        }
        else {
            // Lượt máy
            BotMove(1);
            setColor(112);
            moveCount(1);
            _TURN = true;
        }

        // Kiểm tra trạng thái trò chơi
        result = TestBoard();
        if (result != 2) {
            isPlaying = false;
        }

        // Kết thúc trò chơi
        if (result == -1) {
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
            Sleep(800);
            SetConsoleOutputCP(437);
            while (1) {
                if (AskContinue() == 'N') {
                    playSound(3, 0);
                    Sleep(100);
                    ExitGame();
                    break;
                }
                else if (AskContinue() == 'Y') {
                    playSound(3, 0);
                    Sleep(100);
                    ShowBlinkingCursor(true);
                    system("color 70");
                    clearScreen();
                    ResetData();
                    fixConsoleWindow();
                    DrawBoard(BOARD_SIZE);
                    displayScore(0);
                    moveCount(0);
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
                    isPlaying = true;
                    break;
                }
                else continue;
            }
        }
        else if (result == 1) {
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
            SetConsoleOutputCP(437);
            while (1) {
                if (AskContinue() == 'N') {
                    playSound(3, 0);
                    ExitGame();
                    break;
                }
                else if (AskContinue() == 'Y') {
                    ShowBlinkingCursor(true);
                    system("color 70");
                    clearScreen();
                    ResetData();
                    fixConsoleWindow();
                    DrawBoard(BOARD_SIZE);
                    displayScore(0);
                    moveCount(0);
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
                    isPlaying = true;
                    break;
                }
                else continue;
            }
        }
        else if (TestBoard() == 0) {
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
            SetConsoleOutputCP(437);
            while (1) {
                if (AskContinue() == 'N') {
                    Sleep(100);
                    playSound(3, 0);
                    ExitGame();
                    break;
                }
                else if (AskContinue() == 'Y') {
                    Sleep(100);
                    playSound(3, 0);
                    Sleep(100);
                    ShowBlinkingCursor(true);
                    system("color 70");
                    clearScreen();
                    ResetData();
                    fixConsoleWindow();
                    DrawBoard(BOARD_SIZE);
                    displayScore(0);
                    moveCount(0);
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
                    isPlaying = true;
                    break;
                }
                else continue;
            }
        }
    }


}