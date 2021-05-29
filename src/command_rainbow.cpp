#include "command_rainbow.h"
#include "singleton_t.h"
#include "cp_types.h"
#include <math.h>

command_rainbow::command_rainbow()
    : m_start_wait_mills( millis() ),
      m_outer_loop_idx( 0 ),
      m_inner_loop_idx( 0 )
{   
}

void
command_rainbow::init()
{
    m_outer_loop_idx  = 0;
    m_inner_loop_idx  = 0;
    this->start_wait_mills( millis() );
}

boolean 
command_rainbow::is_loop_delay_over()
{
    return ( millis() - this->start_wait_mills() ) >= RAINBOW_LOOP_DELAY_MILLS;
}

boolean
command_rainbow::is_loop_delay_not_over()
{
    return !( this->is_loop_delay_over() );
}

void
command_rainbow::tick()
{
    pixel_strip& strip = singleton_t< pixel_strip >::instance();
    this->inner_loop_tick( strip );
}

void
command_rainbow::inner_loop_tick( pixel_strip& strip )
{
    if ( m_inner_loop_idx == strip.numPixels() )
    {
        this->outer_loop_tick( strip );
    }
    else
    {
        strip.setPixelColor( m_inner_loop_idx++ , wheel( strip, ( m_inner_loop_idx + m_outer_loop_idx ) & 255 ) );
    }
}

void
command_rainbow::outer_loop_tick( pixel_strip& strip )
{
    if ( is_loop_delay_not_over() )
    {
        return;
    }
    
    if ( m_outer_loop_idx < 256 )
    {
        strip.show();
        start_wait_mills( millis() );
        m_inner_loop_idx = 0;
        m_outer_loop_idx++;
    }
    else
    {
        m_outer_loop_idx = 0;
    }
}


uint32_t 
command_rainbow::get_color_impl( pixel_strip& strip, uint8_t brightness )
{
    return 0;
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t 
command_rainbow::wheel( const pixel_strip& strip, byte wheel_pos ) 
{    
    wheel_pos = 255 - wheel_pos;

    uint32_t new_pos;
    if ( wheel_pos < 85 )
    {
        new_pos = strip.Color( 255 - wheel_pos * 3, 0, wheel_pos * 3 );
    }
    else if ( wheel_pos < 170 )
    {
        wheel_pos -= 85;
        new_pos = strip.Color( 0, wheel_pos * 3, 255 - wheel_pos * 3 );
    }
    else
    {
        wheel_pos -= 170;
        new_pos = strip.Color( wheel_pos * 3, 255 - wheel_pos * 3, 0 );
    }

    return new_pos;
}

