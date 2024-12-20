#pragma once
#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include "Console.h"
#include "Menu.h"
// sua cai j do
char X();
char O();
void ResetData();
void DrawBoard(int pSize);
void StartGame();
void GabageCollect();  
void ExitGame();
int CheckWin(int player);
int TestBoard();
int CheckBoard(int pX, int pY);
void MoveRight();
void MoveLeft();
void MoveDown();
void MoveUp();
char getInput();
void markWinning(int startX, int startY, int dirX, int dirY, int player);
void displayScore(int player);
void moveCount(int player);
void continueGame();

// Hằng số
#define BOARD_SIZE 12 // Kích thước ma trận bàn cờ
#define LEFT 35 // Tọa độ trái màn hình bàn cờ
#define TOP 5 // Tọa độ trên màn hình bàn cờ

// Khai báo kiểu dữ liệu
struct _POINT {
    int x, y, c; // x: tọa độ dòng, y: tọa độ cột, c: đánh dấu
};

extern _POINT _A[BOARD_SIZE][BOARD_SIZE]; // Bàn cờ
extern bool _TURN;
extern int _X, _Y;

#endif CHESSBOARD_H