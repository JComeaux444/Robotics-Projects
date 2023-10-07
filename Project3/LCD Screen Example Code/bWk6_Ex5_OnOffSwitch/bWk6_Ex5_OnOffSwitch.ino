/*
 * Used ssd1306 128-64 example to get started / as a base
 * 
 * 
 */

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int button = 7;
boolean on = true;

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

void setup() {

  for(int i = 0; i <= 13; i++){
        pinMode(i, INPUT);
  }
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Clear the buffer
  display.clearDisplay();
  display.setTextWrap(true);//This line will make the text try and fit in one screen
  display.setTextSize(4); 
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 25);
  display.println("ON");
  display.display();  

  

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
      hold = 0;
    }   
  }
  lastReading = reading;

  if (single == 1 && (millis() - lastSwitchTime) > doubleTime) {
    Serial.println("single press");
    previousMillis = currentMillis;
    single = 0;
    on = !on;
    Serial.println(on);
    display.setCursor(0, 25);
    display.clearDisplay();
    if(on){
      display.println("ON");
    } else {
      display.println("OFF");
    }
    display.display();  
      
  }

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
