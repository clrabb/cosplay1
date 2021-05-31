#include "button.h"
#include "cp_types.h"
#include "button_state.h"
#include <Arduino.h>

button::button( short pin )
    :m_pin( pin )
{
    pinMode( pin, INPUT_PULLUP );

    this->pressed_state(   new button_state_pressed()   );
    this->unpressed_state( new button_state_unpressed() );

    this->current_state( this->unpressed_state() );
}

void
button::update()
{
    this->current_state()->update( this );
}

bool
button::is_pressed()
{
    return this->current_state()->is_pressed();
}

bool
button::is_unpressed()
{
    return this->current_state()->is_unpressed();
}

void
button::pressedFromUnpressed( button_state* state )
{
    this->pressedFromUnpressedImpl( state );
    this->current_state( this->pressed_state() );

    return;
}


void 
button::pressedFromPressed( button_state* state )
{
    this->pressedFromPressedImpl( state );

    return;
}

void
button::unpressedFromPressed( button_state* state )
{
    this->unpressedFromPressedImpl( state );
    this->current_state( this->unpressed_state() );

     return;
}

void
button::unpressedFromUnpressed( button_state* state )
{
    this->unpressedFromUnpressedImpl( state );   
}


