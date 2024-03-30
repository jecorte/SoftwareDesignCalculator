// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.
#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//basic constructor
template <typename T>
Array <T>::Array (void):
data_ (new T[cur_size_]),
cur_size_(0),
max_size_(1)
{

}

//
// Array (size_t)
//constructor with length
template <typename T>
Array <T>::Array (size_t length):
data_ (new T[cur_size_]),
cur_size_(length),
max_size_(length)
{
    
}

//
// Array (size_t, char)
//fills the array with whatever T is
template <typename T>
Array <T>::Array (size_t length, T fill):
Array(length)
{
    	for (size_t i = 0; i < max_size_; i++) {
		data_[i] = fill;
	}
}

//
// Array (const Array &)
//copy constructor
template <typename T>
Array <T>::Array (const Array & array):
    data_ (new char[max_size_]),
	cur_size_(array.cur_size_),
	max_size_(array.max_size_)
{
	for (size_t i = 0; i < cur_size_; i++) {
		data_[i] = array.data_[i];
	}
}

//
// ~Array
//destructor
template <typename T>
Array <T>::~Array (void)
{
    delete[] this->data_;
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
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
T & Array <T>::operator [] (size_t index)
{
    if (index > max_size_) {
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
const T & Array <T>::operator [] (size_t index) const
{
    if (index > max_size_) {
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
T Array <T>::get (size_t index) const
{
    if (index > max_size_) {
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
void Array <T>::set (size_t index, T value)
{
    if (index > max_size_) {
		throw std::out_of_range("Index out of range");
	}
	else {
		data_[index] = value;
	}
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
	if(new_size == cur_size_){
		return;
	}else if(new_size > cur_size_ && new_size <= max_size_){
		cur_size_ = max_size_;
	}else if(new_size < cur_size_){
		return;
	}

	size_t i = 0;
	T* resized_array = new T[new_size];
	while(i < cur_size_){
		resized_array[i] = data_[i];
		i++;
	}
	cur_size_ = new_size;
	max_size_ = new_size;
	delete[] data_;
	data_ = resized_array;
}

//
// find (char)
//
template  <typename T>
int Array <T>::find (T value) const
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
int Array <T>::find (T val, size_t start) const
{
    if(start > max_size_){
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
bool Array <T>::operator == (const Array & rhs) const
{
    if (this == &rhs){
        return true;
    }
    else if (cur_size_ == rhs.cur_size_ && max_size_ == rhs.max_size_ ) {
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
bool Array <T>::operator != (const Array & rhs) const
{
    if (cur_size_ == rhs.cur_size_ && max_size_ == rhs.max_size_ && data_ == rhs.data_) {
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
void Array <T>::fill (T value)
{
    for (size_t i = 0; i < max_size_; i++) {
		data_[i] = value;
	}
}

template <typename T>
void Array <T>::shrink(void)
{
    if (max_size_ > cur_size_) {
	    char* shrunk_data_ = new char[cur_size_];

		for (size_t i = 0; i < cur_size_; i++) {
			shrunk_data_[i] = data_[i];
		}
		delete[] data_;
		data_ = shrunk_data_;
		max_size_ = cur_size_;
		delete[] shrunk_data_;
	}
}

//reverses the array
template <typename T>
void Array<T>::reverse (void)
{
	for(size_t i = 0, k = (cur_size_ - 1); i < k; i++, k--){
		char rev_data_ = data_[i];
		data_[i] = data_[k];
		data_[k] = rev_data_;
	}
}

template <typename T>
Array<T> Array<T>::slice (size_t begin) const
{
	Array newArr = Array((cur_size_ - begin));
	for(size_t i = begin; i < cur_size_; i++){
		newArr[i-begin] = data_[i];
	}
	return newArr;
}

template <typename T>
Array<T> Array<T>::slice (size_t begin, size_t end) const
{
	Array newArr = Array((cur_size_ - begin));
	for(size_t i = begin; i < end; i++){
		newArr[i-begin] = data_[i];
	}
	return newArr;
}

