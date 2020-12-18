#ifndef _Standard_HeaderFile
#define _Standard_HeaderFile

#include <cstddef>

class Standard 
{
public:
  void* operator new (size_t theSize)
  {
    return Standard::Allocate (theSize);
  }
  void  operator delete (void* theAddress)
  {
    Standard::Free (theAddress);
  }

  
  static void* Allocate (const size_t aSize);
  
  static void Free (void* thePtr);
};

#endif // _Standard_HeaderFile
