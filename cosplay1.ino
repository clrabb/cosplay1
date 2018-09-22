#include "constants.h"
#include "cp_types.h"
#include "pixel_array.h"
#include "singleton_t.h"
#include <arduino.h>

#ifdef __AVR__
  #include <avr/power.h>
#endif



// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.



void setup() 
{
    // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
    #if defined (__AVR_ATtiny85__)
        if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
    #endif

    init_singletons();
}

void init_singletons()
{
    // Parameter 1 = number of pixels in strip
    // Parameter 2 = Arduino pin number (most are valid)
    // Parameter 3 = pixel type flags, add together as needed:
    //   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
    //   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
    //   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
    //   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
    //   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
    singleton_t< pixel_array > array( new pixel_array( NUM_PIXELS, PIXEL_ARRAY_PIN, NEO_GRB + NEO_KHZ800 ) );

    return;
}

void loop() 
{
    pixel_array& pa = singleton_t< pixel_array >::instance();
    pa.rainbow( 20 );
}
