#include "Queue.h"
#define def_size_ 10
//
// Stack
//
template <typename T>
Queue <T>::Queue (void):
queue_array_(def_size_),
front(0),
end(0)
{
   
}

template <typename T>
Queue <T>::Queue (const Queue & q):
    queue_array_(def_size_)
{

	for (size_t i = 0; i < queue_array_.cur_size_; i++) {
		queue_array_.data_[i] = q.data_[i];
	}
}

template <typename T>
Queue <T>::~Queue (void)
{
   delete[] this->data_;
}

template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
    if(this = &rhs){
        return *this;
    }
    queue_array_.cur_size = rhs.cur_size_;

    for (size_t i = 0; i < queue_array_.cur_size_; i++) {
		queue_array_.data_[i] = rhs.data_[i];
	}

	return *this;

}

template <typename T>
void Queue <T>::enqueue (T element)
{
    // COMMENT This approach can work, but its design is very expensive. You
    // should find a better design that tries to use as much space as possible
    // while minimizing the amount of copying that must occur.
    //
    // FIX Only copied things when the queue was full, and fixed the appending to append to the end rather than the beginning.
    if(queue_array_.cur_size_ == queue_array_.max_size){
        queue_array_.max_size += 3;
        for(size_t i = front; i < queue_array_.cur_size_; i++){
		    queue_array_.data_[i+1] = queue_array_.data[i];
	    }
    }

    queue_array_.data[end] = element;
    end += 1;
}

template <typename T>
T Queue <T>::dequeue (void)
{
    if(queue_array_.size == 0){
        throw empty_exception("Queue is empty, can't dequeue.");
    }
    
    // COMMENT This design is OK, but it is not the best design. This will be
    // a very expensive array to use if you are dequeing a lot of elements. This
    // is because you are copying N elements each time you dequeue 1 element.
    // Instead, you only want to copy element when necessary. Come up with a better
    // design that is not as expensive for the client to use.
    //
    // FIX Created a "front" variable that keeps track of what's in front and returns the variable that used to be in "front."
    front += 1;
    queue_array_.resize(queue_array_.size - 1);
    return queue_array_[front-1];                          
}

template <typename T>
void Queue <T>::clear (void)
{
    queue_array_.resize(1);
}