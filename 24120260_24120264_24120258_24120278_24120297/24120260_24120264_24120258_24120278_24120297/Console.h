#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>
#include <fstream> 
#include <limits> 
#include <filesystem>
// sua nay kia
using namespace std;
namespace fs = filesystem;

void clearScreen();
void GotoXY(int column, int line);
void setColor(int color);
void ShowBlinkingCursor(bool isVisible);
void fixConsoleWindow();
void SetWindowSize(SHORT width, SHORT height);
void SetScreenBufferSize(SHORT width, SHORT height);
void DisableSelection();
void ShowScrollbar(BOOL Show);
void DisableScrollbar();
void BOX(int x, int y, int w, int h);
void printAsciiArt(const string&, int , int );
void SSetColor(int mauBg, int mauchu);
void box(int x, int y, int w, int h, string nd);

#define Black 112 
#define Blue 113
#define Green 114 
#define PrettyBlue 115
#define Red 116
#define Pink 117
#define Yellow 118
#define White 119
#define Gray 120
#define Blue2 121
#define Green2 122 
#define PrettyBlue2 123
#define Red2 124
#define Pink2 125
#define Yellow2 126
#define White2 127






