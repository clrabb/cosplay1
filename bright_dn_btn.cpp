#include "bright_dn_btn.h"
#include "g_data.h"
#include "singleton_t.h"

bright_dn_btn::bright_dn_btn( unsigned short pin )
    : button( pin ) 
    {}

void
bright_dn_btn::update_brightness()
{
    g_data& gd = singleton_t< g_data >::instance();
    gd.decrement_brightness();

    return;
}

    
