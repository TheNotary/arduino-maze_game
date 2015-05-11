#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include "Map.h"
#include "Arduino.h"

Map::Map(const uint8_t walls_bmp[8]) {
  _level = 0;
  //walls = walls_bmp;
  for (uint8_t i = 0; i < 8; i++) {
    walls[i] = walls_bmp[i];
  }
}
 
void Map::draw(Adafruit_BicolorMatrix &matrix, uint8_t *walls_bmp){
  
  
  matrix.drawBitmapEasy(0, 0, walls_bmp, 8, 8, LED_YELLOW);
}

void Map::setLevel(uint8_t level){
  _level = level;
}

uint8_t Map::getLevel(){
  return _level;
}

