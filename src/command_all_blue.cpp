#include "command_all_blue.h"
#include "cp_types.h"
#include "singleton_t.h"

uint32_t
command_all_blue::get_color_impl( pixel_strip& strip, uint8_t brightness )
{
    return  strip.Color( 0, 0, brightness ); // blue
}

