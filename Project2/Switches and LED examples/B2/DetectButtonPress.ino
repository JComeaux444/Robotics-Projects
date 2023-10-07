bool buttonStateUp = true;
// inspired by
// https://arduino.stackexchange.com/questions/48243/detecting-if-a-push-button-was-pressed-and-released
void setup() {
  Serial.begin(9600);
  pinMode(12,INPUT);

}

void loop() {
  if (digitalRead(12) == LOW && buttonStateUp){
    Serial.println("Button is up"); 
    buttonStateUp = false; 
  }
  if (digitalRead(12) == HIGH && buttonStateUp == false){
    Serial.println("Button is down");  
    buttonStateUp = true;
  }
}
