const int button = 12;
const int button2 = 11;

int redPin = 3;
int yellowPin = 4;
int greenPin = 5;
int pin6 = 9;
//int pin7 = 10;


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

bool buttonStateUp = true;
bool buttonStateUp2 = true; //for second button


void setup() {
  pinMode(button, INPUT);
  pinMode(button2, INPUT);
  for(int i = 0; i <= 13; i++){
        pinMode(i, INPUT);
  }
    
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(pin6, OUTPUT);
  //pinMode(pin7, OUTPUT);
  //digitalWrite(led, LOW);
  Serial.begin(9600);

}

void loop() {


  if (digitalRead(button) == LOW && buttonStateUp){
    Serial.println("Button is up"); 
    buttonStateUp = false; 
  }
  if (digitalRead(button) == HIGH && buttonStateUp == false){
    Serial.println("Button is down");  
    buttonStateUp = true;
      
    for(int i=0; i<255; i++){
      analogWrite(5, i);
      delay(10);  
    }
  }




  if (digitalRead(button2) == LOW && buttonStateUp2){
    Serial.println("Button2 is up"); 
    buttonStateUp2 = false; 
  }
  if (digitalRead(button2) == HIGH && buttonStateUp2 == false){
    Serial.println("Button2 is down");  
    buttonStateUp2 = true;
    for(int i=255; i>0; i--){
      analogWrite(5, i);
      delay(10);  
      digitalWrite(5, LOW);
    }
  }


}
