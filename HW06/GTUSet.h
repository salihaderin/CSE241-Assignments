#ifndef GTU_SET_H
#define GTU_SET_H

#include "GTUContainer.h"

namespace HW6
{
    template<typename T>
    class GTUSet : public GTUContainer<T>
    {
    public:
      GTUSet();
      bool empty() const;
      int size() const;
      int max_size() const;
      void insert(const T& element);
      void erase(const T& element);
      void clear();
      GTUIterator<T> begin() const;
      GTUIterator<T> end() const;
      bool exist(const T& element);
    };
}

#endif
