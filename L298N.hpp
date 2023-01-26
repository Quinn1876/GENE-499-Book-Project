#pragma once

class L298N {
public:
    enum Direction {
        Forward,
        Reverse,
    };
private:
    const int enablePin;
    const int forwardPin;
    const int reversePin;

    int currentSpeed;
    Direction currentDirection;
public:
    L298N(int enable, int forward, int reverse) : enablePin(enable), forwardPin(forward), reversePin(reverse) {}

    void Setup() {
        pinMode(enablePin, OUTPUT);
        pinMode(forwardPin, OUTPUT);
        pinMode(reversePin, OUTPUT);
    }

    void SetDirection(Direction dir) {
        digitalWrite(forwardPin, LOW);
        digitalWrite(reversePin, LOW);
        switch (dir) {
        case Forward:
            digitalWrite(forwardPin, HIGH);
            break;
        case Reverse:
            digitalWrite(reversePin, HIGH);
            break;
        }
    }

    void SetSpeed(int speed) {
        if (speed > 100)
            speed = 100;
        else if (speed < 0)
            speed = 0;

        int writeVal = map(speed, 0, 100, 0, 255);
        analogWrite(enablePin, writeVal);
        currentSpeed = speed;
    }

    int GetSpeed() const { return currentSpeed; }
    Direction GetDirection() const { return currentDirection; }
};
