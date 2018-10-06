#include "command.h"
#include "singleton_t.h"
#include "g_data.h"

// Maps the small number of 'brightness steps', i.e. 0 - 5
// to a 0 - 255 value.  
//
uint8_t
command::map_brightness()
{
    g_data& data = singleton_t< g_data >::instance();
    
    uint8_t brightness = map( data.absolute_brightness(), 0, LED_ABSOLUTE_BRIGHTNESS, 0, PIXEL_MAX_BRIGHTNESS );
    uint8_t final_brightness = constrain( brightness, 0, PIXEL_MAX_BRIGHTNESS );

    return final_brightness;
}    

// Return the color bitmap using 
uint32_t
command::get_color()
{
    pixel_strip& strip = singleton_t< pixel_strip >::instance();
    uint8_t mapped_brightness = this->map_brightness();
    return this->get_color_impl( strip, mapped_brightness );
}



