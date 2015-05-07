Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();
Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

Unit *hero;
boolean doesNeedRedraw = true;
boolean textNeedsRedraw = true;
int8_t lastButtonPress = 0;
// 0-255
uint8_t frame = 0;

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
  walls_bmp[] =
  { B10100000,
    B10110000,
    B10010000,
    B11011100,
    B01000100,
    B01110100,
    B00010100,
    B00011100 };
