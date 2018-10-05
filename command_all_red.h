#ifndef COMMAND_ALL_RED_H
#define COMMAND_ALL_RED_H

#include "command_all_same.h"

class command_all_red : public command_all_same
{
    
public:
    command_all_red() {}
    virtual uint32_t get_color();

private:
    command_all_red( const command_all_red& );
    command_all_red& operator=( const command_all_red& );
};

#endif // COMMAND_ALL_RED_H
