#include "Expr_Command.h"
#include "Expr_Command_Factory.h"
#include "Array.h"
#include "Stack.h"
#include <iostream>
#include <sstream>
#include <string>

class Calculator
{
public:

int precedence (char op){
    if(op == '%' || op == '/' || op == '*'){
        return 2;
    }else if(op == '+' || op == '-'){
        return 1;
    }else{
        return -1;
    }
}

bool infix_to_postfix (std::string & infix,
                        Expr_Command_Factory & factory,
                        Array <Expr_Command *> & postfix) {
std::istringstream input(infix); // create a input stream parser
char token; // current token in string/stream
Expr_Command * cmd = 0; // created command object
Stack <Expr_Command*> temp;
while (!input.eof ()) {
    input >> token;
   // if (token == '+')
       // cmd = factory.create_add_command ();
    //else if (token == '-')
      //  cmd = factory.create_subtract_command ();
// ...
// handle the command based on infix-to-postfix algorithm
}
return true;
};
};
