#include "command_all_blue.h"
#include "cp_types.h"
#include "g_data.h"
#include "singleton_t.h"

uint32_t
command_all_blue::get_color()
{
    g_data& data = singleton_t< g_data >::instance();
    pixel_strip& strip = singleton_t< pixel_strip >::instance();
    uint8_t brightness = this->map_brightness( data.absolute_brightness() );
    return  strip.Color( 0, 0, brightness ); // green
}

