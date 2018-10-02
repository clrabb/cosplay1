#include "bright_btn.h"
#include "singleton_t.h"
#include "g_data.h"

bright_btn::bright_btn( unsigned short pin )
       : button( pin )
    {}

void
bright_btn::pressedFromUnpressedImpl( button_state* state )
{    
    g_data& gd = singleton_t< g_data >::instance();
    gd.increment_brightness();

    return;
}


void
bright_btn::pressedFromPressedImpl( button_state* state )
{
    return;   
}

void 
bright_btn::unpressedFromUnpressedImpl( button_state* state )
{
    return;
}


void 
bright_btn::unpressedFromPressedImpl( button_state* state )
{
    return;
}

