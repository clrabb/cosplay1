#ifndef COMMAND_BTN_H
#define COMMAND_BTN_H

#include "button.h"

class command_btn : public button
{
public:
    command_btn( short pin );
    virtual void pressedFromUnpressedImpl( button_state* btn_state );
    virtual void pressedFromPressedImpl( button_state* btn_state );
    virtual void unpressedFromUnpressedImpl( button_state* btn_state );
    virtual void unpressedFromPressedImpl( button_state* btn_state );

private:
    command_btn( const command_btn& );
    command_btn& operator=( const command_btn& );
    
};

#endif // COMMAND_BTN_H
