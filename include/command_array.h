#ifndef COMMAND_ARRAY_H
#define COMMAND_ARRAY_H

#include "command.h"


class command_array
{
private:
    static const short CMD_SIMPLE_BLINK_IDX = 0;
    static const short CMD_ALL_GREEN_IDX    = 1;
    static const short CMD_ALL_BLUE_IDX     = 2;
    static const short CMD_ALL_RED_IDX      = 3;
    static const short CMD_FOLLOW_1_IDX     = 4;
    
    static const short NUM_COMMANDS         = 4;

private:
    uint8_t         m_current_command_index;
    command*        m_commands[ NUM_COMMANDS ];
    unsigned long   m_last_change_mills;

    uint8_t current_command_index() { return m_current_command_index; }
    void current_command_index( uint8_t index ) { m_current_command_index = index; }
    command* current_command();
    void change_to_command( uint8_t index );
    void init();
    
public:
    command_array();
    void tick();
    void increment_command();
    unsigned long mills_since_last_change();

private:
    unsigned long last_change_mills() { return this->m_last_change_mills; }
    void last_change_mills( unsigned long mills ) { this->m_last_change_mills = mills; }
    void change_to_random_command();
    void reset_command();

private:
    command_array( const command_array& );
    command_array& operator=( const command_array& );
};

#endif // COMMAND_ARRAY_H
