#include "Expr_Command.h"
#include "Number_Command.h"
#include "Stack.h"

class Num_Command : public Expr_Command {
public:
Num_Command (Stack <int> & s, int n)
: s_ (s), n_ (n) { }
void execute (void){
    s_.push (this->n_);
}
private:
Stack <int> & s_;
int n_;
};
