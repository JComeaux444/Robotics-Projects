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
  int  r = rand() % 6;
  r = r + 3;

  if (r == 3){
  digitalWrite(greenPin, HIGH);
  delay(100);
  digitalWrite(greenPin, LOW);
  }
  if (r == 4){
  digitalWrite(yellowPin, HIGH);
  delay(100);
  digitalWrite(yellowPin, LOW);
  }

  if (r == 5){
  digitalWrite(redPin, HIGH);
  delay(100);
  digitalWrite(redPin, LOW);
  }


  if (r == 6){
  digitalWrite(pin6, HIGH);
  delay(100);
  digitalWrite(pin6, LOW);  
  }

  if (r == 7){
  digitalWrite(pin7, HIGH);
  delay(100);
  digitalWrite(pin7, LOW);
  }
}
