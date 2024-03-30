// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
//
#include "Fixed_Array.h"
// Fixed_Array
//
template <typename T>
Fixed_Array <T>::Fixed_Array (void):
data_ (new T[max_size_]),
cur_size_(0)
{

}

//
// Fixed_Array
//
template <typename T>
Fixed_Array <T>::Fixed_Array (const Fixed_Array & arr):
    data_ (new char[cur_size_]),
	cur_size_(arr.cur_size_)
{
	for (size_t i = 0; i < this->cur_size_; i++) {
		this->data_[i] = arr.data_[i];
	}
	
}

//
// ~Fixed_Array
//
template <typename T>
Fixed_Array <T>::~Fixed_Array (void)
{
    delete[] this->data_;
}

//
// operator =
//
template <typename T>
const Fixed_Array <T> & Fixed_Array <T>::operator = (const Fixed_Array <T> & rhs)
{
	if(this = &rhs){
        return *this;
    }
    this->cur_size_ = rhs.cur_size_;

    for (size_t i = 0; i < this->cur_size_; i++) {
		this->data_[i] = rhs.data_[i];
	}

	return *this;
}
