#ifndef BRIGHT_UP_BUTTON_H
#define BRIGHT_UP_BUTTON_H

#include "button.h"

class bright_btn : public button
{
public:
    bright_btn( unsigned short pin );

public:
    virtual void update();
    virtual void updateFromPressed();
    virtual void updateFromUnpressed();
    virtual void updateFromLatched();

    
private:
    bright_btn( const bright_btn& ); // COPY CTOR
    bright_btn& operator=( const bright_btn& ); // ASSIGNMENT OP  
};

#endif // BRIGHT_UP_BUTTON_H
