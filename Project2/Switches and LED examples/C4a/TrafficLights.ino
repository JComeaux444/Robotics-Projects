int redPin = 3;
int yellowPin = 4;
int greenPin = 5;
int walkingPin = 9;
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
  // put your main code here, to run repeatedly:
  digitalWrite(greenPin, HIGH);
  delay(7000);
  digitalWrite(greenPin, LOW);

  
  digitalWrite(yellowPin, HIGH);
  delay(3000);
  digitalWrite(yellowPin, LOW);
  


  digitalWrite(redPin, HIGH);
  digitalWrite(walkingPin, HIGH);
  delay(7000);
  digitalWrite(walkingPin, LOW);
  delay(3000);
  digitalWrite(redPin, LOW);  

}
