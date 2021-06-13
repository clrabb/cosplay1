#ifndef COMMAND_FOLLOW_1_H
#define COMMAND_FOLLOW_1_H

#include "command_all_same.h"
#include "cp_types.h"


class command_follow_1 : public command
{
public:
    command_follow_1();
    virtual void init() override;
    virtual void tick() override;


protected:
    virtual uint32_t get_color_impl( pixel_strip& strip, uint8_t mapped_brightness ) override;


private:
    command_follow_1( const command_follow_1& );
    command_follow_1& operator=( const command_follow_1& );
};

#endif // COMMAND_FOLLOW_1_H
