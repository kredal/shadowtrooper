/**************************************************************
 * Shadow Stormtrooper addressable LED code
 * Uses Neopixels or WS2812 LED strips
 * Uses Adafruit Pro Trinket, 5V
 * Uses Latch type wireless transmitter and reciever to 
 * control the light settings. Found at:
 * https://www.adafruit.com/products/1098
 * Code by Josh Ward, TK-44678
 * ************************************************************/
 
#include "FastLED.h"

#define NUM_STRIPS 9

#define NUM_LEDS 260 //This is just a guess.

#define BRIGHTNESS 128  //half bright, change this as needed.
//A2-A5 on the Pro Trinket
const int aPin = 16;
const int bPin = 17; 
const int cPin = 18;
const int dPin = 19;


CRGB leds[NUM_LEDS];

void setup() {
 //pin >(leds, first led, number in strip)
 //These are all just guesses. The pins are right though. (:
  FastLED.addLeds<NEOPIXEL, 3>(leds, 0, 20);

  FastLED.addLeds<NEOPIXEL, 4>(leds, 20, 30);

  FastLED.addLeds<NEOPIXEL, 5>(leds, 50, 30);

  FastLED.addLeds<NEOPIXEL, 6>(leds, 80, 30);

  FastLED.addLeds<NEOPIXEL, 8>(leds, 110, 30);

  FastLED.addLeds<NEOPIXEL, 9>(leds, 140, 30);

  FastLED.addLeds<NEOPIXEL, 10>(leds, 170, 30);

  FastLED.addLeds<NEOPIXEL, 11>(leds, 200, 30);

  FastLED.addLeds<NEOPIXEL, 12>(leds, 230, 30);

  FastLED.setBrightness(BRIGHTNESS);

  pinMode(aPin, INPUT); 
  pinMode(bPin, INPUT);
  pinMode(cPin, INPUT); 
  pinMode(dPin, INPUT);
  
  /* this zips down all the LEDs in order shown above. Commented out.
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Red;
    FastLED.show();
    leds[i] = CRGB::Black;
    delay(50);
  }
 */

}

void loop() {

  aState = digitalRead(aPin);
  bState = digitalRead(bPin);
  cState = digitalRead(cPin);
  dState = digitalRead(dPin);

if (aState == HIGH || (bState == LOW && cState == LOW && dState == LOW)) {
  //This makes all the pixels everywhere cyan (00FFFF) 
  // Default if pin A is high, or all the others are low (because nothing has been pressed yet.)
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Cyan;
    }
    FastLED.show();
    delay(500);
  }

else if (bState == HIGH) {
  //This makes all the pixels everywhere red (FF0000)
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Red;
    }
    FastLED.show();
    delay(500);
  }

else if (cState == HIGH) {
  //This makes all the pixels everywhere green (00FF00)
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Green;
    }
    FastLED.show();
    delay(500);
  }

else if (dState==HIGH) {
  //Rainbow wheel or party mode or something else. I haven't decided yet.  (:
  }

}
