#include "GTUIteratorConst.h"

namespace HW6
{
  template<typename T>
  GTUIteratorConst<T>::GTUIteratorConst(T *newIter)
  {
    iter = newIter;
  }

  template<typename T>
  const T& GTUIteratorConst<T>::operator * () const
  {
    return *iter;
  }

  template<typename T>
  const T* GTUIteratorConst<T>::operator -> () const
  {
    return iter;
  }

  template<typename T>
  GTUIteratorConst<T>& GTUIteratorConst<T>::operator ++ ()
  {
    iter++;
    return *this;
  }

  template<typename T>
  GTUIteratorConst<T>& GTUIteratorConst<T>::operator ++ (int ignoreMe)
  {
    GTUIteratorConst temp = *this;
    iter++;
    return temp;
  }

  template<typename T>
  GTUIteratorConst<T>& GTUIteratorConst<T>::operator -- ()
  {
    iter--;
    return -this;
  }

  template<typename T>
  GTUIteratorConst<T>& GTUIteratorConst<T>::operator -- (int ignoreMe)
  {
    GTUIteratorConst temp = *this;
    iter--;
    return temp;
  }

  template<typename T>
  GTUIteratorConst<T>& GTUIteratorConst<T>::operator = (const GTUIteratorConst& rightSide)
  {
    iter = rightSide.iter;
    return *this;
  }

  template<typename T>
  bool GTUIteratorConst<T>::operator == (const GTUIteratorConst& rightSide) const
  {
    if(this->iter == rightSide->iter){
      return true;
    }
    else{
      return false;
    }
  }

  template<typename T>
  T* GTUIteratorConst<T>::getIter() const
  {
    return iter;
  }
}
