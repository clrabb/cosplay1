#ifndef PIXEL_ARRAY_H
#define PIXEL_ARRAY_H

#include "constants.h"
#include "types.h"

class pixel_array
{
public:
    pixel_array( uint8_t num_pixels );

private:
    pixel_strip* m_pixels;

private:
    pixel_array( const pixel_array& );
    const pixel_array& operator=( const pixel_array& ); 
};


#endif //PIXEL_ARRAY_H
