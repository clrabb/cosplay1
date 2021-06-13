#include "button_array.h"
#include <Arduino.h>

void
button_array::update_buttons()
{
    this->command_btn()->update();

    return;
}

