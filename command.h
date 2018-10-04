#ifndef COMMAND_H
#define COMMAND_H

#include "cp_types.h"
#include "constants.h"

#ifdef __AVR__
  #include <avr/power.h>
#endif


class command
{
private:
    
public:
    command() {}
    virtual void tick() = 0;
    virtual void init() = 0;

protected: 
    uint8_t map_brightness( uint8_t absolute_brightness );

private:
    command( const command& );
    command& operator=( const command& );
};

#endif // COMMAND_H
