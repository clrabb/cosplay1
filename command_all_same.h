#ifndef COMMAND_ALL_SAME_H
#define COMMAND_ALL_SAME_H

#include "command.h"

class command_all_same : public command
{
    
public:
    command_all_same() {}
    virtual void tick();
    virtual void init();
    virtual uint32_t get_color() = 0;

private:
    command_all_same( const command_all_same& );
    command_all_same& operator=( const command_all_same& );
};

#endif // COMMAND_ALL_SAME_H
