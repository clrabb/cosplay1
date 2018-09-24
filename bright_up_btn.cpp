#include "bright_up_btn.h"
#include "singleton_t.h"
#include "g_data.h"

bright_up_btn::bright_up_btn( unsigned short pin )
       : button( pin )
    {}

void
bright_up_btn::update()
{
    g_data& gd = singleton_t< g_data >::instance();
    gd.increment_brightness();

    return;
}


