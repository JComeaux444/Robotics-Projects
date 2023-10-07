const int button = 12;
int redPin = 3;
int yellowPin = 4;
int greenPin = 5;
int pin6 = 9;
int pin7 = 10;

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

bool runningStopLight = false;
bool runningDiscoParty = false;

bool greenL = false;
bool yellowL = false;
bool redL = false;
bool walkL = false;

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


/*
void discoParty() {

  int  r = rand() % 6;
  r = r + 3;

  if (r == 3){
  digitalWrite(greenPin, HIGH);
  //delay(100);
    if(currentMillis - previousMillis >= 100){
      digitalWrite(greenPin, LOW);
    }
  }
  if (r == 4){
  digitalWrite(yellowPin, HIGH);
    if(currentMillis - previousMillis >= 100){
      //delay(100);
      digitalWrite(yellowPin, LOW);
    }

  }

  if (r == 5){
  digitalWrite(redPin, HIGH);
  //delay(100);
    if(currentMillis - previousMillis >= 100){
      digitalWrite(redPin, LOW);
    }
  }


  if (r == 6){
  digitalWrite(pin6, HIGH);
  //delay(100);
    if(currentMillis - previousMillis >= 100){
      digitalWrite(pin6, LOW);  
    }
  }

  if (r == 7){
  digitalWrite(pin7, HIGH);
  //delay(100);
    if(currentMillis - previousMillis >= 100){
      digitalWrite(pin7, LOW);
    }
  }
  
}

*/




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
      runningDiscoParty = false;
      runningStopLight = false;
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
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(redPin, LOW);
    digitalWrite(pin6, LOW);
    digitalWrite(pin7, LOW);
    greenL = false;
    yellowL = false;
    redL = false;
    walkL = false;  
    runningDiscoParty = false;
    runningStopLight = true;
    single = 0;
  }


//Running the disco here
  if(runningDiscoParty){
    Serial.println("Disco Party is running!");
      //runningDiscoParty = false;
      runningStopLight = false;
  
    if(currentMillis - previousMillis >= 100){
      int r = rand() % 6;
      r = r + 3;
      //Serial.println("IN THE PARTY");
      runningStopLight = false;

      digitalWrite(greenPin, LOW);
      digitalWrite(yellowPin, LOW);
      digitalWrite(redPin, LOW);
      digitalWrite(pin6, LOW);
      digitalWrite(pin7, LOW);
     
      if (r == 3){
        digitalWrite(greenPin, HIGH);       
      }
      if (r == 4){
        digitalWrite(yellowPin, HIGH);
      }
      if (r == 5){
        digitalWrite(redPin, HIGH);
      }
      if (r == 6){
        digitalWrite(pin6, HIGH);  
      }
      if (r == 7){
        digitalWrite(pin7, HIGH); 
      } 
    }
  }


  if(runningStopLight){
    
    runningDiscoParty = false;
    //runningStopLight = false;
    if(greenL == false && yellowL == false && redL == false && walkL == false){
        previousMillis = currentMillis;
        digitalWrite(greenPin, HIGH);
        greenL = true;
    }
  
    if(currentMillis - previousMillis >= 7000 && greenL == true && 
    yellowL == false && redL == false && walkL == false){
      //digitalWrite(greenPin, HIGH);
      //delay(7000);
      digitalWrite(greenPin, LOW);
      digitalWrite(yellowPin, HIGH);
      yellowL = true; 
    }
  
    if(currentMillis - previousMillis >= 10000 && greenL == true && 
    yellowL == true && redL == false && walkL == false){
      //digitalWrite(yellowPin, HIGH);
      //delay(3000);
      digitalWrite(yellowPin, LOW);
      digitalWrite(redPin, HIGH);
      digitalWrite(pin6, HIGH);
      redL = true;
      walkL = true;
    }
  
    if(currentMillis - previousMillis >= 17000 && greenL == true && 
    yellowL == true && redL == true && walkL == true){
      //digitalWrite(redPin, HIGH);
      //digitalWrite(walkingPin, HIGH);
      //delay(7000);
      digitalWrite(pin6, LOW);
      //walkL = true;
    }
  
    if(currentMillis - previousMillis >= 20000 && greenL == true && 
    yellowL == true && redL == true && walkL == true){
      //delay(3000);
      digitalWrite(redPin, LOW);
      previousMillis = currentMillis;
      greenL = false;
      yellowL = false;
      redL = false;
      walkL = false;  
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
    //toggleLED();
    Serial.println("double press");
    runningDiscoParty = true;  
    runningStopLight = false;
    //discoParty();
    single = 0;
    lastSwitchTime = millis();
  }  

}

void toggleLED() {
  if (LEDstate == 0) {
    LEDstate = 1;
  } else {
    LEDstate = 0;
  }
  //digitalWrite(led, LEDstate);  
} 

  /*
void stopLight() {

  currentMillis = millis();

  digitalWrite(greenPin, HIGH);
  if(currentMillis - previousMillis >= 7000){
    previousMillis = currentMillis;
    
    //delay(7000);
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, HIGH);
  }
  Serial.println("running stop light");
  if(currentMillis - previousMillis >= 3000){
    previousMillis = currentMillis;
    //delay(3000);
    digitalWrite(yellowPin, LOW); 
    digitalWrite(redPin, HIGH);
    digitalWrite(pin6, HIGH);
  }

  if(currentMillis - previousMillis >= 7000){
    previousMillis = currentMillis;
    //delay(7000);
    digitalWrite(pin6, LOW);
  }
    
  if(currentMillis - previousMillis >= 3000){
    previousMillis = currentMillis;
    //delay(3000);
    digitalWrite(redPin, LOW);  
  }

  
}
*/
