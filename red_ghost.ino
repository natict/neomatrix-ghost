/*
*  Just a static red ghost for 8x8 NeoMatrix
*/
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

// Control PIN
#define PIN 1

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, PIN,
  NEO_MATRIX_BOTTOM  + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB            + NEO_KHZ800);

// --------------------------------------------  
// Set the brightness (max 50)
int brigh = 40;
// Delay between animation
int wait = 200;
// ---------------------------------------------

const unsigned char PROGMEM ghost[] =
{B00111000,
 B01111100,
 B10010010,
 B10010010,
 B11111110,
 B11111110,
 B11111110,
 B10101010};

void setup() {
  matrix.begin();
  matrix.show();
  matrix.setBrightness(brigh);
}

void loop() {
 matrix.drawBitmap(0,0, ghost, 8, 8, matrix.Color(200, 0, 0));
 // Add blue eyes
 matrix.drawPixel(2,3, matrix.Color(0, 0, 200));
 matrix.drawPixel(5,3, matrix.Color(0, 0, 200));
 matrix.show();
 //TODO: Add animation
}

