#ifndef BUTTON_ARRAY_H
#define BUTTON_ARRAY_H

#include "button.h"

class button_array
{
private:
    button* m_command_btn;

public:
    button_array() {}

    button* command_btn() { return m_command_btn; }
    void command_btn( button* btn ) { m_command_btn = btn; }

    void update_buttons();

private:
    button_array( const button_array& );                // copy ctor
    button_array& operator=( const button_array& );     // assignment op
    
};

#endif
