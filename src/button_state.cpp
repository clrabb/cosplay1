#include "button_state.h"
#include "button.h"
#include "constants.h"
#include "singleton_t.h"
#include "Arduino.h"

/* -------------------- BASE -------------------- */

void
button_state::update( button* btn )
{
    bool is_high = digitalRead( btn->pin() ) == HIGH;

    if ( is_high )
        this->button_pressed( btn );
    else   
        this->button_unpressed( btn );

    return;
}

/* -------------------- UNPRESSED -------------------- */

void
button_state_unpressed::button_pressed( button* btn )
{
    btn->pressedFromUnpressed( this );
    return;
}

void
button_state_unpressed::button_unpressed( button* btn )
{
   btn->unpressedFromUnpressed( this );
}

/* -------------------- PRESSED -------------------- */

button_state_pressed::button_state_pressed()
{    
    this->is_first_pressed( true );
}

void
button_state_pressed::reset_state()
{
    button_state::reset_state();
    this->is_first_pressed( true );
    return;
}

void
button_state_pressed::button_pressed( button* btn )
{
    if ( this->is_first_pressed() )
    {
        this->is_first_pressed( false );
        btn->pressedFromPressed( this );
    }

    return;
}

void
button_state_pressed::button_unpressed( button* btn )
{
    btn->unpressedFromPressed( this );
}



