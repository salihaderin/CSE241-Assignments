#ifndef GTU_CONTAINER_H
#define GTU_CONTAINER_H

#include <memory>
#include "GTUIterator.h"

using std::shared_ptr;

namespace HW6
{
  template <typename T>
  class GTUContainer
  {
  public:
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual int max_size() const = 0;
    virtual void insert(const T& element) = 0;
    virtual void erase(const T& element) = 0;
    virtual void clear() = 0;
    virtual GTUIterator<T> begin() const = 0;
    virtual GTUIterator<T> end() const = 0;
  protected:
    int sizeVal;
    int capacityVal;
    shared_ptr<T> container;
  };
}

#endif
