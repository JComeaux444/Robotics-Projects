// SOS blinking program
// the setup function runs once when you press reset or power the board
int led = 3;
void setup() {
  pinMode(led, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(led, HIGH); 
  delay(200);                      
  digitalWrite(led, LOW);    
  delay(200);  
  digitalWrite(led, HIGH); 
  delay(200);                      
  digitalWrite(led, LOW);    
  delay(200); 
  digitalWrite(led, HIGH); 
  delay(200);                      
  digitalWrite(led, LOW);    
  delay(500);
  //end of s start of O
  digitalWrite(led, HIGH); 
  delay(500);                      
  digitalWrite(led, LOW);    
  delay(300); 
  digitalWrite(led, HIGH); 
  delay(500);                      
  digitalWrite(led, LOW);    
  delay(300); 
  digitalWrite(led, HIGH); 
  delay(500);                      
  digitalWrite(led, LOW);    
  delay(500); 
  //Start of S end of O
  digitalWrite(led, HIGH); 
  delay(200);                      
  digitalWrite(led, LOW);    
  delay(200);  
  digitalWrite(led, HIGH); 
  delay(200);                      
  digitalWrite(led, LOW);    
  delay(200); 
  digitalWrite(led, HIGH); 
  delay(200);                      
  digitalWrite(led, LOW);    
  delay(1000);                 
}
