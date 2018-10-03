#include "button_array.h"
#include <arduino.h>

void
button_array::update_buttons()
{
    this->bright_btn()->update();
    this->command_btn()->update();

    return;
}

