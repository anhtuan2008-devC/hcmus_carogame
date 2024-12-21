#pragma once

#include "Console.h"
#include "Chessboard.h"
#include "PvPMode.h"
#include "sstream"
#include <tlhelp32.h>
#include <psapi.h>

void loadBox();
void deleteBox();
void renameBox();
bool fileExists(const string& filename);
void TerminateProcessesUsingFile(const string& filename);
wstring ConvertToWideString(const string& str);
void DeleteFileWindows(const string& filename);
void RenameFile(const string& oldName, const string& newName);
void SaveGame();
void LoadGame();
