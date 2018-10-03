#ifndef COMMAND_H
#define COMMAND_H

#include "cp_types.h"
#include "constants.h"
#include "led.h"


#ifdef __AVR__
  #include <avr/power.h>
#endif


class command
{
private
    pixel_strip& m_pixel_strip;
    
public:
    command() : m_pixel_strip( NUM_PIXELS, PIXEL_ARRAY_PIN, NEO_GRB + NEO_KHZ800 ) {}
    virtual void tick() = 0;

protected: 
    pixel_strip& pixel_strip() { return m_pixel_strip; }
    uint8_t map_brightness();

private:
    command( const command& );
    command& operator=( const command& );
};

#endif // COMMAND_H
