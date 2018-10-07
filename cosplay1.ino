#include "constants.h"
#include "cp_types.h"
#include "singleton_t.h"
#include "g_data.h"
#include "button_array.h"
#include "bright_btn.h"
#include "command_btn.h"
#include "command_array.h"

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
    #else
        Serial.begin( 9600 );
    #endif


    init_singletons();

    pixel_strip& ps = singleton_t< pixel_strip >::instance();
    ps.begin();
    ps.show();
}

void init_singletons()
{
    init_command_array();
    init_pixel_strip();
    init_buttons();
    init_g_data();
    
    return;
}


void init_command_array()
{
    singleton_t< command_array > ca( new command_array() );
}

void init_buttons()
{
    singleton_t< button_array > ba( new button_array );

    button_array& buttons = singleton_t< button_array >::instance();
    buttons.bright_btn( new bright_btn( BRIGHTNESS_BTN_PIN ) );
    buttons.command_btn( new command_btn( COMMAND_BTN_PIN ) );

    return;
}

void init_g_data()
{
    singleton_t< g_data > gd( new g_data );

    return;
}

void init_pixel_strip()
{
    // Parameter 1 = number of pixels in strip
    // Parameter 2 = Arduino pin number (most are valid)
    // Parameter 3 = pixel type flags, add together as needed:
    //   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
    //   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
    //   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
    //   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
    //   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
    singleton_t< pixel_strip > strip( new pixel_strip( NUM_PIXELS, PIXEL_ARRAY_PIN, NEO_GRB + NEO_KHZ800 ) );

    return;
}

void loop() 
{
    command_array& ca = singleton_t< command_array >::instance();
    button_array&  ba = singleton_t< button_array >::instance();
    g_data&        gd = singleton_t< g_data >::instance();

    ba.update_buttons();
    ca.tick();
}
