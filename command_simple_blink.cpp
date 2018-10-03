#include "command_simple_blink.h"

#include "constants.h"

command_simple_blink::command_simple_blink()
        : command(), 
{ 
    m_last_action_mills = 0; 
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

uint8_t 
command_simple_blink::increment_pixel_num()
{
    uint8_t current_pixel_num = this->current_pixel_num();
    
    uint8_t new_pixel_num = 
        ( current_pixel_num == NUM_PIXELS ) 
            ? 0 
            : current_pixel_num++
    ;

    this->current_pixel_num( new_pixel_num );
    return new_pixel_num;   
}

void
command_simple_blink::move_next_pixel()
{
    g_data& data = singleton_t< g_data >::instance();
    pixel_string& strip = this->pixel_strip();
    uint8_t pixel_num = this->increment_pixel_num();

    
    strip.clear();
    strip.setColor( this->current_pixel_num(), 
}

