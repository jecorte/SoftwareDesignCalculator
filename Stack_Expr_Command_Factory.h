#include "Stack.h"
#include "Add_Command.h"

class Stack_Expr_Command_Factory : public Expr_Command_Factory
{
public:
    Stack_Expr_Command_Factory (Stack <int> & stack_);
    virtual Number_Command * create_number_command (int num);
    virtual Add_Command * create_add_command(void);
    virtual Subtract_Command * create_subtract_command(void);
    virtual Mult_Command * create_multiply_command (void);
    virtual Div_Command * create_division_command (void);
    virtual Mod_Command * create_modulus_command (void);
private:
Stack <int> & stack_;
};