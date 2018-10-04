#include "command.h"
#include "singleton_t.h"
#include "g_data.h"

uint8_t
command::map_brightness( uint8_t absolute_brightness )
{
    uint8_t brightness = map( absolute_brightness, 0, LED_ABSOLUTE_BRIGHTNESS, 0, PIXEL_MAX_BRIGHTNESS );
    uint8_t final_brightness = constrain( brightness, 0, PIXEL_MAX_BRIGHTNESS );

    return final_brightness;
}
