#ifndef COMMAND_SIMPLE_BLINK_H
#define COMMAND_SIMPLE_BLINK_H

#include "command.h"
#include "cp_types.h"
#include <stdint.h>

class command_simple_blink : command
{
private:
    uint32_t m_last_action_mills;
    
public:
    command_simple_blink();
    virtual void tick();

private:
    uint32_t last_action_mills() { return m_last_action_mills; }
    void last_action_mills( uint32_t mills ) { m_last_action_mills = mills; }

private:
    command_simple_blink( const command_simple_blink& );
    command_simple_blink& operator=( const command_simple_blink& );
};

#endif // COMMAND_SIMPLE_BLINK_H
