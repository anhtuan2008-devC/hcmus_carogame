#pragma once
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
#define sobai 9
#pragma comment(lib, "Winmm.lib")
wstring getSongbyNum(short song);
short getBackgroundVolume();
void setBackgroundVolume(short value);
short getEffectVolume();
void setEffectVolume(short value);
void openSound(short song);
void pauseSound(short song);
void stopSound(short song);
void resumeSound(short song);
void restartSound(short song);
void playSound(short song, bool repeat);