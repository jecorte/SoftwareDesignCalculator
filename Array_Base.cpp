#include "Array_Base.h"
#include <stdexcept>         // for std::out_of_bounds exception

//
// Array_Base
//basic constructor
template <typename T>
Array_Base <T>::Array_Base (void):
data_ (new T[cur_size_]),
cur_size_(0)
{

}

//
// Array_Base (size_t)
//constructor with length
template <typename T>
Array_Base <T>::Array_Base (size_t length):
data_ (new T[cur_size_]),
cur_size_(length)
{
    
}

//
// Array_Base (size_t, char)
//fills the Array_Base with whatever T is
template <typename T>
Array_Base <T>::Array_Base (size_t length, T fill):
Array_Base(length)
{
    	for (size_t i = 0; i < cur_size_; i++) {
		data_[i] = fill;
	}
}

//
// Array_Base (const Array_Base &)
//copy constructor
template <typename T>
Array_Base <T>::Array_Base (const Array_Base & Array_Base):
    data_ (new char[cur_size_]),
	cur_size_(Array_Base.cur_size_)
{
	for (size_t i = 0; i < cur_size_; i++) {
		data_[i] = Array_Base.data_[i];
	}
}

//
// ~Array_Base
//destructor
template <typename T>
Array_Base <T>::~Array_Base (void)
{
    delete[] this->data_;
}

//
// operator =
//
template <typename T>
const Array_Base <T> & Array_Base <T>::operator = (const Array_Base & rhs)
{
    if(this = &rhs){
        return *this;
    }
    cur_size_ = rhs.cur_size_;

    for (size_t i = 0; i < cur_size_; i++) {
		data_[i] = rhs.data_[i];
	}

	return *this;
}

//
// operator []
//
template <typename T>
T & Array_Base <T>::operator [] (size_t index)
{
    if (index > cur_size_) {
		throw std::out_of_range("Index out of range");
	}
	else {
		return data_[index];
	}
}

//
// operator [] 
//
template <typename T>
const T & Array_Base <T>::operator [] (size_t index) const
{
    if (index > cur_size_) {
		throw std::out_of_range("Index out of range");
	}
	else {
		return data_[index];
	}
}

//
// get
//
template <typename T>
T Array_Base <T>::get (size_t index) const
{
    if (index > cur_size_) {
		throw std::out_of_range("Index out of range");
	}
	else {
		return data_[index];
	}
}

//
// set
//
template <typename T>
void Array_Base <T>::set (size_t index, T value)
{
    if (index > cur_size_) {
		throw std::out_of_range("Index out of range");
	}
	else {
		data_[index] = value;
	}
}

//
// find (char)
//
template  <typename T>
int Array_Base <T>::find (T value) const
{
    for(size_t i = 0; i < cur_size_; i++){
		if(data_[i] == value){
			return i;
		}
	}
	return -1;
}

//
// find (char, size_t) 
//
template <typename T>
int Array_Base <T>::find (T val, size_t start) const
{
    if(start > cur_size_){
		throw std::out_of_range("Index out of range");
	}
	for(size_t i = start; i < cur_size_; i++){
		if(data_[i] == val){
			return i;
		}
	}
	return -1;
}

//
// operator ==
//
template <typename T>
bool Array_Base <T>::operator == (const Array_Base & rhs) const
{
    if (this == &rhs){
        return true;
    }
    else if (cur_size_ == rhs.cur_size_) {
		return true;
	}
	else {
		return false;
	}
}

//
// operator !=
//
template <typename T>
bool Array_Base <T>::operator != (const Array_Base & rhs) const
{
    if (cur_size_ == rhs.cur_size_ && data_ == rhs.data_) {
		return false;
	}
	else {
		return true;
	}
}

//
// fill
//
template <typename T>
void Array_Base <T>::fill (T value)
{
    for (size_t i = 0; i < cur_size_; i++) {
		data_[i] = value;
	}
}

//reverses the Array_Base
template <typename T>
void Array_Base<T>::reverse (void)
{
	for(size_t i = 0, k = (cur_size_ - 1); i < k; i++, k--){
		char rev_data_ = data_[i];
		data_[i] = data_[k];
		data_[k] = rev_data_;
	}
}

template <typename T>
Array_Base<T> Array_Base<T>::slice (size_t begin) const
{
	Array_Base newArr = Array_Base((cur_size_ - begin));
	for(size_t i = begin; i < cur_size_; i++){
		newArr[i-begin] = data_[i];
	}
	return newArr;
}

template <typename T>
Array_Base<T> Array_Base<T>::slice (size_t begin, size_t end) const
{
	Array_Base newArr = Array_Base((cur_size_ - begin));
	for(size_t i = begin; i < end; i++){
		newArr[i-begin] = data_[i];
	}
	return newArr;
}

