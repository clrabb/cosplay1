#include "command_simple_blink.h"
#include "constants.h"
#include "g_data.h"
#include "singleton_t.h"

command_simple_blink::command_simple_blink()
        : command()
{ 
    m_last_action_mills = 0; 
    m_current_pixel_num = 0;
}

void
command_simple_blink::init()
{
    pixel_strip& strip = singleton_t< pixel_strip >::instance();
    strip.clear();
    strip.show();
    this->last_action_mills( millis() );
    this->current_pixel_num ( 0 );
    this->tick();
}

void
command_simple_blink::tick()
{
    uint32_t now = millis();
    uint32_t interval = now - this->last_action_mills();

    if ( interval > SIMPLE_BLINK_DURATION_MILLS )
    {
        this->move_next_pixel();
        this->last_action_mills( millis() );
    }
    
    return;
}

void 
command_simple_blink::increment_pixel_num()
{
    uint8_t current_pixel_num = this->current_pixel_num();
    
    uint8_t new_pixel_num = 
        ( current_pixel_num == NUM_PIXELS ) 
            ? 0
            : ++current_pixel_num
    ;

    this->current_pixel_num( new_pixel_num );

    return new_pixel_num;   
}

void
command_simple_blink::turn_off_pixel( uint8_t num )
{
    pixel_strip& strip = singleton_t< pixel_strip >::instance();
    strip.setPixelColor( num, 0 );
    strip.show();
}

uint32_t
command_simple_blink::get_color_impl( pixel_strip& strip, uint8_t brightness )
{
    return strip.Color( brightness, brightness, brightness );
}

void
command_simple_blink::move_next_pixel()
{
    pixel_strip& strip      = singleton_t< pixel_strip >::instance();

    this->turn_off_pixel( this->current_pixel_num() );    
    this->increment_pixel_num();    
    strip.setPixelColor( this->current_pixel_num(), this->get_color() );
    
    strip.show();
}

