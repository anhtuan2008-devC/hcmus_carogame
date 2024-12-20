#pragma once
#include <cstdlib>
#include <ctime>
#include "Chessboard.h"

void BotMove(int mode = 2);
int countConsecutive(int row, int col, int dx, int dy, int player);
bool isThreat(int row, int col, int player);
void easyMode();
int evaluateMove(int row, int col, int player);
bool checkWin(int row, int col, int player);
void hardMode();
void PlayWithBot();
void PlayWithHardBot();