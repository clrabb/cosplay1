#ifndef COMMAND_SIMPLE_BLINK_H
#define COMMAND_SIMPLE_BLINK_H

#include "command.h"
#include "cp_types.h"
#include <stdint.h>

class command_simple_blink : public command
{
private:
    uint32_t m_last_action_mills;
    uint8_t  m_current_pixel_num;
    
public:
    command_simple_blink();
    virtual void tick();
    virtual void init();

protected:
    virtual uint32_t get_color_impl( pixel_strip& strip, uint8_t brightness );

private:
    uint32_t last_action_mills() { return m_last_action_mills; }
    void last_action_mills( uint32_t mills ) { m_last_action_mills = mills; }
    uint8_t current_pixel_num() { return m_current_pixel_num; }
    void current_pixel_num( uint8_t num ) { m_current_pixel_num = num; }
    void move_next_pixel();
    void increment_pixel_num();
    void turn_off_pixel( uint8_t num );

private:
    command_simple_blink( const command_simple_blink& );
    command_simple_blink& operator=( const command_simple_blink& );
};

#endif // COMMAND_SIMPLE_BLINK_H
