#ifndef GTU_VECTOR_H
#define GTU_VECTOR_H

#include "GTUContainer.h"

namespace HW6
{
  template<typename T>
  class GTUVector : public GTUContainer<T>
  {
  public:
    GTUVector();
    bool empty() const;
    int size() const;
    int max_size() const;
    void insert(const T& element);
    void erase(const T& element);
    void clear();
    T& operator [] (int index);
    GTUIterator<T> begin() const;
    GTUIterator<T> end() const;
    bool exist(const T& element);
  };
}

#endif
