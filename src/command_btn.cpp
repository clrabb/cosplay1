#include "command_btn.h"
#include "command_array.h"
#include "singleton_t.h"

command_btn::command_btn( short pin )
    : button( pin )
{
}

void
command_btn::pressedFromUnpressedImpl( button_state* state )
{
    command_array& comm_array = singleton_t< command_array >::instance();
    comm_array.increment_command();
}

void
command_btn::unpressedFromUnpressedImpl( button_state* state )
{
}

void
command_btn::pressedFromPressedImpl( button_state* state )
{
}

void
command_btn::unpressedFromPressedImpl( button_state* state )
{
}

