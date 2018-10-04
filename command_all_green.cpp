#include "command_all_green.h"
#include "constants.h"
#include "singleton_t.h"
#include "cp_types.h"
#include "g_data.h"


void
command_all_green::tick()
{
    pixel_strip& ps = singleton_t< pixel_strip >::instance();
    g_data&      gd = singleton_t< g_data >::instance();
    
    for ( int i = 0; i < NUM_PIXELS; ++i )
    {
        ps.setPixelColor( i, this->map_brightness( gd.absolute_brightness() ), 0, 0 );
    }

    ps.show();
}

void
command_all_green::init()
{
}

