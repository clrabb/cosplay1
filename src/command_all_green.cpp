#include "command_all_green.h"

uint32_t
command_all_green::get_color_impl( pixel_strip& strip, uint8_t brightness )
{
    return strip.Color( brightness, 0, 0 ); // green
}

