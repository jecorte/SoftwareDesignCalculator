// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
#include "Stack.h"
#define def_size_ 10
//
// Stack
//constructor
template <typename T>
Stack <T>::Stack (void):
stack_array_(def_size_),
size_(def_size_)
{
   
}

//
// Stack
//copy constructor
template <typename T>
Stack <T>::Stack (const Stack & stack):
    stack_array_(def_size_),
    size_(def_size_)
{
        
        // COMMENT Could you not just use the assignment operator on
        // the array class to copy over the elements?!
        // 
        // FIX Used the assignment operator to copy over the elements.

	stack_array_ = stack;
}
//
// ~Stack
//destructor
template <typename T>
Stack <T>::~Stack (void)
{
   delete[] this->data_;
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
    size_ += 1;
    stack_array_.resize(size_);
    stack_array_[size_- 1] = element;
}
//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
    if(stack_array_.size() == 0){
        throw empty_exception("Stack is empty, can't pop.");
    }
    size_ -= 1;
    stack_array_.resize(size_);
}


//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    if(this = &rhs){
        return *this;
    }
    
    // COMMENT Could you not just use the assignment operator on
    // the array class to copy over the elements?!
    // 
    // FIX Used the assignment operator to copy over the elements.

    stack_array_ = rhs;

}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    stack_array_.resize(0);
    stack_array_.resize(1);
}