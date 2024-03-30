#include "Stack.h"
#include "Expr_Command.h"
class Mult_Command : public Expr_Command {
public:
Mult_Command (Stack <int> & s) : s_ (s) { }
virtual void execute (void){
    int n2 = s_.top ();
    s_.pop();
    int n1 = s_.top ();
    s_.pop();
    s_.push (n1 * n2);
}
private:
Stack <int> & s_;
};