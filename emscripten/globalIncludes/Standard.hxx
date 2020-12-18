#ifndef _Standard_HeaderFile
#define _Standard_HeaderFile

#include <Standard_Address.hxx>
#include <Standard_Size.hxx>

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
  Standard_EXPORT static Standard_Address Allocate (const Standard_Size aSize);
  
  //! Deallocates memory blocks
  //! @param thePtr - previously allocated memory block to be freed
  Standard_EXPORT static void Free (const Standard_Address thePtr);
};

#endif // _Standard_HeaderFile
