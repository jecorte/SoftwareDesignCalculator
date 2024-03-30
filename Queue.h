#ifndef QUEUE_H_
#define QUEUE_H_

#include "Array.h"

#include <exception>

/**
 * @class Queue
 *
 * Basic stack for abitrary elements.
 */
template <typename T>
class Queue
{
public:
  /// Type definition of the type.
  typedef T type;

  class empty_exception : public std::exception
  {
  public:
    /// Default constructor.
    empty_exception (void)
      : std::exception () { }

    empty_exception (const char * msg)
      : std::exception (msg) { }
  };

  /// Default constructor.
  Queue (void);

  /// Copy constructor.
  Queue (const Queue & q);

  /// Destructor.
  ~Queue (void);

  const Queue & operator = (const Queue & rhs);

  void enqueue (T element);

  T dequeue (void);

  bool is_empty (void) const;

  size_t size (void) const;

 
  void clear (void);

protected:

  Array<T> queue_array_;

  char * data_;

  int front;
  int end;
};



#include "Queue.cpp"

#include "Queue.inl"

#endif  
