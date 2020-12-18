#ifndef _Standard_HeaderFile
#define _Standard_HeaderFile

#include <cstddef>

//! The package Standard provides global memory allocator and other basic
//! services used by other OCCT components.

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

  
  //! Allocates memory blocks
  //! aSize - bytes to  allocate
  static void* Allocate (const size_t aSize);
  
  //! Deallocates memory blocks
  //! @param thePtr - previously allocated memory block to be freed
  static void Free (void* thePtr);
};

#endif // _Standard_HeaderFile
