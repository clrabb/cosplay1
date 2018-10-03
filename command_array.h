#ifndef COMMAND_ARRAY_H
#define COMMAND_ARRAY_H

#include "command.h"

class command_array
{
private:
    uint8_t m_current_command_index;
    command* m_commands[ NUM_COMMANDS ];

    uint8_t current_command_index() { return m_current_command_index; }
    void current_command_index( uint8_t index ) { m_current_command_index = index; }
    void change_to_command( uint8_t index );
    void init();
    
public:
    command_array();
    void tick();
    void increment_command();

private:
    command_array( const command_array& );
    command_array& operator=( const command_array& );
};

#endif // COMMAND_ARRAY_H
