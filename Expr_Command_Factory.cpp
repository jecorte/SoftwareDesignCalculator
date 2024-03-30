#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Expr_Command.h"
#include "Mult_Command.h"
#include "Div_Command.h"
#include "Mod_Command.h"
class Expr_Command_Factory
{
public:
    virtual ~Expr_Command_Factory (void) = 0;
    virtual Number_Command * create_number_command (int num) = 0;
    virtual Add_Command * create_add_command (void) = 0;
    virtual Subtract_Command * create_subtract_command (void) = 0;
    virtual Mult_Command * create_multiply_command (void) = 0;
    virtual Div_Command * create_division_command (void) = 0;
    virtual Mod_Command * create_modulus_command (void) = 0;

private:
    // prevent the following operations
    Expr_Command_Factory (const Expr_Command_Factory &);
    const Expr_Command_Factory & operator = (const Expr_Command_Factory &);
};