#ifndef GLOBAL_DATA_H
#define GLOBAL_DATA_H

#include <arduino.h>

class g_data
{
private:
    uint8_t m_brightness;

public:
    g_data();
    uint8_t brightness() { return m_brightness; }
    void increment_brightness();

private:
    void brightness( uint8_t brightness ) { m_brightness = brightness; }


private:
    g_data( const g_data& );
    g_data& operator=( const g_data& );

};


#endif // GLOBAL_DATA_H
