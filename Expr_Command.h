#ifndef _EXPR_COMMAND_H_
#define _EXPR_COMMAND_H_

class Expr_Command{
    public:
    void execute (void);
    int precedence(char op);
};

#include "Number_Command.h"

#endif