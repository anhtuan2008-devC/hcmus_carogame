#pragma once
#ifndef PVP_MODE_H
#define PVP_MODE_H
#include <cstdlib>
#include <ctime>
#include "Chessboard.h"
#include "LoadGame.h"

void gameBackground();
void vienPlayer();
void turnPlayer();
int ProcessFinish(int pWhoWin);
int AskContinue();
void gameText();
int PlayWithPlayer();

#endif
