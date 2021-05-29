#ifndef BUTTON_H
#define BUTTON_H

#include "button_state.h"

class button
{
private:
    short m_pin;
    button_state* m_current_state;
    button_state* m_btn_unpressed;
    button_state* m_btn_pressed;
    button_state* m_btn_latched;
    
public:
    button( short pin );
    short pin() { return m_pin; }

    button_state* current_state() { return m_current_state; }
    void current_state( button_state* state ) { state->reset_state(); m_current_state = state; }

    button_state* unpressed_state() { return m_btn_unpressed; }
    void unpressed_state( button_state* state ) { state->reset_state(); m_btn_unpressed= state; }

    button_state* pressed_state() { return m_btn_pressed; }
    void pressed_state( button_state* state ) { state->reset_state(); m_btn_pressed = state; }

    button_state* latched_state() { return m_btn_latched; }
    void latched_state( button_state* state ) { state->reset_state(); m_btn_latched = state; }

    //------------------------------------------
    // 
    // Virtual methods
    //
    //------------------------------------------
    virtual void update();
    virtual void pressedFromUnpressed( button_state* statee );
    virtual void pressedFromUnpressedImpl( button_state* state ) {}
    
    virtual void pressedFromPressed( button_state* state );
    virtual void pressedFromPressedImpl( button_state* state ) {}
    
    virtual void unpressedFromUnpressed( button_state* state );
    virtual void unpressedFromUnpressedImpl( button_state* state ) {}
    
    virtual void unpressedFromPressed( button_state* state );
    virtual void unpressedFromPressedImpl( button_state* state ) {}
        
    //------------------------------------------
    // 
    // Testing
    //
    //------------------------------------------
    bool is_unpressed();
    bool is_pressed();
    bool is_latched();

private:
    button( const button& );
    button& operator=( const button& );
    
};

#endif // BUTTON_H
