// demo of Starter Kit V2.0 - Grove Sound Sensor
// when sound larger than a certain value, led will on
#include "SoundSensor.hpp"
#include "Button.hpp"
#include "Potentiometer.hpp"
#include "L298N.hpp"

// Methods
void onButtonPress();
void RampUp();
void RampDown();
void SenseSound();

enum States {
  RampingUp,
  DrivingHigh,
  RampingDown,
  DrivingLow
};

/// Pin Definitions
const int pinSound          = A0;               // pin of Sound Sensor
const int pinPotentiometer  = A1;
const int pinButton         = 2;
const int pinMotorIn1       = 7;
const int pinMotorIn2       = 8;
const int pinMotorEn        = 9;

// drivers

Button pushButton(pinButton);
SoundSensor soundSensor(pinSound);
Potentiometer potentiometer(pinPotentiometer, 100, 0);
L298N motor(pinMotorEn, pinMotorIn1, pinMotorIn2);

// Interrupt Globals
volatile int buttonPressCount_g = 0;

// Constants
#define MOTOR_SPEED_LOW 0
#define MOTOR_SPEED_HIGH 25

void setup()
{
    Serial.begin(9600);
    soundSensor.Setup();
    pushButton.Setup();
    potentiometer.Setup();
    motor.Setup();
    attachInterrupt(digitalPinToInterrupt(pinButton), onButtonPress, RISING);

  // If this is missing, the motor won't move
  motor.SetDirection(L298N::Forward);
}

void loop()
{
  static States state = DrivingLow;

  soundSensor.ReadPin();

  switch (state) {
  case DrivingHigh: {
    if (!soundSensor.IsHigh()) {
      state = RampingDown;
    }
    break;
  }
  case DrivingLow: {
    if (!soundSensor.IsHigh()) {
      state = RampingUp;
    }
    break;
  }
  case RampingUp: {
    if (motor.GetSpeed() < MOTOR_SPEED_HIGH) {
      motor.SetSpeed(motor.GetSpeed() + 1);
    } else {
      state = DrivingHigh;
    }
    break;
  }
  case RampingDown: {
    if (motor.GetSpeed() > MOTOR_SPEED_LOW) {
      motor.SetSpeed(motor.GetSpeed() - 1);
    } else {
      state = DrivingLow;
    }
    break;
  }
  }

  delay(200);
}

void onButtonPress() {
  buttonPressCount_g++;
}


void SenseSound() {
  soundSensor.ReadPin();


}
