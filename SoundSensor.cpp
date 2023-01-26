#include "SoundSensor.hpp"

void SoundSensor::ReadPin(const bool logToSerial) {
    int sensorValue = analogRead(soundPin);   //read the sensorValue on Analog 0
    history[index] = sensorValue;
    ++index %= HISTORY_LEN;

    int runningAvg = 0;
    for (int i = 0; i < HISTORY_LEN; i++) {
      runningAvg += history[i];
    }

    int avg = runningAvg / HISTORY_LEN;

    if (avg >  120) {
      isHigh = true;
    } else if (avg < 100) {
      isHigh = false;
    }

    if (logToSerial) {
        Serial.println(avg);
    }
}

void SoundSensor::Setup() {
    pinMode(soundPin, INPUT);
}

bool SoundSensor::IsHigh() {
  return isHigh;
}
