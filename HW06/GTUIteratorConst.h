#ifndef GTU_ITERATOR_CONST_H
#define GTU_ITERATOR_CONST_H

namespace HW6
{
    template<typename T>
    class GTUIteratorConst
    {
    public:
      GTUIteratorConst(T*); //constructor
      const T& operator * () const; //* operator overloading
      const T* operator -> () const; // -> operator overloading
      GTUIteratorConst& operator ++ ();  //prefix ++ overloading
      GTUIteratorConst& operator ++ (int);  //postfix ++ overloading
      GTUIteratorConst& operator -- ();  //prefix -- overloading
      GTUIteratorConst& operator -- (int);  //postfix -- overloading
      GTUIteratorConst& operator = (const GTUIteratorConst&); //assignment operator overloading
      bool operator == (const GTUIteratorConst&) const;  //== operator overloading
      T* getIter() const;
    private:
      T* iter;
    };
}

#endif
