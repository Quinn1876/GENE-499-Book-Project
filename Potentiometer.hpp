#pragma once

class Potentiometer {
    const int max_;
    const int min_;
    const int pin_;
public:
    Potentiometer(int pin_, int max_, int min_) : max_(max_), min_(min_), pin_(pin_) {}

    int Setup() {}

    int GetReading() {
        int raw = analogRead(pin_);
        return map(raw, 0, 1023, min_, max_);
    }
};
