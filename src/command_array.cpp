#include "command_array.h"
#include "command_simple_blink.h"
#include "command_all_green.h"
#include "command_all_blue.h"
#include "command_all_red.h"
#include "command_rainbow.h"
#include <Arduino.h>

command_array::command_array()
{
    this->m_commands[ 0 ] = new command_simple_blink();
    this->m_commands[ 1 ] = new command_all_green();
    this->m_commands[ 2 ] = new command_all_blue();
    this->m_commands[ 3 ] = new command_all_red();
    this->m_current_command_index = 0;
    this->m_last_change_mills     = millis();
}

command*
command_array::current_command()
{
    return this->m_commands[ this->current_command_index() ];
}

void
command_array::change_to_command( uint8_t index )
{
    this->current_command_index( index );
    this->current_command()->init();
    this->last_change_mills( millis() );
}

void
command_array::increment_command()
{

    uint8_t next_command_index = 
        ( this->current_command_index() == NUM_COMMANDS -1 )
            ? 0
            : this->current_command_index() + 1 
    ;

    this->change_to_command( next_command_index );
}
 

void
command_array::change_to_random_command()
{
    long random_index = random( NUM_COMMANDS );
    this->change_to_command( random_index ); 
}

void
command_array::tick()
{
    if ( this->mills_since_last_change() > MILLS_BETWEEN_CHANGE )
    {
        this->change_to_random_command();
    }

    command* com = m_commands[ this->current_command_index() ];
    com->tick();
}

unsigned long
command_array::mills_since_last_change()
{
    return millis() - this->last_change_mills();
}
