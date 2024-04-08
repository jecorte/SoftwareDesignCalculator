class Expr_Command {
public:
virtual void execute (void) = 0;
int precedence (char op){
    if(op == '%' || op == '/' || op == '*'){
        return 2;
    }else if(op == '+' || op == '-'){
        return 1;
    }else{
        return -1;
    }
}

};
