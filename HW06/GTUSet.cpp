#include <iostream>
#include <stdexcept>
#include <memory>

#include "GTUSet.h"

using std::cout;
using std::endl;
using std::invalid_argument;
using std::shared_ptr;
using std::default_delete;
using std::domain_error;

namespace HW6
{
  template<typename T>
  GTUSet<T>::GTUSet()
  {
    this->sizeVal = 0;
    this->capacityVal = 0;
  }

  template<typename T>
  bool GTUSet<T>::empty() const
  {
      if(this->sizeVal == 0){
        return true;
      }
      else{
        return false;
      }
  }

  template<typename T>
  int GTUSet<T>::size() const
  {
    return this->sizeVal;
  }

  template<typename T>
  int GTUSet<T>::max_size() const
  {
    return this->capacityVal;
  }

  /*
   *checks if the element is already in container
   *checks if there is enough capacity to add new element
   *keeps container shared_ptr in temp1 to not lose container
   *creates temp2 shared_ptr for allocating memory
   *clears container with temp2
   *copies all elements into container
   *finally adds the new element
   */
  template<typename T>
  void GTUSet<T>::insert(const T& element)
  {
    int check = this->max_size() - this->size();
    if(this->exist(element)){
      throw invalid_argument("Element is already in the set.");
    }
    else if(check < 0){
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
  void GTUSet<T>::erase(const T& element)
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
  void GTUSet<T>::clear()
  {
    this->sizeVal = 0;
  }

  /*
   *uses std::shared_ptr::get function to begin
   */
  template<typename T>
  GTUIterator<T> GTUSet<T>::begin() const
  {
    return (this->container).get();
  }

  template<typename T>
  GTUIterator<T> GTUSet<T>::end() const
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
  bool GTUSet<T>::exist(const T& element)
  {
    for(auto i = this->begin(); i != this->end(); ++i){
      if(*i == element){
        return true;
      }
    }
    return false;
  }
}

/*
 *to not get undefined reference error
 */
template class HW6::GTUSet<char>;
template class HW6::GTUContainer<char>;
template class HW6::GTUSet<int>;
template class HW6::GTUContainer<int>;
template class HW6::GTUSet<bool>;
template class HW6::GTUContainer<bool>;
template class HW6::GTUSet<float>;
template class HW6::GTUContainer<float>;
template class HW6::GTUSet<double>;
template class HW6::GTUContainer<double>;
template class HW6::GTUSet<wchar_t>;
template class HW6::GTUContainer<wchar_t>;
template class HW6::GTUSet<std::string>;
template class HW6::GTUContainer<std::string>;
