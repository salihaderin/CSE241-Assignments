#include <string>
#include "GTUIterator.h"

namespace HW6
{
  template<typename T>
  GTUIterator<T>::GTUIterator(void) {}

  template<typename T>
  GTUIterator<T>::GTUIterator(T* newIter)
  {
    iter = newIter;
  }

  template<typename T>
  T& GTUIterator<T>:: operator * () const
  {
    return *iter;
  }

  template<typename T>
  T* GTUIterator<T>::operator -> () const
  {
    return iter;
  }

  template<typename T>
  GTUIterator<T>& GTUIterator<T>::operator ++ ()
  {
    iter++;
    return *this;
  }

  template<typename T>
  GTUIterator<T> GTUIterator<T>::operator ++ (int _)
  {
    GTUIterator<T> temp = *this;
    iter++;
    return temp;
  }

  template<typename T>
  GTUIterator<T>& GTUIterator<T>::operator -- ()
  {
    iter--;
    return *this;
  }

  template<typename T>
  GTUIterator<T> GTUIterator<T>::operator -- (int _)
  {
    GTUIterator<T> temp = *this;
    iter--;
    return temp;
  }

  template<typename T>
  GTUIterator<T>& GTUIterator<T>::operator = (const GTUIterator& rightSide)
  {
    iter = rightSide.iter;
    return *this;
  }

  template<typename T>
  bool GTUIterator<T>::operator == (const GTUIterator<T>& rightSide) const
  {
    if(this->iter == rightSide.iter){
      return true;
    }
    else{
      return false;
    }
  }

  template<typename T>
  bool GTUIterator<T>::operator != (const GTUIterator<T>& rightSide) const
  {
    if(this->iter != rightSide.iter){
      return true;
    }
    else{
      return false;
    }
  }

  template<typename T>
  T* GTUIterator<T>::getIter() const
  {
    return iter;
  }
}

/*
 *to not get undefined reference error
 */
template class HW6::GTUIterator<char>;
template class HW6::GTUIterator<int>;
template class HW6::GTUIterator<bool>;
template class HW6::GTUIterator<float>;
template class HW6::GTUIterator<double>;
template class HW6::GTUIterator<wchar_t>;
template class HW6::GTUIterator<std::string>;
