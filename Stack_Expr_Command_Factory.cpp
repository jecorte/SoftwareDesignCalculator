#include "Stack.h"
#include "Add_Command.h"


class Stack_Expr_Command_Factory : public Expr_Command_Factory
{
public:
    Stack_Expr_Command_Factory (Stack <int> & stack_);
    // returns add command
    Add_Command * Stack_Expr_Command_Factory::create_add_command (void){
    return new Add_Command (stack_);
    }
    //returns subtract command
    Subtract_Command * Stack_Expr_Command_Factory::create_subtract_command (void){
    return new Subtract_Command (stack_);
    }
    //returns multiplication command
    Mult_Command * Stack_Expr_Command_Factory::create_mult_command (void){
    return new Mult_Command (stack_);
    }
    //returns division command
    Div_Command * Stack_Expr_Command_Factory::create_div_command (void){
    return new Div_Command (stack_);
    }
    //returns modulus command
    Mod_Command * Stack_Expr_Command_Factory::create_mod_command (void){
    return new Mod_Command (stack_);
    }


private:
Stack <int> & stack_;
};