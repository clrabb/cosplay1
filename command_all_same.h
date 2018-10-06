#ifndef COMMAND_ALL_SAME_H
#define COMMAND_ALL_SAME_H

#include "command.h"

class command_all_same : public command
{
private:
    uint32_t m_last_color;
    uint32_t last_color() { return m_last_color; }
    void last_color( uint32_t color ) { m_last_color = color; }   
    
public:
    command_all_same() {}
    
    virtual void tick();
    virtual void init();


private:
    command_all_same( const command_all_same& );
    command_all_same& operator=( const command_all_same& );
};

#endif // COMMAND_ALL_SAME_H
