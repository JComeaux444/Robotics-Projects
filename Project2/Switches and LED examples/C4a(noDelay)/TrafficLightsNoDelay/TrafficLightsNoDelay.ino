int redPin = 3;
int yellowPin = 4;
int greenPin = 5;
int pin6 = 9;

bool greenL = false;
bool yellowL = false;
bool redL = false;
bool walkL = false;


const long interval = 1000;
unsigned long previousMillis = 0;
unsigned long currentMillis;


void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i <= 13; i++){
        pinMode(i, INPUT);
  }
    
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(walkingPin, OUTPUT);

}

void loop() {

  
  currentMillis = millis();
  // put your main code here, to run repeatedly:




  if(greenL == false && yellowL == false && redL == false && walkL == false){
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
