/*
 * Used ssd1306 128-64 example to get started / as a base
 * 
 * Found a built in function to use to prevent text wrapping here but that's all
 * https://www.instructables.com/Scrolling-text-on-TFT-screen/
 * 
 * 
 * Copied from my Ex3 Example with slight changes
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
int height = display.height();
String foodAdP1 = "Hamburgers";
String foodAdP2 = "Hotdogs";
String foodAdP3 = "Pizza";
String foodAdP4 = "High Quality Sushi!";
String foodAdP5 = "All items only 99 cents!";
String foodAdP6 = "Quality is top notch!";

void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Clear the buffer
  display.clearDisplay();
  display.setTextWrap(true);//This line will make the text try and fit in one screen
  

}

void loop() {

  display.clearDisplay();

  display.setTextSize(2); 
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, height);
  display.println(foodAdP1);
  display.println(foodAdP2);
  display.println(foodAdP3);
  display.println(foodAdP4);
  display.println(foodAdP5);
  display.println(foodAdP6);
  display.display();  

  height = height - 1; //a Higher(closer to zero) number means slower, but any pos num reverses it
  Serial.println(height);
  //Serial.println(foodAd.length());
  if(height < -200){ // There is probably a way to guess how long the string is but this is manual
    height = display.height();
  }

}
