#pragma once
#include <cstdlib>
#include <ctime>
#include "Chessboard.h"

void gameBotText();
int countConsecutive(int row, int col, int dx, int dy, int player);
bool isThreat(int row, int col, int player);
int evaluateMove(int row, int col, int player);
bool checkWin(int row, int col, int player);
void botMove();
void PlayWithBot();
