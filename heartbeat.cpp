#include "heartbeat.h"
#include "cp_types.h"
#include "constants.h"
#include <arduino.h>

heartbeat::heartbeat()
{
    pinMode( LED_BUILTIN, OUTPUT );
}

void
heartbeat::beat()
{
    if ( this->is_off() )
        this->off_beat();
    else
        this->on_beat();

    return;
}

unsigned long 
heartbeat::time_on()
{
    return
        ( this->is_on() )
            ? millis() - this->last_state_change_mills() 
            : 0
        ;           
}

unsigned long
heartbeat::time_off()
{
    return
        ( this->is_off() )
            ? millis() - this->last_state_change_mills() 
            : 0
        ;
}

void 
heartbeat::off_beat()
{   
    if ( this->time_off() >= MILLS_BETWEEN_HEARTBEATS )
    {
        this->turn_on();
    }

    return;
}

void
heartbeat::on_beat()
{
    if ( this->time_on() >= HEARTBEAT_LENGTH_MILLS )
    {
        this->turn_off();
    }

    return;
}

void 
heartbeat::turn_on()
{
    digitalWrite( LED_BUILTIN, HIGH );

    this->last_state_change_mills( millis() );
    return;
}

void 
heartbeat::turn_off()
{ 
    digitalWrite( LED_BUILTIN, LOW );
    this->last_state_change_mills( millis() );

    return;
}


bool
heartbeat::is_on()
{
    return digitalRead( LED_BUILTIN ) == HIGH;
}

bool
heartbeat::is_off()
{
    return !( this->is_on() );
}    
