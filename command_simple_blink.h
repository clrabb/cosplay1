#ifndef COMMAND_SIMPLE_BLINK_H
#define COMMAND_SIMPLE_BLINK_H

#include "command.h"
#include "cp_types.h"
#include <stdint.h>

class command_simple_blink : command
{
private:
    uint32_t m_last_action_mills;
    uint8_t  m_current_pixel_num;
    
public:
    command_simple_blink();
    virtual void tick();

private:
    uint32_t last_action_mills() { return m_last_action_mills; }
    void last_action_mills( uint32_t mills ) { m_last_action_mills = mills; }
    uint8_t current_pixel_num() { return m_current_pixel_num; }
    void current_pixel_num( uint8_t num ) { m_current_pixel_num = num; }
    void move_next_pixel();
    uint8_t increment_pixel_num();

private:
    command_simple_blink( const command_simple_blink& );
    command_simple_blink& operator=( const command_simple_blink& );
};

#endif // COMMAND_SIMPLE_BLINK_H
