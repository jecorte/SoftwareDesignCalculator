// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS507_FIXED_ARRAY_H_
#define _CS507_FIXED_ARRAY_H_

#include "Array_Base.h"

// COMMENT Replace this with the structure we discussed in class:
//   Array_Base
//   Fixed_Array: Array_Base
//   Array : Array_Base
//
// Otherwise, your implementation will not work as expected since
// the Array class has an expected interface, which you have changed.
//
//FIX Changed the naming conventions

/**
 * @class Fixed_Array
 *
 * Implementation of a fixed size array, i.e., one that is not
 * resizeable. It is derived from Array so it can inherit of 
 * the Array class's methods.
 */
template <typename T>
class Fixed_Array : public Array <T>
{
public:
  /// Default constructor.
  Fixed_Array (void);

	/**
	 * Copy constructor.
	 *
	 * @param[in]      arr        Source array
	 */
  Fixed_Array (const Fixed_Array <T> & arr);
	
  /**
   * Initializing constructor. The source array can be of any size
   * as long as they are of the same type.
   *
   * @param[in]      arr        Source array
   */

  /**
   * Initializing constructor. Fills the contents of the 
   * array with the specified \a fill value.
   *
   * @param[in]      fill       The file value.
   */
  Fixed_Array (T fill);

  /// Destructor.
  ~Fixed_Array (void);

  /**
   * Assignment operator
   *
   * @param[in]      rhs        Right-hand side of operator.
   */
  const Fixed_Array & operator = (const Fixed_Array <T> & rhs);


protected:
  /// Pointer to the actual data.
  char * data_;

  /// Current size of the Fixed_Array.
  size_t cur_size_;

  size_t max_size_;

};

// include the inline files
#include "Fixed_Array.inl"

// include the source file since template class
#include "Fixed_Array.cpp"

#endif  // !defined _CS507_FIXED_ARRAY_H_
