#include <stdexcept>
#include <memory>
#include <iostream>
#include "GTUVector.h"

using std::cout;
using std::endl;
using std::shared_ptr;
using std::invalid_argument;
using std::domain_error;
using std::default_delete;

namespace HW6
{
  template<typename T>
  GTUVector<T>::GTUVector()
  {
    this->sizeVal = 0;
    this->capacityVal = 0;
  }

  template<typename T>
  bool GTUVector<T>::empty() const
  {
    if(this->sizeVal == 0){
      return true;
    }
    else{
      return false;
    }
  }

  template<typename T>
  int GTUVector<T>::size() const
  {
      return this->sizeVal;
  }

  template<typename T>
  int GTUVector<T>::max_size() const
  {
    return this->capacityVal;
  }

  /*
   *checks whether there is enough capacity to add new element
   *keeps container shared_ptr in temp1 to not lose container
   *creates temp2 shared_ptr for allocating memory
   *clears container with temp2
   *copies all elements into container
   *finally adds the new element
   */
  template<typename T>
  void GTUVector<T>::insert(const T& element)
  {
    int check = this->max_size() - this->size();
    if(check < 0){
      throw domain_error("Something went wrong.");
    }
    else{
      if(check == 0){
        this->capacityVal++;
      }
      shared_ptr<T> temp1 = this->container;
      shared_ptr<T> temp2(new T[this->max_size()], default_delete<T[]>());
      this->container = temp2;
      for(auto i = 0; i < this->size(); ++i){
        this->container.get()[i] = temp1.get()[i];
      }
      this->container.get()[this->size()] = element;
      this->sizeVal++;
    }
  }

  /*
   *checks whether the element is in the set
   *if it is not, throws exception
   *uses a similar algorithm with the insert function
   *shifts elements by ignoring the target element
   */
  template<typename T>
  void GTUVector<T>::erase(const T& element)
  {
    if(!this->exist(element)){
      throw invalid_argument("This element does not exist in the set.");
    }
    else{
      shared_ptr<T> temp1 = this->container;
      shared_ptr<T> temp2(new T[this->max_size()], default_delete<T[]>());
      this->container = temp2;
      auto j = 0;
      for(auto i = 0; i < this->size(); ++i, ++j){
        if(temp1.get()[j] == element){
          this->sizeVal--;
          i--;
          continue;
        }
        else{
          this->container.get()[i] = temp1.get()[j];
        }
      }
    }
  }

  /*
   *I am not sure whether i should delete shared_ptr elements or i should not
   *I will pretend like they do not exist
   */
  template<typename T>
  void GTUVector<T>::clear()
  {
    this->sizeVal = 0;
  }

  template<typename T>
  T& GTUVector<T>::operator [] (int index)
  {
    return this->container.get()[index]; // buraya bak
  }

  /*
   *uses std::shared_ptr::get function to begin
   */
  template<typename T>
  GTUIterator<T> GTUVector<T>::begin() const
  {
    return (this->container).get();
  }

  template<typename T>
  GTUIterator<T> GTUVector<T>::end() const
  {
    GTUIterator<T> iter = this->begin();
    int i = 1;
    while(i <= this->sizeVal){
      iter++;
      i++;
    }
    return iter;
  }

  /*
   *checks whether the element is in the vector or not
   */
  template<typename T>
  bool GTUVector<T>::exist(const T& element)
  {
    for(auto iter = this->begin(); iter != this->end(); ++iter){
      if(*iter == element){
        return true;
      }
    }
    return false;
  }
}

/*
 *to not get undefined reference error
 */
template class HW6::GTUVector<char>;
template class HW6::GTUContainer<char>;
template class HW6::GTUVector<int>;
template class HW6::GTUContainer<int>;
template class HW6::GTUVector<bool>;
template class HW6::GTUContainer<bool>;
template class HW6::GTUVector<float>;
template class HW6::GTUContainer<float>;
/*template class HW6::GTUVector<void>;
template class HW6::GTUContainer<void>;*/
template class HW6::GTUVector<wchar_t>;
template class HW6::GTUContainer<wchar_t>;
template class HW6::GTUVector<std::string>;
template class HW6::GTUContainer<std::string>;
