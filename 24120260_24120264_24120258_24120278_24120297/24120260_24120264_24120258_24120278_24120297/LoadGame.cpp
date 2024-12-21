#include "LoadGame.h"

#include <tlhelp32.h>
#include <psapi.h>

wstring ConvertToWideString(const string& str) {
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.size(), NULL, 0);
    wstring wstrTo(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.size(), &wstrTo[0], size_needed);
    return wstrTo;
}

void TerminateProcessesUsingFile(const string& filename) {
    HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapShot == INVALID_HANDLE_VALUE) {
        cerr << "Khong the tao snapshot " << endl;
        return;
    }

    PROCESSENTRY32 procEntry;
    procEntry.dwSize = sizeof(PROCESSENTRY32);
    if (Process32First(hSnapShot, &procEntry)) {
        do {
            HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, procEntry.th32ProcessID);
            if (hProcess != NULL) {
                std::wstring wFilename = ConvertToWideString(filename);
                DWORD dwRet = GetModuleFileNameEx(hProcess, NULL, (LPWSTR)wFilename.c_str(), MAX_PATH);
                if (dwRet > 0 && wFilename == std::wstring(procEntry.szExeFile)) {
                    cout << "Tien trinh '" << procEntry.szExeFile << "' đang su dung tep '" << filename << "'." << endl;
                    TerminateProcess(hProcess, 1);
                    cout << "Da ket thuc tien trinh '" << procEntry.szExeFile << "'." << endl;
                }
                CloseHandle(hProcess);
            }
        } while (Process32Next(hSnapShot, &procEntry));
    }
    CloseHandle(hSnapShot);
}

void DeleteFileWindows(const string& filename) {
    wstring wFilename = ConvertToWideString(filename);

    if (DeleteFileW(wFilename.c_str())) {
        cout << "Tep '" << filename << "' da duoc xoa." << endl;
    }
    else {
        DWORD errorCode = GetLastError();
        cerr << "Khong the xoa tep '" << filename << "'." << endl;
        cerr << "Chi tiet loi khi xoa tep: " << errorCode << endl;

        if (errorCode == ERROR_SHARING_VIOLATION) {
            cout << "Tep dang su dung." << endl;
            TerminateProcessesUsingFile(filename);


            if (DeleteFileW(wFilename.c_str())) {
                cout << "File '" << filename << "' da duoc xoa." << endl;
            }
            else {
                cerr << "Khong the xoa tep '" << endl;
                cerr << "Chi tiet loi: " << GetLastError() << endl;
            }
        }
    }
}





// Hàm đổi tên tệp
void RenameFile(const string& oldName, const string& newName) {
    try {
        fs::rename(oldName, newName);
        clearScreen();
        GotoXY(45, 15);
        cout << "Da doi ten file tu " << oldName << " thanh " << newName << endl;
    }
    catch (const fs::filesystem_error& e) {
        cout << "Loi khi đoi ten tep: " << e.what() << endl;
    }
}


void SaveGame() {
    // L
    GotoXY(21, 2);
    cout << char(220) << char(219) << char(223) << char(223) << char(223) << char(219) << char(220);
    GotoXY(21, 3);
    cout << char(223) << char(219) << char(220) << char(220) << char(220) << char(220);
    GotoXY(26, 4);
    cout << char(223) << char(219);
    GotoXY(21, 5);
    cout << char(223) << char(219) << char(220) << char(220) << char(220) << char(219) << char(223);
    // A
    GotoXY(30, 2);
    cout << char(220) << char(219) << char(223) << char(219) << char(220);
    GotoXY(29, 3);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    GotoXY(29, 4);
    cout << char(219) << char(219) << char(254) << char(254) << char(254) << char(219) << char(219);
    GotoXY(29, 5);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    // V
    GotoXY(38, 2);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    GotoXY(38, 3);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    GotoXY(38, 4);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    GotoXY(39, 5);
    cout << char(223) << char(219) << char(220) << char(219) << char(223);
    //E
    GotoXY(47, 2);
    cout << char(219) << char(219) << char(223) << char(223) << char(223) << char(223);
    GotoXY(47, 3);
    cout << char(219) << char(219) << char(220) << char(220);
    GotoXY(47, 4);
    cout << char(219) << char(219) << char(223) << char(223);
    GotoXY(47, 5);
    cout << char(219) << char(219) << char(220) << char(220) << char(220) << char(220);

    //G
    GotoXY(65, 2);
    cout << char(220) << char(219) << char(223) << char(223) << char(223) << char(219) << char(220);
    GotoXY(65, 3);
    cout << char(219) << char(219) << "   " << char(223) << char(223);
    GotoXY(65, 4);
    cout << char(219) << char(219) << " " << char(223) << char(223) << char(219) << char(219);
    GotoXY(65, 5);
    cout << char(223) << char(219) << char(220) << char(220) << char(220) << char(219) << char(223);
    //A
    GotoXY(75, 2);
    cout << char(220) << char(219) << char(223) << char(219) << char(220);
    GotoXY(74, 3);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    GotoXY(74, 4);
    cout << char(219) << char(219) << char(254) << char(254) << char(254) << char(219) << char(219);
    GotoXY(74, 5);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    // M
    GotoXY(83, 2);
    cout << char(219) << char(219) << char(219) << char(220) << char(219) << char(219) << char(219);
    GotoXY(83, 3);
    cout << char(219) << char(219) << char(223) << char(219) << char(223) << char(219) << char(219);
    GotoXY(83, 4);
    cout << char(219) << char(219) << " " << char(223) << " " << char(219) << char(219);
    GotoXY(83, 5);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    //E
    GotoXY(92, 2);
    cout << char(219) << char(219) << char(223) << char(223) << char(223) << char(223);
    GotoXY(92, 3);
    cout << char(219) << char(219) << char(220) << char(220);
    GotoXY(92, 4);
    cout << char(219) << char(219) << char(223) << char(223);
    GotoXY(92, 5);
    cout << char(219) << char(219) << char(220) << char(220) << char(220) << char(220);
    // pkm
    GotoXY(40, 13);
    cout << char(220) << char(223) << char(223) << char(223) << char(223) << char(223) << char(220) << char(220);
    GotoXY(39, 14);
    cout << char(219) << "      " << char(220) << char(220) << char(219) << char(220) << char(220) << char(220) << char(223) << char(223) << char(223) << char(220) << "   " << char(219) << char(223) << char(220);
    GotoXY(38, 15);
    cout << char(219) << " " << char(220) << char(223) << char(220) << char(220) << char(223) << char(223) << "   " << char(219) << "   " << char(220) << char(219) << char(223) << char(220) << "  " << char(223) << char(220) << char(223) << char(220);
    GotoXY(37, 16);
    cout << char(219) << " " << char(220) << char(223) << char(223) << "     " << char(220) << char(219) << char(220) << " " << char(220) << char(223) << " " << char(223) << char(220) << " " << char(223) << char(220) << char(220) << char(219) << char(220) << char(223) << char(220);
    GotoXY(37, 17);
    cout << char(220) << char(223) << "      " << char(220) << char(223) << char(219) << "  " << char(223) << char(223) << char(220) << char(220) << char(223) << char(223) << char(223) << "  " << char(223) << "   " << char(223) << char(220);
    GotoXY(37, 18);
    cout << char(220) << char(223) << char(223) << char(223) << char(223) << char(220) << char(220) << "           " << char(220) << char(220) << "  " << char(220) << "    " << char(219);
    GotoXY(37, 19);
    cout << char(223) << char(219) << "  " << char(219) << "   " << char(219) << " " << char(223) << char(220) << char(223) << char(220) << "  " << char(220) << char(223) << " " << char(223) << char(220) << "  " << char(219) << char(220) << "   " << char(223) << char(220);
    GotoXY(39, 20);
    cout << char(223) << char(219) << "     " << char(223) << char(220) << "   " << char(219) << char(223) << " " << char(219) << "   " << char(223) << char(223) << char(220) << char(220) << "   " << char(220) << char(223);
    GotoXY(40, 21);
    cout << char(223) << char(220) << "    " << char(223) << char(220) << char(223) << char(223) << char(223) << char(220) << char(220) << char(223) << char(220) << "       " << char(223) << char(223) << char(223);
    GotoXY(41, 22);
    cout << char(223) << char(220) << "   " << char(220) << char(219) << char(220) << char(223) << char(223) << char(223) << char(223) << char(223) << char(223);
    GotoXY(42, 23);
    cout << char(223) << char(220) << char(220) << char(220) << char(220) << char(223);

    //red
    setColor(4);
    GotoXY(41, 13);
    cout << char(220) << char(220) << char(220) << char(220) << char(220);
    GotoXY(40, 14);
    cout << char(223) << " " << char(220) << char(219) << char(219) << char(219) << char(223) << char(223);
    GotoXY(42, 15);
    cout << char(223) << char(223);

    //yellow
    setColor(14);
    GotoXY(40, 14);
    cout << char(220) << char(219) << char(223);
    GotoXY(48, 21);
    cout << char(220) << char(220);

    //blue
    setColor(9);
    GotoXY(46, 15);
    cout << char(220) << char(220);
    GotoXY(42, 16);
    cout << char(220) << char(220) << char(219) << char(219) << char(219) << char(223);
    GotoXY(39, 17);
    cout << char(220) << char(219) << char(219) << char(219) << char(219) << char(219) << char(223) << char(220);
    GotoXY(42, 18);
    cout << char(223) << char(223) << char(219) << char(219) << char(219);

    //orange
    setColor(6);
    GotoXY(52, 14);
    cout << char(220) << char(220) << char(220);
    GotoXY(60, 14);
    cout << char(220);
    GotoXY(39, 15);
    cout << char(219) << char(223) << char(220) << "  " << char(220) << char(220) << char(223) << char(223) << char(219) << " " << char(219) << char(219) << char(219) << char(223) << " " << char(220);
    GotoXY(60, 15);
    cout << char(223) << char(220);
    GotoXY(38, 16);
    cout << char(219) << char(223) << char(220) << char(220) << char(223) << char(223);
    GotoXY(49, 16);
    cout << char(223) << char(219) << char(223);
    GotoXY(55, 16);
    cout << char(223) << char(219) << char(220);
    GotoXY(61, 16);
    cout << char(223) << char(220);
    GotoXY(38, 17);
    cout << char(220) << char(223);
    GotoXY(48, 17);
    cout << char(219) << char(219) << char(220) << char(220);
    GotoXY(54, 17);
    cout << char(220) << char(220) << char(220) << char(219) << char(219) << char(220) << char(219) << char(219) << char(219) << char(220);
    GotoXY(38, 18);
    cout << char(220) << char(220) << char(220) << char(220);
    GotoXY(47, 18);
    cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(223) << char(223) << char(219) << char(219) << char(223) << char(219) << char(219) << char(219) << char(219);
    GotoXY(50, 19);
    cout << char(223) << char(219) << char(219) << char(223);
    GotoXY(39, 19);
    cout << char(219) << char(219) << " " << char(219) << char(219) << char(219) << " " << char(219) << char(220) << char(223);
    GotoXY(57, 19);
    cout << char(223) << char(219);
    GotoXY(61, 19);
    cout << char(223) << char(219) << char(219) << char(219) << char(220);
    GotoXY(41, 20);
    cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(220) << char(223) << char(219) << char(219) << char(223);
    GotoXY(52, 20);
    cout << char(220) << char(219);
    GotoXY(60, 20);
    cout << char(223) << char(223) << char(219) << char(219) << char(219) << char(223);
    GotoXY(41, 21);
    cout << char(223) << char(219) << char(219) << char(219) << char(219) << char(220) << char(223);
    GotoXY(50, 21);
    cout << char(220) << char(223) << char(223) << char(220);
    GotoXY(42, 22);
    cout << char(223) << char(219) << char(219) << char(219) << char(223);
    GotoXY(48, 22);
    cout << char(223);
    GotoXY(43, 23);
    cout << char(223);
    GotoXY(45, 23);
    cout << char(223);

    //white
    setColor(15);
    GotoXY(49, 19);
    cout << char(220);
    GotoXY(59, 19);
    cout << char(219);
    GotoXY(50, 20);
    cout << char(219);
    GotoXY(44, 23);
    cout << char(223);
    GotoXY(46, 23);
    cout << char(223);

    int saveCount = 0;
    string filename;
    while (saveCount <= 10) {
        box(35, 8, 50, 5, "Nhap ten file de luu game:");
        GotoXY(65, 9);
        cin >> filename;
        ofstream file(filename);
        if (file.is_open()) {
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    file << _A[i][j].c << " ";
                }
                file << "\n";
            }
            file << (_TURN ? 1 : 0) << "\n";
            file.close();
            saveCount++;
            GotoXY(65, 20);
            cout << "Game da duoc luu" << endl;
            clearScreen();
            menuScreen();
            break;
        }
        else {
            cerr << "Khong the mo file de luu!" << endl;
        }
        break;
    }
    if (saveCount > 10) {
        GotoXY(65, 23);
        cout << "Da luu qua 10 lan" << endl;
        return;
    }

}


// Load game 
void LoadGame() {

    // L
    GotoXY(22, 2);
    cout << char(219) << char(219);
    GotoXY(22, 3);
    cout << char(219) << char(219);
    GotoXY(22, 4);
    cout << char(219) << char(219);
    GotoXY(22, 5);
    cout << char(219) << char(219) << char(220) << char(220) << char(220) << char(220);
    // o
    GotoXY(29, 2);
    cout << char(220) << char(219) << char(223) << char(223) << char(223) << char(219) << char(220);
    GotoXY(29, 3);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    GotoXY(29, 4);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    GotoXY(29, 5);
    cout << char(223) << char(219) << char(220) << char(220) << char(220) << char(219) << char(223);
    // A
    GotoXY(39, 2);
    cout << char(220) << char(219) << char(223) << char(219) << char(220);
    GotoXY(38, 3);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    GotoXY(38, 4);
    cout << char(219) << char(219) << char(254) << char(254) << char(254) << char(219) << char(219);
    GotoXY(38, 5);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    // D
    GotoXY(47, 2);
    cout << char(219) << char(219) << char(223) << char(223) << char(219) << char(220);
    GotoXY(47, 3);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    GotoXY(47, 4);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    GotoXY(47, 5);
    cout << char(219) << char(219) << char(220) << char(220) << char(219) << char(223);
    //G
    GotoXY(65, 2);
    cout << char(220) << char(219) << char(223) << char(223) << char(223) << char(219) << char(220);
    GotoXY(65, 3);
    cout << char(219) << char(219) << "   " << char(223) << char(223);
    GotoXY(65, 4);
    cout << char(219) << char(219) << " " << char(223) << char(223) << char(219) << char(219);
    GotoXY(65, 5);
    cout << char(223) << char(219) << char(220) << char(220) << char(220) << char(219) << char(223);
    //A
    GotoXY(75, 2);
    cout << char(220) << char(219) << char(223) << char(219) << char(220);
    GotoXY(74, 3);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    GotoXY(74, 4);
    cout << char(219) << char(219) << char(254) << char(254) << char(254) << char(219) << char(219);
    GotoXY(74, 5);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    // M
    GotoXY(83, 2);
    cout << char(219) << char(219) << char(219) << char(220) << char(219) << char(219) << char(219);
    GotoXY(83, 3);
    cout << char(219) << char(219) << char(223) << char(219) << char(223) << char(219) << char(219);
    GotoXY(83, 4);
    cout << char(219) << char(219) << " " << char(223) << " " << char(219) << char(219);
    GotoXY(83, 5);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    //E
    GotoXY(92, 2);
    cout << char(219) << char(219) << char(223) << char(223) << char(223) << char(223);
    GotoXY(92, 3);
    cout << char(219) << char(219) << char(220) << char(220);
    GotoXY(92, 4);
    cout << char(219) << char(219) << char(223) << char(223);
    GotoXY(92, 5);
    cout << char(219) << char(219) << char(220) << char(220) << char(220) << char(220);

    int i = 10;
    string directory = ".";
    GotoXY(50, 9);
    cout << "Danh sach cac gane da luu:\n";
    for (const auto& entry : fs::directory_iterator(directory)) {
        if (filesystem::is_regular_file(entry) && entry.path().extension().empty()) {
            GotoXY(55, i);
            cout << entry.path().stem() << endl;
            i++;
        }
    }
    box(40, 20, 45, 5, "Nhap ten file ma ban muon :");
    BOX(1, 1, 15, 3);
    GotoXY(1, 1);
    cout << "Esc:back Menu";

    // hinh 1 
    GotoXY(10, 14);
    cout << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220);
    GotoXY(9, 15);
    cout << char(219) << "      " << char(220) << char(223);
    GotoXY(8, 16);
    cout << char(219) << "     " << char(220) << char(219) << char(220) << char(220) << char(220) << char(220);
    GotoXY(7, 17);
    cout << char(219) << "           " << char(220) << char(223);
    GotoXY(8, 18);
    cout << char(223) << char(223) << char(223) << char(223) << char(220) << "    " << char(220) << char(223);
    GotoXY(11, 19);
    cout << char(220) << char(223) << "  " << char(220) << char(223);
    GotoXY(10, 20);
    cout << char(220) << char(223) << " " << char(220) << char(223);
    GotoXY(11, 21);
    cout << char(223) << char(223);
    // hinh 2 
    GotoXY(95, 13);
    cout << char(220) << char(223) << char(223) << char(223) << char(223) << char(220) << char(220) << char(220) << char(220) << char(223) << char(223) << char(223) << char(223) << char(220);
    GotoXY(93, 14);
    cout << char(220) << char(223) << "              " << char(223) << char(220);
    GotoXY(93, 15);
    cout << char(219) << "                " << char(219);
    GotoXY(93, 16);
    cout << char(219) << "     " << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << "     " << char(219);
    GotoXY(94, 17);
    cout << char(223) << char(220) << char(220) << char(220) << char(223) << "      " << char(223) << char(220) << char(220) << char(220) << char(223);
    GotoXY(96, 15);
    cout << char(223) << char(219) << char(223) << " " << char(223) << "  " << char(223) << " " << char(223) << char(220) << char(223);
    GotoXY(97, 14);
    cout << char(220) << "        " << char(220);
    // hinh 1
    setColor(6);
    GotoXY(10, 15);
    cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(223);
    GotoXY(9, 16);
    cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(223);
    GotoXY(8, 17);
    cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(223) << char(223);
    GotoXY(11, 18);
    cout << char(223) << char(223) << char(219) << char(219) << char(219) << char(219) << char(223);
    GotoXY(12, 19);
    cout << char(220) << char(219) << char(219) << char(223);
    GotoXY(11, 20);
    cout << char(220) << char(219) << char(223);
    string filename;
    char key;
    setColor(117);
    GotoXY(72, 21);

    filename = "";
    while (true) {
        key = _getch();

        if (key == 27) {
            playSound(3, 0);
            clearScreen();
            menuScreen();
        }
        else if (key == '\r') {
            if (!filename.empty()) {
                break;
            }
        }
        else if (key == '\b') {
            if (!filename.empty()) {
                filename.pop_back();
                cout << "\b \b";
            }
        }
        else {
            filename += key;
            cout << key;
        }
    }

    box(20, 25, 20, 5, "Load Game");
    box(52, 25, 20, 5, "Xoa File");
    box(84, 25, 20, 5, "Doi Ten");
    ifstream file(filename);
    int selection = 0;
    while (true) {
        for (int i = 0; i < 3; i++) {
            setColor(i == selection ? 124 : 112);
            switch (i) {
            case 0: box(20, 25, 20, 5, "Load Game"); break;
            case 1: box(52, 25, 20, 5, "Xoa File");; break;
            case 2: box(84, 25, 20, 5, "Doi Ten");; break;
            }
            Sleep(10);
        }

        char ch = _getch();

        if (ch == 27) {
            playSound(3, 0);
            clearScreen();
            menuScreen();
            break;
        }
        playSound(2, 0);
        if (ch == 13) {
            switch (selection) {
            case 0:
                playSound(3, 0);
                clearScreen();
                if (file.is_open()) {
                    ShowBlinkingCursor(true);
                    system("color 70");
                    fixConsoleWindow();
                    ResetData();
                    gameText();
                    DrawBoard(BOARD_SIZE);
                    displayScore(0);
                    moveCount(0);
                    for (int i = 0; i < BOARD_SIZE; i++) {
                        for (int j = 0; j < BOARD_SIZE; j++) {
                            int value;
                            file >> value;
                            if (value == -1) {
                                GotoXY(_A[i][j].x + 1, _A[i][j].y);
                                printf("%c", X());
                                moveCount(-1);
                            }
                            if (value == 1) {
                                GotoXY(_A[i][j].x + 1, _A[i][j].y);
                                printf("%c", O());
                                moveCount(1);
                            }

                        }
                    }
                    int turn;
                    file >> turn;
                    _TURN = (turn == 1);

                    file.close();
                    // Viền X
                    BOX(2, 16, 16, 10);
                    // Viền O
                    BOX(20, 16, 16, 10);
                    GotoXY(_A[0][0].x + 49, _A[0][0].y + 11);
                    if (_TURN == false) {
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
                    bool validEnter = true;
                    while (true) {
                        char command = getInput();
                        if (command) {
                            command = toupper(command);
                            if (command == 27) {
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
                                                break;
                                            }
                                            else {
                                                continueGame();
                                                vienPlayer();
                                                gameText();
                                                GotoXY(_A[0][0].x, _A[0][0].y);
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
                        Sleep(100);
                    }
                }
                else {
                    clearScreen();
                    LoadGame();
                }
                file.close();
                break;
            case 1:
                playSound(3, 0);
                clearScreen();
                file.is_open();
                file.close();
                DeleteFileWindows(filename);
                clearScreen();
                LoadGame();
                break;
            case 2:
                playSound(3, 0);
                clearScreen();
                string filename2;
                box(35, 8, 50, 5, "Nhap ten file ma ban muon doi : ");
                GotoXY(71, 9);
                cin >> filename2;
                file.is_open();
                file.close();
                RenameFile(filename, filename2);
                clearScreen();
                LoadGame();
                break;
            }
        }

        if (ch == 75 or ch == 'a' or ch == 'A') {
            if (selection > 0) {
                selection--;
            }
        }
        else if (ch == 77 or ch == 'd' or ch == 'D') {
            if (selection < 2) {
                selection++;
            }
        }
    }
}
