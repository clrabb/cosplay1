#ifndef COMMAND_H
#define COMMAND_H

#include "cp_types.h"
#include "constants.h"
#include <stdint.h>

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
    virtual uint32_t get_color();
    virtual uint32_t get_color_impl( pixel_strip& strip, uint8_t mapped_brightness ) = 0;
    virtual uint8_t map_brightness();
    

private:
    command( const command& );
    command& operator=( const command& );
};

#endif // COMMAND_H
