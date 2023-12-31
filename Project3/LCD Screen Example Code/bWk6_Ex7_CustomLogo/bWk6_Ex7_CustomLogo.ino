/**************************************************************************

 Used example for a 128x64 pixel display using I2C to communicate


  Copied from previous ex6 code and made slight changes to make it display only one image

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



#define LOGO_HEIGHT   54
#define LOGO_WIDTH    64
static const unsigned char PROGMEM logo_bmp[] =
{ 0x00, 0xa0, 0x00, 0x06, 0x38, 0x00, 0x00, 0x00, 0x81, 0xa0, 0x00, 0x02, 0x3c, 0x00, 0x00, 0x00, 
0x81, 0x60, 0x08, 0x0e, 0x2e, 0x00, 0x00, 0x00, 0x81, 0x60, 0x44, 0x0e, 0x2f, 0x80, 0x00, 0x00, 
0x02, 0x60, 0x48, 0x0e, 0x2d, 0xf0, 0x00, 0x00, 0x0a, 0x60, 0x48, 0x02, 0x0c, 0xf8, 0x00, 0x00, 
0x02, 0x40, 0xc8, 0x02, 0x08, 0x7c, 0x00, 0x00, 0x0a, 0x40, 0xd0, 0x02, 0x08, 0x7e, 0x00, 0x00, 
0x0c, 0xc0, 0xd8, 0x10, 0x00, 0x7e, 0x00, 0x00, 0x04, 0xc0, 0xf8, 0x90, 0x00, 0x7f, 0x80, 0x00, 
0x1c, 0xc0, 0xfc, 0xd0, 0x00, 0x7e, 0x80, 0x00, 0x14, 0x60, 0xfc, 0x38, 0x00, 0x3e, 0xc0, 0x00, 
0x14, 0x40, 0xfc, 0x98, 0x00, 0x3e, 0xfc, 0x00, 0x14, 0x61, 0xed, 0x9e, 0x00, 0x3e, 0x7c, 0x00, 
0x14, 0x61, 0xed, 0x89, 0xcf, 0xfc, 0x7f, 0xc0, 0x14, 0x73, 0xe4, 0xc8, 0x04, 0xff, 0xff, 0xc0, 
0x91, 0x7b, 0xd4, 0xc8, 0x04, 0x18, 0x7c, 0x60, 0x99, 0xf1, 0xde, 0x3d, 0xdc, 0x18, 0x1c, 0x60, 
0x19, 0xd7, 0xca, 0x9a, 0xb7, 0x7c, 0x5c, 0x60, 0xdc, 0xe4, 0xc0, 0x00, 0x00, 0x00, 0x1c, 0x60, 
0xfd, 0x80, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x60, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x60, 
0xfc, 0x00, 0x00, 0x00, 0x7f, 0xfd, 0xf8, 0x60, 0xfc, 0x07, 0x00, 0x00, 0xff, 0xff, 0xf8, 0x40, 
0xfc, 0x3f, 0xc0, 0x00, 0xbf, 0xff, 0xf8, 0x40, 0xff, 0xff, 0xe0, 0x00, 0x70, 0xff, 0xb8, 0x60, 
0xff, 0x8f, 0xf0, 0x03, 0xc0, 0x7f, 0xd8, 0x40, 0x3f, 0x07, 0xfc, 0x00, 0x00, 0x3f, 0xd8, 0x00, 
0x3f, 0x83, 0xe4, 0x00, 0x03, 0xf7, 0xf8, 0x00, 0x3f, 0xf8, 0xe7, 0x07, 0xf8, 0x00, 0x38, 0x00, 
0x3f, 0x00, 0x01, 0x06, 0x00, 0x00, 0x18, 0x00, 0x3f, 0x00, 0x01, 0x00, 0x00, 0x00, 0x18, 0x00, 
0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 
0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x37, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 
0x77, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x77, 0x80, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 
0x77, 0xc0, 0x00, 0x00, 0x00, 0x06, 0x08, 0x00, 0x77, 0xc0, 0x00, 0x00, 0x00, 0x06, 0x08, 0x00, 
0x77, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x67, 0xe0, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 
0x67, 0xe0, 0x10, 0x00, 0x00, 0x04, 0x10, 0x00, 0xa7, 0xf0, 0x10, 0x00, 0x00, 0x08, 0x10, 0x00, 
0xa7, 0xf0, 0x08, 0x00, 0x00, 0x20, 0x30, 0x00, 0x6f, 0xf8, 0x04, 0x00, 0x00, 0x40, 0x30, 0x00, 
0x6f, 0xfc, 0x01, 0x00, 0x00, 0x80, 0x70, 0x00, 0x4f, 0xfe, 0x00, 0x9a, 0x0b, 0x00, 0xf0, 0x00, 
0x4f, 0xff, 0x00, 0x3f, 0xfc, 0x01, 0xf0, 0x00, 0x4f, 0xff, 0x80, 0x00, 0x00, 0x03, 0xf0, 0x00, 
0x4f, 0xff, 0xe0, 0x00, 0x00, 0x0c, 0x30, 0x00, 0x4f, 0xff, 0xf8, 0x00, 0x00, 0x38, 0x50, 0x00, 
0xcf, 0xff, 0xfc, 0x00, 0x00, 0x60, 0x10, 0x00, 0x8f, 0xff, 0xff, 0x00, 0x01, 0xc0, 0x12, 0x00, 
0x8f, 0xff, 0xff, 0xfc, 0x03, 0x80, 0x12, 0x00, 0x87, 0xff, 0xfe, 0x06, 0x0e, 0x00, 0x12, 0x00, 
0x83, 0xff, 0xec, 0x02, 0x1c, 0x00, 0x12, 0x00, 0x83, 0x7f, 0xd8, 0x03, 0x78, 0x02, 0x12, 0x00, 
0x83, 0x4b, 0xe0, 0x01, 0xf0, 0x04, 0x12, 0x00, 0x00, 0x00, 0xc7, 0x01, 0xe0, 0x02, 0x16, 0x00, 
0x00, 0x03, 0x1f, 0xe0, 0x80, 0x00, 0x1e, 0x00, 0x00, 0x06, 0x70, 0x38, 0xc0, 0x00, 0x1e, 0x00, 
0x00, 0x0c, 0xc0, 0x0c, 0x40, 0x00, 0x34, 0x00, 0x00, 0x18, 0x80, 0x07, 0x40, 0x00, 0x14, 0x00  };

void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.clearDisplay();

  display.invertDisplay(true);

  testdrawbitmap();    // Draw a small bitmap image


}

void loop() {
}


void testdrawbitmap(void) {
  display.clearDisplay();

  display.drawBitmap(
    (display.width()  - LOGO_WIDTH ) / 2,
    (display.height() - LOGO_HEIGHT) / 2,
    logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();
  delay(10000);
}
