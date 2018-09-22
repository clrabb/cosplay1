#include "pixel_array.h"

pixel_array::pixel_array( uint8_t num_pixels )
{
    this->m_pixels = new pixel_strip( num_pixels, PIXEL_STRIP_PIN, NEO_GRB + NEO_KHZ800 );
}

