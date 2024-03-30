#include "Array.h"
#include "Array_Base.h"
#include "Stack.h"
#include "Fixed_Array.h"
#include "Queue.h"
#include "Add_Command.h"
#include <iostream>

int main ()
{
    Array_Base<char> * a1 = new Array_Base<char>(5, 'a');
    Array_Base<char> * a2 = new Array_Base<char>(5, 'b');
    Array<char> * array1 = new Array<char>(5, 'a');
    Array<char> * array2 = new Array<char>(5, 'b');
    Stack<int> * stack = new Stack<int>();
}
