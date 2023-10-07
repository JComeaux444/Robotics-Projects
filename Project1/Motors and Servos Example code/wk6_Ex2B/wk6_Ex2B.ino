#include <Stepper.h>
#include <stdio.h>
#include<stdlib.h>

const int stepsPerRevolution = 1075;  // change this to fit the number of steps per revolution
// for your motor


const long interval = 1000;
unsigned long previousMillis = 0;
unsigned long currentMillis;
int stepperSpeedInterval = 21;


// initialize the stepper library on pins 8 through 11:
Stepper stepperOne(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // set the speed at 20 rpm:
  stepperOne.setSpeed(20);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  
  // going fast in one direction

  currentMillis = millis();

  stepperOne.step(stepsPerRevolution);
  //stepperOne.step(stepsPerRevolution);
  //delay(500);

  if(currentMillis - previousMillis >= 50){
    stepperOne.step(stepsPerRevolution);
    stepperOne.setSpeed(stepperSpeedInterval);
    stepperSpeedInterval++;
    Serial.println(stepperSpeedInterval);
    previousMillis = currentMillis;
  }
  
}
