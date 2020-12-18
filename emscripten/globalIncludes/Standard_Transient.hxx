#ifndef _Standard_Transient_HeaderFile
#define _Standard_Transient_HeaderFile

#include <Standard.hxx>

class Standard_Transient
{
public:
  void* operator new (size_t theSize)
  {
    return Standard::Allocate (theSize);
  }
};


#endif 
