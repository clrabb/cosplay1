#ifndef COMMAND_ALL_GREEN_H
#define COMMAND_ALL_GREEN_H

#include "command_all_same.h"
#include "cp_types.h"

class command_all_green : public command_all_same
{
    
public:
    command_all_green() {}

protected:
    virtual uint32_t get_color_impl( pixel_strip& strip, uint8_t brightness );

private:
    command_all_green( const command_all_green& );
    command_all_green& operator=( const command_all_green& );
};

#endif // COMMAND_ALL_GREEN_H
