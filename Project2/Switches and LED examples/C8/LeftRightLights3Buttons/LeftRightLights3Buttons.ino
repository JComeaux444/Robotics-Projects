#include <stdio.h>
#include<stdlib.h>

const int button = 12;
const int button2 = 11;
const int button3 = 7;
int redPin = 3;
int yellowPin = 4;
int greenPin = 5;
int pin6 = 9;
int pin7 = 10;

int speedAndD = 0;
int pos = 3;

int bounceTime = 50;
int holdTime = 250;
int doubleTime = 500;

int lastReading = LOW;
int hold = 0;
int single = 0;
int LEDstate = 0;

unsigned long onTime = 0;
unsigned long lastSwitchTime = 0;

const long interval = 1000;
unsigned long previousMillis = 0;
unsigned long currentMillis;

//bool runningStopLight = false;
bool runningArcadeL = false;

bool greenL = false;
bool yellowL = false;
bool redL = false;
bool walkL = false;

bool buttonStateUp2 = true; //for second button right
bool buttonStateUp3 = true; //for third button left

void setup() {
  pinMode(button, INPUT);
  for(int i = 0; i <= 13; i++){
        pinMode(i, INPUT);
  }
    
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin7, OUTPUT);
  //digitalWrite(led, LOW);
  Serial.begin(9600);
}


void loop() {


  currentMillis = millis();
  int reading = digitalRead(button);

//first pressed
  if (reading == HIGH && lastReading == LOW) {
    onTime = millis();
  }

//held
  if (reading == HIGH && lastReading == HIGH) {
    if ((millis() - onTime) > holdTime) {
      //setup();  
      hold = 1;
    }
  }

//released
  if (reading == LOW && lastReading == HIGH) {
    if (((millis() - onTime) > bounceTime) && hold != 1) {
      onRelease();
    }
    if (hold == 1) {
      Serial.println("held"); //!!!!! HELD HERE  HELD HERE HELD HERE HELD HERE
      //digitalWrite(led, LEDstate);
      hold = 0;
      //runningDiscoParty = false;
      //runningStopLight = false;
      runningArcadeL = false;
      digitalWrite(greenPin, LOW);
      digitalWrite(yellowPin, LOW);
      digitalWrite(redPin, LOW);
      digitalWrite(pin6, LOW);
      digitalWrite(pin7, LOW);
      //setup();
    }   
  }
  lastReading = reading;

  if (single == 1 && (millis() - lastSwitchTime) > doubleTime) {
    Serial.println("single press");
    //stopLight();
    previousMillis = currentMillis;
    speedAndD = 0;
    pos = 3;
    runningArcadeL = true;
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, HIGH);
    digitalWrite(redPin, LOW);
    digitalWrite(pin6, LOW);
    digitalWrite(pin7, LOW);
    greenL = false;
    yellowL = false;
    redL = false;
    walkL = false;  
    single = 0;
  }



//button 2 / right button
  if (digitalRead(button2) == LOW && buttonStateUp2){
    //Serial.println("Button2 is up"); 
    buttonStateUp2 = false; 
  }
  if (digitalRead(button2) == HIGH && buttonStateUp2 == false){
    //Serial.println("Button2 is down");
    speedAndD += 1;  
    buttonStateUp2 = true;
  }


//button 3 / left button
  if (digitalRead(button3) == LOW && buttonStateUp3){
    //Serial.println("Button3 is up"); 
    buttonStateUp3 = false; 
  }
  if (digitalRead(button3) == HIGH && buttonStateUp3 == false){
    //Serial.println("Button3 is down"); 
    speedAndD -= 1;   
    buttonStateUp3 = true;
  }





//Running the lights here
  if(runningArcadeL){
    Serial.println("Arcade is running!");
      //runningDiscoParty = false;
      //runningStopLight = false;
    
    //When going right
    if(currentMillis - previousMillis >= (5000/(speedAndD+1)) && speedAndD > 0){
      pos = pos+1;
      
      if(pos > 5 || pos < 0 ){
        pos = 5;
      }
      
      previousMillis = currentMillis;

      digitalWrite(greenPin, LOW);
      digitalWrite(yellowPin, LOW);
      digitalWrite(redPin, LOW);
      digitalWrite(pin6, LOW);
      digitalWrite(pin7, LOW);
      
      if(pos == 1){
        digitalWrite(pin7, HIGH);
      }
      if(pos == 2){
        digitalWrite(greenPin, HIGH);
      }
      if(pos == 3){
        digitalWrite(yellowPin, HIGH);
      }
      if(pos == 4){
        digitalWrite(pin6, HIGH);
      }
      if(pos == 5){
        digitalWrite(redPin, HIGH);
        pos = 0;
      }
    }
   
    //When going LEFT
    if(currentMillis - previousMillis >= (5000/(abs(speedAndD)+1)) && speedAndD < 0){
      pos = pos-1;

      if(pos > 5 || pos < 0 ){
        pos = 5;
      }
      
      previousMillis = currentMillis;

      digitalWrite(greenPin, LOW);
      digitalWrite(yellowPin, LOW);
      digitalWrite(redPin, LOW);
      digitalWrite(pin6, LOW);
      digitalWrite(pin7, LOW);
      
      if(pos == 1){
        digitalWrite(pin7, HIGH);
        pos = 6;
      }
      if(pos == 2){
        digitalWrite(greenPin, HIGH);
      }
      if(pos == 3){
        digitalWrite(yellowPin, HIGH);
      }
      if(pos == 4){
        digitalWrite(pin6, HIGH);
      }
      if(pos == 5){
        digitalWrite(redPin, HIGH);
      } 
      
    }
  }


Serial.println("LOOP is running!");

}


void onRelease() {

  if ((millis() - lastSwitchTime) >= doubleTime) {
    single = 1;
    lastSwitchTime = millis();
    return;
  }  

  if ((millis() - lastSwitchTime) < doubleTime) {
    Serial.println("double press");
    single = 0;
    lastSwitchTime = millis();
  }  

}
