#ifndef BUTTON_ARRAY_H
#define BUTTON_ARRAY_H

#include "button.h"

class button_array
{
private:
    button* m_bright_up_btn;
    button* m_bright_dn_btn;
    button* m_prog_sel_right_btn;
    button* m_prog_sel_left_btn;

public:
    button_array() {}

    button* bright_up_btn() { return m_bright_up_btn; }
    void bright_up_btn( button* btn ) { m_bright_up_btn = btn; }
    
    button* bright_dn_btn() { return m_bright_dn_btn; }
    void bright_dn_btn( button* btn ) { m_bright_dn_btn = btn; }

    button* prog_sel_right_btn() { return m_prog_sel_right_btn; }
    void prog_sel_right_btn( button* btn ) { m_prog_sel_right_btn = btn; }

    button* prog_sel_left_btn() { return m_prog_sel_left_btn; }
    void prog_sel_left_btn( button* btn ) { m_prog_sel_left_btn = btn; }

    void update_buttons();

private:
    button_array( const button_array& );                // copy ctor
    button_array& operator=( const button_array& );     // assignment op
    
};

#endif
