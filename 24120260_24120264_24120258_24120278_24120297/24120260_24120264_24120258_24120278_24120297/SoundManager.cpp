#include "SoundManager.h"

// Global array to track loaded audio
bool audio_loaded[sobai] = { 0 };

// Current volume levels
short backgroundVolume = 400; // Âm lượng cho âm thanh nền
short effectVolume = 400;     // Âm lượng cho âm thanh trò chơi

// Function to get song path by number
wstring getSongbyNum(short song) {
    switch (song) {
    case 1: return L"./Sounds/level-ii-short-236120.mp3"; // Âm thanh nền
    case 2: return L"./Sounds/move.mp3";
    case 3: return L"./Sounds/chose.mp3";
    case 4: return L"./Sounds/Win.mp3";
    default: return L"";
    }
}

// Background volume functions
short getBackgroundVolume() {
    return backgroundVolume;
}

void setBackgroundVolume(short value) {
    value = (value > 1000) ? 1000 : (value < 0) ? 0 : value;
    backgroundVolume = value;

    // Update volume for background music (case 1)
    if (audio_loaded[1]) {
        wstring name = getSongbyNum(1);
        mciSendString((L"setaudio " + name + L" volume to " + to_wstring(backgroundVolume)).c_str(), NULL, 0, NULL);
    }
}

// Effect volume functions
short getEffectVolume() {
    return effectVolume;
}

void setEffectVolume(short value) {
    value = (value > 1000) ? 1000 : (value < 0) ? 0 : value;
    effectVolume = value;

    // Update volume for game effects (case 2-6)
    for (int i = 2; i <= 6; i++) {
        if (audio_loaded[i]) {
            wstring name = getSongbyNum(i);
            mciSendString((L"setaudio " + name + L" volume to " + to_wstring(effectVolume)).c_str(), NULL, 0, NULL);
        }
    }
}

// Function to open a sound
void openSound(short song) {
    if (song >= 0 && song < sobai && !audio_loaded[song]) {
        wstring songName = getSongbyNum(song);
        wstring command = L"open " + songName + L" type mpegvideo alias " + songName;
        mciSendString(command.c_str(), NULL, 0, NULL);
        audio_loaded[song] = true;
    }
}

// Pause sound
void pauseSound(short song) {
    if (song >= 0 && song < sobai && audio_loaded[song]) {
        wstring songName = getSongbyNum(song);
        mciSendString((L"pause " + songName).c_str(), NULL, 0, NULL);
    }
}

// Resume sound
void resumeSound(short song) {
    if (song >= 0 && song < sobai && audio_loaded[song]) {
        wstring songName = getSongbyNum(song);
        mciSendString((L"resume " + songName).c_str(), NULL, 0, NULL);
    }
}

// Stop and close sound
void stopSound(short song) {
    if (song >= 0 && song < sobai) {
        wstring songName = getSongbyNum(song);
        mciSendString((L"stop " + songName).c_str(), NULL, 0, NULL);
        mciSendString((L"close " + songName).c_str(), NULL, 0, NULL);
        audio_loaded[song] = false;
    }
}

// Restart sound
void restartSound(short song) {
    if (song >= 0 && song < sobai && audio_loaded[song]) {
        wstring songName = getSongbyNum(song);
        mciSendString((L"seek " + songName + L" to 0").c_str(), NULL, 0, NULL);
    }
}

// Play sound with repeat option
void playSound(short song, bool repeat) {
    if (song >= 0 && song < sobai && song != 0) {
        if (!audio_loaded[song]) {
            openSound(song);
        }

        restartSound(song);
        wstring songName = getSongbyNum(song);
        wstring command = L"play " + songName + (repeat ? L" repeat" : L"");

        mciSendString(command.c_str(), NULL, 0, NULL);

        // Set the appropriate volume based on sound type
        if (song == 1) { // Âm thanh nền
            setBackgroundVolume(backgroundVolume);
        }
        else { // Âm thanh trò chơi
            setEffectVolume(effectVolume);
        }
    }
}
