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
    uint8_t brightness = this->brightness();
    
    if ( brightness < MAX_BRIGHTNESS_LVL )
    {
        if ( brightness == MAX_BRIGHTNESS_LVL )
        {
            this->brightness( 0 );
        }
        else
        {
            this->brightness( brightness++ );
        }
    }

    return;
}

