#ifndef _EXPR_COMMAND_FACTORY_H_
#define _EXPR_COMMAND_FACTORY_H_

class Expr_Command_Factory{
    public:
    virtual ~Expr_Command_Factory (void);
    virtual Number_Command * create_number_command (int num);
    virtual Add_Command * create_add_command (void);
    virtual Subtract_Command * create_subtract_command (void);
    virtual Mult_Command * create_multiply_command (void);
    virtual Div_Command * create_division_command (void);
    virtual Mod_Command * create_modulus_command (void);
};

#include "Number_Command.h"

#endif