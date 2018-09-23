#include "g_data.h"

#include "constants.h"

void
g_data::increment_brightness()
{
    if ( brightness() < PIXEL_ARRAY_MAX_BRIGHTNESS )
    {
        brightness( brightness() + 1 );
    }

    return;
}

void
g_data::decrement_brightness()
{
    if ( brightness() > PIXEL_ARRAY_MAX_BRIGHTNESS )
    {
        brightness( brightness() - 1 );
    }

    return;
}

