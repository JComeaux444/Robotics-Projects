/*
 * Used ssd1306 128-64 example to get started / as a base
 * 
 * Found a built in function to use to prevent text wrapping here but that's all
 * https://www.instructables.com/Scrolling-text-on-TFT-screen/
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
int width = display.width();
String foodAd = "Hamburgers, Hotdogs, Pizza, High Quality Sushi! All items only 99 cents! Quality is top notch!";


void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Clear the buffer
  display.clearDisplay();
  display.setTextWrap(false);//This line will prevent the text from trying to fit on one screen
  

}

void loop() {

  display.clearDisplay();

  display.setTextSize(3); 
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(width, 25);
  display.println(foodAd);
  display.display();  

  width = width - 4;
  Serial.println(width);
  Serial.println(foodAd.length());
  if(width < -1800){ // There is probably a way to guess how long the string is but this is manual
    width = display.width();
  }

}
