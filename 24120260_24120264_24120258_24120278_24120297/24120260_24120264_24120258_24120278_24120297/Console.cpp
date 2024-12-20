#include "Console.h"

// Hàm xóa màn hình (clear screen)
void clearScreen() {
#ifdef _WIN32
	system("cls"); // Dành cho Windows
#else
	system("clear"); // Dành cho Linux/Mac
#endif
	SetConsoleTitle(L"Caro");
	fixConsoleWindow();
	DisableScrollbar();
	system("color 70");
}

//screen: goto [x,y]
void GotoXY(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void ShowBlinkingCursor(bool isVisible) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;

	// Lấy thông tin con trỏ hiện tại
	GetConsoleCursorInfo(hConsole, &cursorInfo);

	// Cài đặt con trỏ nhấp nháy và hiện thị dựa trên tham số truyền vào
	cursorInfo.bVisible = isVisible;
	cursorInfo.dwSize = isVisible ? 25 : 2; 
	SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void fixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow(); // Lấy handle của console
	if (consoleWindow == NULL) {
		cerr << "Error: Unable to get console window handle." << endl;
		return;
	}

	// Loại bỏ khả năng thay đổi kích thước và phóng to cửa sổ
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style &= ~(WS_SIZEBOX | WS_MAXIMIZEBOX); // Bỏ WS_SIZEBOX và WS_MAXIMIZEBOX
	SetWindowLong(consoleWindow, GWL_STYLE, style);

	// Cập nhật thay đổi
	SetWindowPos(consoleWindow, NULL, 0, 0, 0, 0,
		SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
}

void SetWindowSize(SHORT width, SHORT height) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	SMALL_RECT WindowSize;
	WindowSize.Top = 0;
	WindowSize.Left = 0;
	WindowSize.Right = width - 1; // Adjusted for index-based coordinate
	WindowSize.Bottom = height - 1;

	if (!SetConsoleWindowInfo(hStdout, TRUE, &WindowSize)) {
		cerr << "Error setting console window size: " << GetLastError() << endl;
	}
}

void SetScreenBufferSize(SHORT width, SHORT height)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD NewSize;
	NewSize.X = width;
	NewSize.Y = height;

	SetConsoleScreenBufferSize(hStdout, NewSize);
}

void DisableSelection() {
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

	SetConsoleMode(hStdin, ~ENABLE_QUICK_EDIT_MODE);
}

void ShowScrollbar(BOOL Show)
{
	HWND hWnd = GetConsoleWindow();
	ShowScrollBar(hWnd, SB_BOTH, Show);
}

void DisableScrollbar() {
	HWND hWnd = GetConsoleWindow();
	if (hWnd == NULL) {
		cerr << "Error: Unable to get console window handle." << endl;
		return;
	}

	ShowScrollBar(hWnd, SB_BOTH, FALSE); // Tắt thanh cuộn ngang và dọc
}

void BOX(int x, int y, int w, int h) {
	// Vẽ bên trong hộp
	x--; y--;
	for (int iy = y; iy < y + h; iy++) {
		for (int ix = x; ix < x + w; ix++) {
			GotoXY(ix, iy);
			cout << " ";
		}
	}
	// Vẽ viền trên và dưới của hộp
	for (int ix = x; ix < x + w; ix++) {
		GotoXY(ix, y); // Viền trên
		cout << char(196); // ─
		GotoXY(ix, y + h - 1); // Viền dưới
		cout << char(196); // ─
	}

	// Vẽ viền trái và phải của hộp
	for (int iy = y; iy < y + h; iy++) {
		GotoXY(x, iy); // Viền trái
		cout << char(179); // │
		GotoXY(x + w - 1, iy); // Viền phải
		cout << char(179); // │
	}

	// Vẽ các góc của hộp
	GotoXY(x, y); // Góc trên bên trái
	cout << char(218); // ┌
	GotoXY(x + w - 1, y); // Góc trên bên phải
	cout << char(191); // ┐
	GotoXY(x, y + h - 1); // Góc dưới bên trái
	cout << char(192); // └
	GotoXY(x + w - 1, y + h - 1); // Góc dưới bên phải
	cout << char(217); // ┘
}

void printAsciiArt(const string& filename, int startX = 0, int startY = 0) {
	ifstream file(filename);
	string line;
	int currentY = startY; // Y vị trí bắt đầu in
	if (!file.is_open()) {
		cerr << "Unable to open file: " << filename << endl;
		return;
	}

	while (getline(file, line)) {
		GotoXY(startX, currentY); // Di chuyển con trỏ tới (startX, currentY)
		cout << line;
		currentY++; // Di chuyển xuống dòng tiếp theo
	}
	file.close();
}

void SSetColor(int mauBg, int mauchu) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (mauBg << 4) | mauchu);
}

// Hàm vẽ hộp chứa nội dung
void box(int x, int y, int w, int h, string nd) {
	// Vẽ bên trong hộp
	x--; y--;
	for (int iy = y; iy < y + h; iy++) {
		for (int ix = x; ix < x + w; ix++) {
			GotoXY(ix, iy);
			cout << " ";
		}
	}

	// Hiển thị nội dung trong hộp
	GotoXY(x + 5, y + 2); // Vị trí hiển thị nội dung trong hộp
	cout << nd;

	// Vẽ viền trên và dưới của hộp
	for (int ix = x; ix < x + w; ix++) {
		GotoXY(ix, y); // Viền trên
		cout << char(196); // ─
		GotoXY(ix, y + h - 1); // Viền dưới
		cout << char(196); // ─
	}

	// Vẽ viền trái và phải của hộp
	for (int iy = y; iy < y + h; iy++) {
		GotoXY(x, iy); // Viền trái
		cout << char(179); // │
		GotoXY(x + w - 1, iy); // Viền phải
		cout << char(179); // │
	}

	// Vẽ các góc của hộp
	GotoXY(x, y); // Góc trên bên trái
	cout << char(218); // ┌
	GotoXY(x + w - 1, y); // Góc trên bên phải
	cout << char(191); // ┐
	GotoXY(x, y + h - 1); // Góc dưới bên trái
	cout << char(192); // └
	GotoXY(x + w - 1, y + h - 1); // Góc dưới bên phải
	cout << char(217); // ┘
}
