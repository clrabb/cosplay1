#include "command_all_red.h"

uint32_t
command_all_red::get_color_impl( pixel_strip& strip, uint8_t brightness )
{
    return  strip.Color( 0, brightness, 0 ); // red
}

