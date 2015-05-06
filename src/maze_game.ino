/*************************************************** 
  This is a library for our I2C LED Backpacks

  Designed specifically to work with the Adafruit LED Matrix backpacks 
  ----> http://www.adafruit.com/products/872
  ----> http://www.adafruit.com/products/871
  ----> http://www.adafruit.com/products/870

  These displays use I2C to communicate, 2 pins are required to 
  interface. There are multiple selectable I2C addresses. For backpacks
  with 2 Address Select pins: 0x70, 0x71, 0x72 or 0x73. For backpacks
  with 3 Address Select pins: 0x70 thru 0x77

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
// For LED Backpack
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
// For LCD Shield
#include <Adafruit_MCP23017.h>
#include <Adafruit_RGBLCDShield.h>

class Unit {
  public:
   int x = 2;
   int y = 2;
   int hp;
   int color;
   void drawUnit(Adafruit_BicolorMatrix matrix) { 
     matrix.drawPixel(x, y, LED_GREEN);
     matrix.writeDisplay();  // write the changes we just made to the display
   }
};



Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();
Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

Unit *hero;
boolean doesNeedRedraw;
int8_t lastButtonPress = 0;
int8_t frame = 0;



void setup() {
  // Serial.begin(9600);
  // Serial.println("8x8 LED Matrix Test");
  hero = new Unit();
  
  matrix.begin(0x70);  // pass in the address

  lcd.begin(0, 0);         // initialize display colums and rows
  lcd.setBacklight(0x7);
}

static const uint8_t PROGMEM
  smile_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100 },
  neutral_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10111101,
    B10000001,
    B01000010,
    B00111100 },
  frown_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10011001,
    B10100101,
    B01000010,
    B00111100 },
  maze_bmp[] =
  { B10100000,
    B10110000,
    B10010000,
    B11011100,
    B01000100,
    B01110100,
    B00010100,
    B00010111 };

void loop() {
  pollKeys();
  drawText();
  drawMaze();
  drawHero();
  delay(500);
}

void drawText() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Fun Game");
}

void drawMaze() {
  matrix.clear();
  matrix.drawBitmap(0, 0, maze_bmp, 8, 8, LED_YELLOW);
  matrix.writeDisplay();
}

void drawHero() {
  hero->drawUnit(matrix);
}





void pollKeys() {
  uint8_t buttons;                       // button read value

  buttons = lcd.readButtons();  // read the buttons on the shield
 
  if(buttons!=0) {                     // if a button was pressed
    boolean wasSelectButtonPressedTooRecently = (frame - lastButtonPress) <= 8;
    doesNeedRedraw = true;
    if (buttons & BUTTON_RIGHT) {       // if up pressed, increment hours
      hero->x +=1;
    }
    if (buttons & BUTTON_LEFT) {     // if down pressed, decrement hours
      hero->x -=1;
    }
    if (buttons & BUTTON_UP) {       // if up pressed, increment hours
      hero->y -=1;
    }
    if (buttons & BUTTON_DOWN) {     // if down pressed, decrement hours
      hero->y +=1;
    }

    /* if (buttons & BUTTON_SELECT && !wasSelectButtonPressedTooRecently ) { 
      lastButtonPress = frame;
      if(backlight)                 // if the backlight is on
        backlight=OFF;             //   set it to off
      else                          // else turn on the backlight if off 
        backlight=WHITE;           //   (you can select any color)
      
      lcd.setBacklight(backlight);  // set the new backlight state
    } */

    if (buttons & BUTTON_SELECT && wasSelectButtonPressedTooRecently ) { 
      doesNeedRedraw = false;
    }

    //confineDisplayText();
  }
}








/*
void loop() {

  matrix.clear();
  matrix.drawBitmap(0, 0, smile_bmp, 8, 8, LED_GREEN);
  matrix.writeDisplay();
  delay(500);

  matrix.clear();
  matrix.drawBitmap(0, 0, neutral_bmp, 8, 8, LED_YELLOW);
  matrix.writeDisplay();
  delay(500);

  matrix.clear();
  matrix.drawBitmap(0, 0, frown_bmp, 8, 8, LED_RED);
  matrix.writeDisplay();
  delay(500);

  matrix.clear();      // clear display
  matrix.drawPixel(0, 0, LED_GREEN);  
  matrix.writeDisplay();  // write the changes we just made to the display
  delay(500);

  matrix.clear();
  matrix.drawLine(0,0, 7,7, LED_YELLOW);
  matrix.writeDisplay();  // write the changes we just made to the display
  delay(500);

  matrix.clear();
  matrix.drawRect(0,0, 8,8, LED_RED);
  matrix.fillRect(2,2, 4,4, LED_GREEN);
  matrix.writeDisplay();  // write the changes we just made to the display
  delay(500);

  matrix.clear();
  matrix.drawCircle(3,3, 3, LED_YELLOW);
  matrix.writeDisplay();  // write the changes we just made to the display
  delay(500);

  matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix.setTextSize(1);
  matrix.setTextColor(LED_GREEN);
  for (int8_t x=7; x>=-36; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print("Hello");
    matrix.writeDisplay();
    delay(100);
  }
  matrix.setRotation(3);
  matrix.setTextColor(LED_RED);
  for (int8_t x=7; x>=-36; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print("World");
    matrix.writeDisplay();
    delay(100);
  }
  matrix.setRotation(0);
}
*/
