#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>

#define SERIAL_BAUD 115200

Servo ESC1;
Servo Steering;

int Speed = 0;
int SteeringAngle = 0;

void receiveEvent(int CommandWord)
{
  while(1 < Wire.available()){
    SteeringAngle = Wire.read();
  }
  Speed = Wire.read();
  ESC1.write(Speed);
  Steering.write(SteeringAngle);  
}

void setup() {
  // put your setup code here, to run once:
  ESC1.attach(9);
  Steering.attach(8);
  Wire.begin(7);
  Wire.onReceive(receiveEvent);
}

void loop() {
  // put your main code here, to run repeatedly:
}