int pwm = 12;
int timer, interval;
int i = 0;
int led = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  while(i<= pwm){
    interval = millis()-timer;
    digitalWrite(led,HIGH);
    delay(i);
    if(i == pwm){
      delay(400);  
    }  
    digitalWrite(led,LOW);
    delay(pwm);
    if(interval >= 40){
      i++;
      timer = millis();
    }
  }

  while(i>=0){
    interval = millis()-timer;
    digitalWrite(led,HIGH);
    delay(i);
    digitalWrite(led,LOW);
    delay(pwm);
    if(i==0){
      delay(400);
    }
    if (interval >= pwm){
      i--;
      timer = millis();
    }
    
  }
  i=0;

}
