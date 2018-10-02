#include "g_data.h"

#include "constants.h"
#include <arduino.h>

g_data::g_data()
    : m_brightness( 0 )
{
}

void
g_data::increment_brightness()
{
    if ( this->brightness() < PIXEL_ARRAY_MAX_BRIGHTNESS )
    {
        if ( this->brightness() == MAX_BRIGHTNESS_LVL )
        {
            this->brightness( 0 );
        }
        else
        {
            this->brightness( this->brightness() + 1 );
        }
    }

    return;
}

