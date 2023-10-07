/**************************************************************************

 Used example for a 128x64 pixel display using I2C to communicate


  Remade logo and code to make animation go from right to left

 **************************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMTANKS     7 // Number of tanks in the animation example

#define LOGO_HEIGHT   20
#define LOGO_WIDTH    34
static const unsigned char PROGMEM logo_bmp[] =
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x05, 0x50, 0x00, 0x00, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x1f, 0xff, 
0xfc, 0x00, 0x00, 0x00, 0x1f, 0xfc, 0x00, 0x00, 0x01, 0xff, 0xff, 0x00, 0x00, 0x03, 0xff, 0xff, 
0xfc, 0x00, 0x0f, 0xff, 0xff, 0xff, 0x80, 0x1f, 0xff, 0xff, 0xff, 0x80, 0x3f, 0xff, 0xff, 0xff, 
0x80, 0x7f, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0xff, 0x80, 0x7f, 0xff, 0xff, 0xff, 0x00, 
0x4f, 0xef, 0xf7, 0xf2, 0x00, 0x6e, 0x76, 0x76, 0x74, 0x00, 0x1f, 0xff, 0xff, 0xf8, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00 };

void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.clearDisplay();

  testanimate(logo_bmp, LOGO_WIDTH, LOGO_HEIGHT); // Animate bitmaps
}

void loop() {
}

#define XPOS   0 // Indexes into the 'icons' array in function below
#define YPOS   1
#define DELTAY 2 // Basically used to assign a random num which affects speed

void testanimate(const uint8_t *bitmap, uint8_t w, uint8_t h) {
  int8_t f, icons[NUMTANKS][3];

  // Initializes tank positions
  for(f=0; f< NUMTANKS; f++) {
    icons[f][XPOS]   = SCREEN_WIDTH;
    icons[f][YPOS]   = random(1 , display.height()-LOGO_HEIGHT/2);
    icons[f][DELTAY] = random(1, 6);
    Serial.print(F("x: "));
    Serial.print(icons[f][XPOS], DEC);
    Serial.print(F(" y: "));
    Serial.print(icons[f][YPOS], DEC);
    Serial.print(F(" dy: "));
    Serial.println(icons[f][DELTAY], DEC);
  }

  for(;;) { // Loops forever...
    display.clearDisplay(); 

    // Draws each tank
    for(f=0; f< NUMTANKS; f++) {
      display.drawBitmap(icons[f][XPOS], icons[f][YPOS], bitmap, w, h, SSD1306_WHITE);
    }

    display.display(); 
    delay(1); // speed where shorter is faster

    // Updates position of each tank
    for(f=0; f< NUMTANKS; f++) {
      icons[f][XPOS] -= icons[f][DELTAY];
      // If the tank is off the left side of the screen
      if (icons[f][XPOS] <= -LOGO_WIDTH) {
        // Reinitialize to a random position to the right side of the screen
        icons[f][YPOS]   = random(1 , display.height()-LOGO_HEIGHT/2);
        icons[f][XPOS]   = SCREEN_WIDTH;
        icons[f][DELTAY] = random(1, 6);
      }
    }
  }
}
