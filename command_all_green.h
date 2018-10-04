#ifndef COMMAND_ALL_GREEN_H
#define COMMAND_ALL_GREEN_H

#include "command.h"

class command_all_green : public command
{
    
public:
    command_all_green() {}
    virtual void tick();
    virtual void init();

private:
    command_all_green( const command_all_green& );
    command_all_green& operator=( const command_all_green& );
};

#endif // COMMAND_ALL_GREEN_H
