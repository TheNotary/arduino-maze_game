#ifndef HEADER_MAP
  #define HEADER_MAP
   
  class Map {
    public:
     Map(const uint8_t walls_bmp[8]);
     uint8_t walls[8];
     uint8_t _level;
     void draw(Adafruit_BicolorMatrix matrix, const uint8_t *walls_bmp);
     void setLevel(uint8_t level);
     uint8_t getLevel();
  };
   
#endif

