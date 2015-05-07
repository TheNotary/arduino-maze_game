#ifndef HEADER_MAP
  #define HEADER_MAP
   
  class Map {
    public:
     Map(uint8_t walls_bmp[]);
     uint8_t walls[];
     void draw(Adafruit_BicolorMatrix matrix);
  };
   
#endif

