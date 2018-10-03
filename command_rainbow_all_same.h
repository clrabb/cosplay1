#ifndef COMMAND_RAINBOW_ALL_SAME_H
#define COMMAND_RAINBOW_ALL_SAME_H

#include "command.h"
#include "stdint.h"

class command_rainbow_all_same : command
{
private:
    uint16_t m_outer_idx = 0;
    uint16_t m_inner_idx = 0;   

    
public:
    command_rainbow_all_same() {}
    virtual void tick();

private:
    command_rainbow_all_same( const command_rainbow_all_same& );
    command_rainbow_all_same& opeator=( command_rainbow_all_same& );    
};

#endif // COMMAND_RAINBOW_ALL_SAME_H
