#include "bright_btn.h"
#include "singleton_t.h"
#include "g_data.h"

bright_btn::bright_btn( unsigned short pin )
       : button( pin )
    {}

void
bright_btn::update()
{
    button::update();
}

void
bright_btn::updateFromPressed()
{   
}

void 
bright_btn::updateFromUnpressed()
{
}

void bright_btn::updateFromLatched()
{
}

