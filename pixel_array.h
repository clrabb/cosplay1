#ifndef PIXEL_ARRAY_H
#define PIXEL_ARRAY_H

#include "cp_types.h"

class pixel_array
{
public:
    pixel_array( uint8_t num_pixels, const short pin, int parms );

    // Decorated
    //
    uint16_t num_pixels();
    void show() { this->m_pixel_strip->show(); }
    void begin() { this->m_pixel_strip->begin(); }
    
    // Lighting effects
    //
    void rainbow_all_same( uint8_t wait );

private:
    uint32_t wheel( byte pos );

private:
    pixel_strip* m_pixel_strip;

private:
    pixel_array( const pixel_array& );
    const pixel_array& operator=( const pixel_array& ); 
};


#endif //PIXEL_ARRAY_H
