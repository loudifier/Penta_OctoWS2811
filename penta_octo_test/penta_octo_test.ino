/*  OctoWS2811 Teensy4_PinList.ino - Demonstrate use of any pins
    http://www.pjrc.com/teensy/td_libs_OctoWS2811.html

  With Teensy 4.x, you can use any group of pins.  You are not limited
  to only 8 fixed pins as with Teensy 3.x.  This example shows how to
  use only 4 pins, which are the 4 pins of the Octo28 shield which do
  not conflict with the Audio shield.

  Required Connections
  --------------------
    pin 2:  LED Strip #1
    pin 14: LED strip #2
    pin 6:  LED strip #5
    pin 5:  LED strip #8
*/

#include <OctoWS2811.h>

/* Any group of digital pins may be used
Pinouts of the Penta_OctoWS2811 board (Teensy 4.0 not connected to J4, J5, J8, or J9)
  J2 - 1, 2, 3, 4
  J3 - 5, 6, 7, 8
  J4 - 25, 26, 27, 28
  J5 - 29, 30, 31, 32
  J6 - 23, 22, 21, 20
  J7 - 17, 16, 15, 14
  J8 - 40, 39, 38, 37
  J9 - 36, 35, 34, 33
  J10 - 13, 18, 19, 9
  J11 - 11, 12, 41, 24 (0 can be used instead of 41 and 12 can be used instead of 24 by changing jumper pads on bottom of board)

*/
const int numPins = 40;
byte pinList[numPins] = {1, 2, 3, 4, 5, 6, 7, 8, 25, 26, 27, 28, 29, 30, 31, 32, 23, 22, 21, 20, 17, 16, 15, 14, 40, 39, 38, 37, 36, 35, 34, 33, 13, 18, 19, 9, 11, 12, 41, 24};

const int ledsPerStrip = 1365;


// These buffers need to be large enough for all the pixels.
// The total number of pixels is "ledsPerStrip * numPins".
// Each pixel needs 3 bytes, so multiply by 3.  An "int" is
// 4 bytes, so divide by 4.  The array is created using "int"
// so the compiler will align it to 32 bit memory.
const int bytesPerLED = 3;  // change to 4 if using RGBW
DMAMEM int displayMemory[ledsPerStrip * numPins * bytesPerLED / 4];
int drawingMemory[ledsPerStrip * numPins * bytesPerLED / 4];

const int config = WS2811_GRB | WS2811_800kHz;

OctoWS2811 leds(ledsPerStrip, displayMemory, drawingMemory, config, numPins, pinList);

void setup() {
  leds.begin();
  leds.show();
}

/*
#define RED    0xFF0000
#define GREEN  0x00FF00
#define BLUE   0x0000FF
#define YELLOW 0xFFFF00
#define PINK   0xFF1088
#define ORANGE 0xE05800
#define WHITE  0xFFFFFF
*/
// Less intense...

#define RED    0x160000
#define GREEN  0x001600
#define BLUE   0x000016
#define YELLOW 0x101400
#define PINK   0x120009
#define ORANGE 0x100400
#define WHITE  0x101010


void loop() {
  //int microsec = 2000000 / ledsPerStrip;  // change them all in 2 seconds
  int microsec = -30; // when microsec is set to a negative value, skip that number of frames

  // uncomment for voltage controlled speed
  // millisec = analogRead(A9) / 40;

  colorWipe(RED, microsec);
  colorWipe(GREEN, microsec);
  colorWipe(BLUE, microsec);
  colorWipe(YELLOW, microsec);
  colorWipe(PINK, microsec);
  colorWipe(ORANGE, microsec);
  colorWipe(WHITE, microsec);
}

void colorWipe(int color, int wait)
{
  for (int i=0; i < ledsPerStrip; i++) {
      for (int j=0; j< numPins; j++){
        if (i<j){
          leds.setPixel(j*ledsPerStrip + i, color ^ WHITE);
        } else {
          leds.setPixel(j*ledsPerStrip + i, color);
        }
      }
    if (wait<0){
      if ((i%int(-wait+0.5) == 0)){
        leds.show();
      }
    } else {
      leds.show();
      delayMicroseconds(wait);
    }
  }
}
