#ifndef COMMAND_ALL_BLUE_H
#define COMMAND_ALL_BLUE_H

#include "command_all_same.h"

class command_all_blue : public command_all_same
{
    
public:
    command_all_blue() {}
    virtual uint32_t get_color();

private:
    command_all_blue( const command_all_blue& );
    command_all_blue& operator=( const command_all_blue& );
};

#endif // COMMAND_ALL_BLUE_H
