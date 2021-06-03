#ifndef GLOBAL_DATA_H
#define GLOBAL_DATA_H

#include <Arduino.h>

class g_data
{
private:
    uint8_t m_absolute_brightness;

public:
    g_data();
    //uint8_t absolute_brightness() { return m_absolute_brightness; }
    uint8_t absolute_brightness() { return 1; }
    
    void increment_absolute_brightness();

private:
    void absolute_brightness( uint8_t brightness ) { m_absolute_brightness = brightness; }


private:
    g_data( const g_data& );
    g_data& operator=( const g_data& );

};


#endif // GLOBAL_DATA_H
