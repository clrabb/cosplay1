#include "command_all_same.h"
#include "constants.h"
#include "singleton_t.h"
#include "cp_types.h"


void
command_all_same::tick()
{
    uint32_t color = this->get_color();
    if ( color == this->last_color() )
        return;

    
    pixel_strip& ps = singleton_t< pixel_strip >::instance();
    
    for ( int i = 0; i < NUM_PIXELS; ++i )
    {
        ps.setPixelColor( i, color );
    }

    ps.show();
}

void
command_all_same::init()
{
}

