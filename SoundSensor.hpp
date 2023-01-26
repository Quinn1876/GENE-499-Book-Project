#pragma once
#include "Arduino.h"
#define HISTORY_LEN 2

class SoundSensor {
    const int soundPin;
    int history[HISTORY_LEN] = {0};
    int index = 0;
    bool isHigh = false;

public:
    SoundSensor(const int &soundPin)
        : soundPin(soundPin) {}

    void ReadPin(const bool logToSerial);
    void Setup();
};
