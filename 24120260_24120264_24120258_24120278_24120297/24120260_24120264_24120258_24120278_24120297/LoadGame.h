#pragma once

#include "Console.h"
#include "Chessboard.h"
#include "PvPMode.h"

void loadBox();
void deleteBox();
void renameBox();
void TerminateProcessesUsingFile(const string& filename);
wstring ConvertToWideString(const string& str);
void DeleteFileWindows(const string& filename);
void RenameFile(const string& oldName, const string& newName);
void SaveGame();
void LoadGame();
