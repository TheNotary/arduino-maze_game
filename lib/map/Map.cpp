#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include "Map.h"
#include "Arduino.h"

Map::Map(const uint8_t walls_bmp[8]) {
  for (uint8_t i = 0; i < 8; i++) {
    walls[i] = walls_bmp[i];
  }
}
 
void Map::draw(Adafruit_BicolorMatrix matrix){
  matrix.clear();
  matrix.drawBitmap(0, 0, walls, 8, 8, LED_RED);
  matrix.writeDisplay();
}


