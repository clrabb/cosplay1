#include "command_array.h"
#include "command_simple_blink.h"

command_array::command_array()
{
    this->m_commands[ 0 ] = new command_simple_blink();
    this->m_current_command_index = 0;
}

void
command_array::change_to_command( uint8_t index )
{
    this->current_command_index( index );
}

void
command_array::increment_command()
{
    ( this->current_command_index() == NUM_COMMANDS )
        ? this->current_command_index( 0 )
        : this->current_command_index( this->current_command_index() + 1 )
    ;
}

void
command_array::tick()
{
    command* com = m_commands[ this->current_command_index() ];
    com->tick();
}

