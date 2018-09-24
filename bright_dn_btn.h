#ifndef BRIGHT_DN_BTN_H
#define BRIGHT_DN_BTN_H

#include "brightness_btn.h"

class bright_dn_btn : public button
{
public:
    bright_dn_btn( unsigned short pin );

public:
    virtual void update_brightness();
    
private:
    bright_dn_btn( const bright_dn_btn& );            // COPY CTOR
    bright_dn_btn& operator=( const bright_dn_btn& ); // ASSIGNMENT OP
 

};

#endif // BRIGHT_DN_BTN_H
