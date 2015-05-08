#ifndef HEADER_MYCLASS
  #define HEADER_MYCLASS
   
  class Unit {
    public:
     Unit(int xPos, int yPos);
     int x;
     int y;
     int hp;
     int color;
     void draw(Adafruit_BicolorMatrix &matrix);
  };
   
#endif
