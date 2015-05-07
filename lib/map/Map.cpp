#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include "Map.h"
#include "Arduino.h"

Map::Map(uint8_t walls_bmp[]) {
  walls = walls_bmp;
}
 
void Map::draw(Adafruit_BicolorMatrix matrix){
  matrix.clear();
  matrix.drawBitmap(0, 0, walls, 8, 8, LED_YELLOW);
  matrix.writeDisplay();
}


