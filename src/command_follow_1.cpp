#include "command_follow_1.h"

command_follow_1::command_follow_1()
{

}

void
command_follow_1::init()
{

}

void 
command_follow_1::tick()
{

}

uint32_t
command_follow_1::get_color_impl( pixel_strip& strip, uint8_t brightness )
{
    return  strip.Color( 0, 12, brightness ); // blue
}

