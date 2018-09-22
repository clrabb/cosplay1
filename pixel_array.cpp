#include "pixel_array.h"

pixel_array::pixel_array( uint8_t num_pixels, short pin, int parms )
{
    this->m_pixel_strip = new pixel_strip( num_pixels, pin, parms );
}

uint16_t 
pixel_array::num_pixels()
{
    pixel_strip* pixels = this->m_pixel_strip;
    return pixels->numPixels();
}

void
pixel_array::rainbow( uint8_t wait )
{
    uint16_t i, j;
    pixel_strip* strip = this->m_pixel_strip;
    
    for( j = 0; j < 256; j++ ) 
    {
        for( i = 0; i < this->num_pixels(); i++ ) 
        {
            strip->setPixelColor( i, wheel( ( i + j ) & 255 ) );
        }
        
        strip->show();
        delay(wait);
    }
}

// Input a value 0 to 255 to get a color value.
// The colors are a transition r - g - b - back to r.
uint32_t 
pixel_array::wheel( byte wheel_pos ) 
{
    wheel_pos = 255 - wheel_pos;
    pixel_strip* strip = this->m_pixel_strip;

    uint32_t retval;
    if ( wheel_pos < 85 )
    {
        retval = strip->Color( 255 - wheel_pos * 3, 0, wheel_pos * 3 );
    }
    else if ( wheel_pos < 170 )
    {
        byte new_pos = wheel_pos - 85;
        retval = strip->Color( 0, new_pos * 3, 255 - new_pos * 3 );
    }
    else
    {
        byte new_pos = wheel_pos = 170;
        retval = strip->Color( new_pos * 3, 255 - new_pos * 3, 0 );
    }
    
    return retval;
}

