template <typename T>
inline
size_t Queue <T>::size (void) const
{
    return queue_array_.cur_size_;
}

template <typename T>
inline
bool Queue <T>::is_empty (void) const
{
    if(queue_array_.cur_size_ == 0){
        return true;
    }else{
        return false;
    }
}