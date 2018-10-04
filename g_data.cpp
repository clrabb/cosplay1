#include "g_data.h"

#include "constants.h"
#include <arduino.h>

g_data::g_data()
    : m_absolute_brightness( 0 )
{
}

void
g_data::increment_absolute_brightness()
{
    uint8_t current_brightness = this->absolute_brightness();

    uint8_t new_brightness =
        ( current_brightness == LED_ABSOLUTE_BRIGHTNESS )
            ? 0
            : ++current_brightness
    ;

    this->absolute_brightness( new_brightness );

    return;
}

