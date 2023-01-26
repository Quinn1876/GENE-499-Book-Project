// demo of Starter Kit V2.0 - Grove Sound Sensor
// when sound larger than a certain value, led will on
#include "SoundSensor.hpp"
#include "Button.hpp"
#include "Potentiometer.hpp"

/// Pin Definitions
const int pinSound = A0;               // pin of Sound Sensor
const int pinPotentiometer = A1;
const int pinLed   = 7;                // pin of LED
const int pinButton = 2;

// drivers

Button pushButton(pinButton);
SoundSensor soundSensor(pinSound);
Potentiometer potentiometer(pinPotentiometer, 100, 0);

// Interrupt Globals
volatile int buttonPressCount_g = 0;

void setup()
{
    pinMode(pinLed, OUTPUT);            //set the LED on Digital 12 as an OUTPUT
    Serial.begin(9600);
    soundSensor.Setup();
    pushButton.Setup();
    potentiometer.Setup();
    attachInterrupt(digitalPinToInterrupt(pinButton), onButtonPress, RISING);
}

void loop()
{
  const int pressSinceLastCheck = buttonPressCount_g;
  buttonPressCount_g = 0;
  Serial.println(pressSinceLastCheck);

  delay(400);
}

void onButtonPress() {
  buttonPressCount_g++;
}
