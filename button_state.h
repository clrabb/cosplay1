#ifndef BUTTON_STATE_H
#define BUTTON_STATE_H

class button;


class button_state
{

public:
    button_state() {}
    
    virtual void button_pressed( button* btn )   = 0;
    virtual void button_unpressed( button* btn ) = 0;
    virtual void reset_state() {}
    virtual bool is_unpressed() = 0;
    virtual bool is_pressed()   = 0;
    virtual const char* name()  = 0;
    void update( button* btn );

private:
    button_state( button_state& );
    button_state& operator=( button_state& );
};

class button_state_unpressed : public button_state
{    
public:
    button_state_unpressed() {}

    virtual void button_pressed( button* btn );
    virtual void button_unpressed( button* btn );
    virtual bool is_unpressed() { return true;  }
    virtual bool is_pressed()   { return false; }
    virtual const char* name() { return "Unpressed"; }
};

class button_state_pressed: public button_state
{
private:
    bool m_first_pressed;

private:
    bool    is_first_pressed() { return m_first_pressed; }
    void    is_first_pressed( bool pressed ) { m_first_pressed = pressed; }
  
     
public:    
    button_state_pressed();
    virtual void button_pressed( button* btn );
    virtual void button_unpressed( button* btn );
    virtual bool is_unpressed() { return false; }
    virtual bool is_pressed()   { return true;  }
    virtual const char* name() { return "Pressed"; }
    virtual void reset_state() override;

private:
    button_state_pressed( button_state_pressed& );
    button_state_pressed& operator=( button_state_pressed& );
};


#endif // BUTTON_STATE_H
