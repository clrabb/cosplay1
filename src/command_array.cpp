#include "command_array.h"
#include "command_simple_blink.h"
#include "command_all_green.h"
#include "command_all_blue.h"
#include "command_all_red.h"
#include "command_rainbow.h"

command_array::command_array()
{
    this->m_commands[ 0 ] = new command_simple_blink();
    this->m_commands[ 1 ] = new command_all_green();
    this->m_commands[ 2 ] = new command_all_blue();
    this->m_commands[ 3 ] = new command_all_red();
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
    ( this->current_command_index() == NUM_COMMANDS -1 )
        ? this->current_command_index( 0 )
        : this->current_command_index( this->current_command_index() + 1 )
    ;

    (this->m_commands[ this->current_command_index() ])->init();
}

void
command_array::tick()
{
    command* com = m_commands[ this->current_command_index() ];
    com->tick();
}

