#ifndef COMMAND_RAINBOW_H
#define COMMAND_RAINBOW_H

#include "command.h"
#include "cp_types.h"

class command_rainbow : public command
{
private:
    uint16_t m_outer_loop_idx;
    uint16_t m_inner_loop_idx;
    uint32_t m_start_wait_mills;
    
    
public:
    command_rainbow();
    virtual void tick();
    virtual void init();

protected:
    virtual uint32_t get_color_impl( pixel_strip& strip, uint8_t brightness );

private:
    uint32_t wheel( const pixel_strip& strip, byte wheel_pos );    
    uint32_t start_wait_mills() { return m_start_wait_mills; }
    void start_wait_mills( uint32_t mills ) { m_start_wait_mills = mills; }
    boolean is_loop_delay_over();
    boolean is_loop_delay_not_over();
    void inner_loop_tick( pixel_strip& strip );
    void outer_loop_tick( pixel_strip& strip );

private:
    command_rainbow( const command_rainbow& );
    command_rainbow& operator=( const command_rainbow& );
    
};

#endif //COMMAND_RAINBOW_H



