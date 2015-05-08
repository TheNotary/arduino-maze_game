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

// For pixel Units, such as hero
#include <Unit.h>
// For organizing maps
#include <Map.h>

#include "Globals.h"



void setup() {
  Serial.begin(115200);
  Serial.println("Starting Maze Game");
  
  hero = new Unit(4,6);
  map1 = new Map(walls1_bmp);
  
  matrix.begin(0x70);  // pass in the address
  matrix.setBrightness(1);

  lcd.begin(0, 0);         // initialize display colums and rows
  lcd.setBacklight(0x7);
}



void loop() {
  pollKeys();
  drawText();
  if(doesNeedRedraw){
    drawWalls();
    drawHero();
    doesNeedRedraw = false;
  }
  delay(100);
}

void drawText() {
  if(textNeedsRedraw){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Fun Game");
    textNeedsRedraw = false;
  }
}

void drawWalls() {
  map1->draw(matrix);
  //matrix.clear();
  //matrix.drawBitmap(0, 0, walls1_bmp, 8, 8, LED_YELLOW);
  //matrix.writeDisplay();
}

void drawHero() {
  hero->draw(matrix);
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

    if (buttons & BUTTON_SELECT && !wasSelectButtonPressedTooRecently ) { 
      lastButtonPress = frame;
      if(true){               // if the backlight is on
        Serial.println("Select Pressed");
        // backlight=OFF;             //   set it to off
      }
      else{                        // else turn on the backlight if off 
        // backlight=WHITE;           //   (you can select any color)
      }
      
      //lcd.setBacklight(backlight);  // set the new backlight state
    }

    if (buttons & BUTTON_SELECT && wasSelectButtonPressedTooRecently ) { 
      doesNeedRedraw = false;
    }

    //confineDisplayText();
  }
}




