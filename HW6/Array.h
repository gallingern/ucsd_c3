/*
 * Array.h
 *
 *  Created on: Nov 12, 2013
 *      Author: Nathaniel Gallinger
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdexcept>
using std::invalid_argument;

namespace NathanielGallinger
{
  template <typename ElemType, int SIZE>
  class Array
  {
  public:
    // Default Constructor
    Array()
    {
    }

    // Copy Constructor
    Array(ElemType source[SIZE])
    : elements(source)
    {
    }

    // Overloaded = operator
    Array<ElemType, SIZE> operator=(ElemType source[SIZE])
    {
      ElemType retval[SIZE];

      for (int idx = 0; idx < SIZE; idx++) {
        retval[idx] = source[idx];
      }

      return retval;
    }

    // Overloaded == operator
    bool operator==(const Array<ElemType, SIZE> other)
    {
      bool retval = true;

      for (int idx = 0; idx < SIZE; idx++) {
        if(!(this->elements[idx] == other[idx]))
          retval = false;
      }

      return retval;
    }

    // Overloaded != operator
    bool operator!=(const Array<ElemType, SIZE> other)
    {
      bool retval = true;

      for (int idx = 0; idx < SIZE; idx++) {
        if(!(this->elements[idx] == other[idx]))
          retval = false;
      }

      return !retval;
    }

    // Overloaded [] operator, L-value
    ElemType &operator[](int index)
    {
      if((index < 0) || (index >= SIZE))
        throw invalid_argument("subscript index is out of range");

      return this->elements[index];
    }

    // Overloaded [] operator, L-value
    ElemType operator[](int index) const
    {
      if((index < 0) || (index >= SIZE))
        throw invalid_argument("subscript index is out of range");

      return this->elements[index];
    }

  private:
    ElemType elements[SIZE];
  };
}


#endif /* ARRAY_H_ */
