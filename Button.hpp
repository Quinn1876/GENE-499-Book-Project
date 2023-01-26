#pragma once
#include "Arduino.h"

class Button {
    const int buttonPin;
    public:
        Button(int buttonPin) : buttonPin(buttonPin) {};

        void Setup() {
            pinMode(buttonPin, INPUT);
        }
        bool isPressed() {
            return digitalRead(buttonPin);
        }
};
