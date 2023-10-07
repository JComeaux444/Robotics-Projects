int redPin = 3;
int yellowPin = 4;
int greenPin = 5;
int pin6 = 9;
int pin7 = 10;
void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i <= 13; i++){
        pinMode(i, INPUT);
  }
    
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin7, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(greenPin, HIGH);
  delay(1000);
  digitalWrite(greenPin, LOW);
  
  digitalWrite(yellowPin, HIGH);
  delay(1000);
  digitalWrite(yellowPin, LOW);
  

  digitalWrite(redPin, HIGH);
  delay(1000);
  digitalWrite(redPin, LOW);
  
 
  digitalWrite(pin6, HIGH);
  delay(1000);
  digitalWrite(pin6, LOW);  
  
 
  digitalWrite(pin7, HIGH);
  delay(1000);
  digitalWrite(pin7, LOW);
  
}
