/*
 * Inspired by MotorKnob Example and 
 * https://www.brainy-bits.com/post/control-a-stepper-motor-using-an-arduino-and-a-rotary-encoder
 * http://www.arduino.cc/en/Reference/Stepper
 * This example code is in the public domain. (For Motor Knob)
 */

#include <Stepper.h>

int ClickPin = 2;
int DTPin = 3;
int SWPin = 4;

int MotorPos = 0;
int PrevPos = 0;// the previous reading from the analog input
int StepsNeeded;

volatile boolean TurnDetected; // volitile is needed for interrupts
volatile boolean RotateDirection;

// change this to the number of steps on your motor
#define STEPS 2048

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 8, 10, 9, 11);

// interrupt runs if the button on the knob gets clicked
void InterruptClick () { // on click it will go to origin
  delay(15); // debounce
  if (digitalRead(ClickPin)) {
    RotateDirection = digitalRead(DTPin);
  } else {
    RotateDirection = !digitalRead(DTPin);
  }
  TurnDetected = true;

  
}

void setup() {
  
  pinMode(ClickPin,INPUT);
  pinMode(DTPin,INPUT);
  pinMode(SWPin,INPUT);
  digitalWrite(SWPin,HIGH);
  attachInterrupt(0,InterruptClick,FALLING);

}

void loop() {
  stepper.setSpeed(10);
  if(!(digitalRead(SWPin))){
    if (MotorPos == 0) {
      //check to see if button was pressed and motor now at pos 0 again
    } else {
      stepper.step(-(MotorPos*50));
      MotorPos = 0; // sets position to 0
    }
  }

  if(TurnDetected){
    //PrevPos = MotorPos;
    if(RotateDirection){
      MotorPos--;
    } else{
      MotorPos++;
    }
    TurnDetected = false;

    //sees what direction to move motor
    if(PrevPos+1 == MotorPos){ //CW
      PrevPos = MotorPos;
      StepsNeeded=50;
      stepper.step(StepsNeeded);
    }

    if(MotorPos+1 == PrevPos){ //CCW
      PrevPos = MotorPos;
      StepsNeeded=-50;
      stepper.step(StepsNeeded);
    }
    
  }


  
}
