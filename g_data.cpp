#include "g_data.h"

#include "constants.h"
#include <arduino.h>

void
g_data::increment_brightness()
{
    if ( brightness() < PIXEL_ARRAY_MAX_BRIGHTNESS )
    {
        brightness( brightness() + 1 );
    }

    digitalWrite( LED_BUILTIN, HIGH );

    return;
}

void
g_data::decrement_brightness()
{
    if ( brightness() > PIXEL_ARRAY_MAX_BRIGHTNESS )
    {
        brightness( brightness() - 1 );
    }

    digitalWrite( LED_BUILTIN, LOW );

    return;
}

