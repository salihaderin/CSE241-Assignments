#ifndef GTU_ITERATOR_H
#define GTU_ITERATOR_H

namespace HW6
{
    template<typename T>
    class GTUIterator
    {
    public:
      GTUIterator<T>(void);
      GTUIterator<T>(T* newIter); //constructor
      T& operator * () const; //* operator overloading
      T* operator -> () const; // -> operator overloading
      GTUIterator<T>& operator ++ ();  //prefix ++ overloading
      GTUIterator<T> operator ++ (int _);  //postfix ++ overloading
      GTUIterator<T>& operator -- ();  //prefix -- overloading
      GTUIterator<T> operator -- (int _);  //postfix -- overloading
    //  GTUIterator<T>& operator + (int i); //+ operator overloading
      GTUIterator<T>& operator = (const GTUIterator<T>& rightSide); //assignment operator overloading
      bool operator == (const GTUIterator<T>& rightSide) const;  //== operator overloading
      bool operator != (const GTUIterator<T>& rightSide) const; //!= operator overloading
      T* getIter() const;
    private:
      T* iter;
    };
}

#endif
