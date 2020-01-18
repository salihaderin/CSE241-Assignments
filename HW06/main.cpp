#include <iostream>

#include "GTUSet.h"
#include "GTUVector.h"

using std::cout;
using std::endl;
using std::string;

using namespace HW6;

template<typename T>
void printContainer(const GTUContainer<T>& con);

template<typename T>
void printElement(const GTUIterator<T>& element);

template<typename T>
GTUIterator<T> find(GTUIterator<T> iter1, GTUIterator<T> iter2, const T& element);

template<typename F, typename T>
void for_each(GTUIterator<T> iter1, GTUIterator<T> iter2, F func);

template<typename T, typename P>
GTUIterator<T> find_if(GTUIterator<T> iter1, GTUIterator<T> iter2, P base);

/*
 *for testing the find_if element
 */
inline bool isEven(int i){ return ((i % 2) == 0);}

int main(int argc, char const *argv[]) {
  cout << "--- TESTING GTUSet<int> ---" << endl;
  GTUSet<int> testSetInt;
  cout << "Empty function is calling..." << endl;
  try{
    if(testSetInt.empty())
      cout << "Set is empty" << endl;
    else
      cout << "Set is not empty" << endl;
    cout << "Inserting elements..." << endl;
    for(int i = 1; i < 11; ++i){
      testSetInt.insert(i);
    }
    cout << "Elements of set: ";
    printContainer(testSetInt);
    cout << "Empty function is calling..." << endl;
    if(testSetInt.empty())
      cout << "Set is empty" << endl;
    else
      cout << "Set is not empty" << endl;
    cout << "Trying to add an existing element into set..." << endl;
    testSetInt.insert(5);
    cout << "Elements of set: ";
    printContainer(testSetInt);
    cout << "Set size: " << testSetInt.size() << endl;
    cout << "Set max_size: " << testSetInt.max_size() << endl;
    cout << "Erase function is calling..." << endl;
    for(int i =  1; i < 10; ++i){
      if(isEven(i))
        testSetInt.erase(i);
    }
    cout << "Elements of set: ";
    printContainer(testSetInt);
    GTUIterator<int> setIter1 = testSetInt.begin();
    GTUIterator<int> setIter2 = testSetInt.end();
    cout << "find function is calling..." << endl;
    GTUIterator<int> temp = find(setIter1, setIter2, 5);
    cout << *temp << "is found" << endl;
    cout << "find_if function is calling..." << endl;
    temp = find_if(setIter1, setIter2, isEven);
    cout << *temp << " is the first even number in the set." << endl;
  }
  catch(std::invalid_argument excp){
    cout << "Caught an error" << endl;
  }
  catch(std::domain_error excp){
    cout << "Caught an error" << endl;
  }

  cout << endl << endl;

  cout << "--- TESTING GTUVector<int> ---" << endl;
  GTUVector<int> testVectorInt;
  cout << "Empty function is calling..." << endl;
  try{
    if(testVectorInt.empty())
      cout << "Vector is empty" << endl;
    else
      cout << "Vector is not empty" << endl;
    cout << "Inserting elements..." << endl;
    for(int i = 1; i < 11; ++i){
      testVectorInt.insert(i);
    }
    cout << "Elements of vector: ";
    printContainer(testVectorInt);
    cout << "Empty function is calling..." << endl;
    if(testSetInt.empty())
      cout << "Vector is empty" << endl;
    else
      cout << "Vector is not empty" << endl;
    cout << "Trying to add an existing element into vector..." << endl;
    testVectorInt.insert(5);
    cout << "Elements of vector: ";
    printContainer(testVectorInt);
    cout << "Vector size: " << testVectorInt.size() << endl;
    cout << "Vector max_size: " << testVectorInt.max_size() << endl;
    cout << "Erase function is calling..." << endl;
    for(int i =  1; i < 10; ++i){
      if(isEven(i))
        testVectorInt.erase(i);
    }
    cout << "Elements of vector: ";
    printContainer(testVectorInt);
    GTUIterator<int> vectorIter1 = testVectorInt.begin();
    GTUIterator<int> vectorIter2 = testVectorInt.end();
    cout << "find function is calling..." << endl;
    GTUIterator<int> temp = find(vectorIter1, vectorIter2, 5);
    cout << *temp << "is found" << endl;
    cout << "find_if function is calling..." << endl;
    temp = find_if(vectorIter1, vectorIter2, isEven);
    cout << *temp << " is the first even number in the vector." << endl;
  }
  catch(std::invalid_argument excp){
    cout << "Caught an error" << endl;
  }
  catch(std::domain_error excp){
    cout << "Caught an error" << endl;
  }

  cout << endl << endl;

/******** TESTING GTUSet FOR STRING TYPE
  GTUSet<string> testSetStr;
  try{
    testSetStr.insert("Monday");
    testSetStr.insert("Tuesday");
    testSetStr.insert("Tuesday");
    testSetStr.insert("Wednesday");
    testSetStr.insert("Thursday");
    testSetStr.insert("Friyay");
    testSetStr.insert("Saturday");
    testSetStr.insert("Sunday");
    testSetStr.erase("Monday");
    testSetStr.erase("DumbDay");
  }
  catch(std::invalid_argument excp){
    cout << "Caught an error" << endl;
  }
  catch(std::domain_error excp){
    cout << "Caught an error" << endl;
  }
  printContainer(testSetStr);*/


/*********TESTING GTUVector FOR STRING TYPE
  GTUVector<string> testVectorStr;
  try{
    testVectorStr.insert("Monday");
    testVectorStr.insert("Tuesday");
    testVectorStr.insert("Tuesday");
    testVectorStr.insert("Wednesday");
    testVectorStr.insert("Thursday");
    testVectorStr.insert("Friyay");
    testVectorStr.insert("Saturday");
    testVectorStr.insert("Sunday");
    testVectorStr.erase("Monday");
    testVectorStr.erase("Dumbday");
  }
  catch(std::invalid_argument excp){
    cout << "Caught an error" << endl;
  }
  catch(std::domain_error excp){
    cout << "Caught an error" << endl;
  }
  printContainer(testVectorStr);*/


  return 0;
}

/*
 *prints the container content
 */
template<typename T>
void printContainer(const GTUContainer<T>& con)
{
  for(auto iter = con.begin(); iter != con.end(); ++iter){
    cout << *iter << ' ';
  }
  cout << endl;
}

/*template<typename T>
void printElement(const GTUIterator<T>& element)
{
  cout << element << endl;
}*/

/*
 *finds given element between two iterators
 *if there is no such element then returns iter1
 */
template<typename T>
GTUIterator<T> find(GTUIterator<T> iter1, GTUIterator<T> iter2, const T& element)
{
  for(; iter1 != iter2; ++iter1){
    if(*iter1 == element){
      cout << "Element "<< *iter1 << " is found (find function)." << endl;
      return iter1;
    }
  }
  cout << "Element " << element << " cannot be found (find function)." << endl;
  return iter1;
}

/*
 *i couldn't execute this function because i got an error when calling
 *it was supposed to execute given parameter for every element between iter1 and iter2
 */
/*template<typename T, typename F>
void for_each(GTUIterator<T> iter1, GTUIterator<T> iter2, F func)
{
  for(; iter1 != iter2; ++iter1){
    func(*iter1);
    cout << "Function executed for " << *iter1 << " element (foreach function)." << endl;
  }
}*/

/*
 *finds first element that fulfills the base condition and then returns it
 *returns iter1 if there is no such element
 */
template<typename T, typename P>
GTUIterator<T> find_if(GTUIterator<T> iter1, GTUIterator<T> iter2, P base)
{
  for(; iter1 != iter2; ++iter1){
    if(base(*iter1)){
      return iter1;
    }
  }
  cout << "no even" << endl;
  return iter1;
}
