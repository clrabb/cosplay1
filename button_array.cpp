#include "button_array.h"

void
button_array::update_buttons()
{
    this->bright_up_btn()->update();
    this->bright_dn_btn()->update();
    //this->prog_sel_right_btn()->update();
    //this->prog_sel_left_btn()->update();
}

