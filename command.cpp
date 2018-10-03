#include "command.h"
#include "singleton_t.h"
#include "g_data.h"

uint8_t
command::map_brightness()
{
    g_data& data = singleton_t< g_data >::instance();
    uint8_t brightness = map( data.brightness(), 0, MAX_BRIGHTNESS_LVL, 0, PIXEL_MAX_BRIGHTNESS );
    uint8_t final_brightness = constrain( data.brightness(), 0, PIXEL_MAX_BRIGHTNESS );

    return final_brightness;
}
