#ifndef BRIGHT_UP_BUTTON_H
#define BRIGHT_UP_BUTTON_H

#include "button.h"

class bright_up_btn : public button
{
public:
    bright_up_btn( unsigned short pin );

public:
    virtual void update();

    
private:
    bright_up_btn( const bright_up_btn& ); // COPY CTOR
    bright_up_btn& operator=( const bright_up_btn& ); // ASSIGNMENT OP  
};

#endif // BRIGHT_UP_BUTTON_H
