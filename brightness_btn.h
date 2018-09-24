#ifndef BRIGHTNESS_BTN_H
#define BRIGHTNESS_BTN_H

#include "button.h"

class brightness_btn
{
    virtual void update_brightness() = 0;
    virtual void update();
};

#endif // BRIGHTNESS_BTN_H
