#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include "Unit.h"
#include "Arduino.h"
 
void Unit::draw(Adafruit_BicolorMatrix matrix){
  matrix.drawPixel(x, y, LED_GREEN);
  matrix.writeDisplay();  // write the changes we just made to the display
}


