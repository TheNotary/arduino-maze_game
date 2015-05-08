#ifndef HEADER_MAP
  #define HEADER_MAP
   
  class Map {
    public:
     Map(const uint8_t walls_bmp[8]);
     uint8_t walls[8];
     void draw(Adafruit_BicolorMatrix matrix);
  };
   
#endif

