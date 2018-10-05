#ifndef COMMAND_RAINBOW_H
#define COMMAND_RAINBOW_H

#include "command.h"

class command_rainbow : public command
{
public:
    command_rainbow() {}


private:
    uint32_t wheel( byte wheel_pos );

private:
    command_rainbow( const command_rainbow& );
    command_rainbow& operator=( const command_rainbow& );
    
};

#endif //COMMAND_RAINBOW_H



