// demo of Starter Kit V2.0 - Grove Sound Sensor
// when sound larger than a certain value, led will on
#include "SoundSensor.hpp"
const int pinSound = A0;               // pin of Sound Sensor
const int pinLed   = 7;                // pin of LED

SoundSensor soundSensor(pinSound);

void setup()
{
    pinMode(pinLed, OUTPUT);            //set the LED on Digital 12 as an OUTPUT
    Serial.begin(9600);
    soundSensor.Setup();
}

void loop()
{
  soundSensor.ReadPin(true);

  delay(200);
}
