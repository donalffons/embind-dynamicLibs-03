#ifndef _Standard_HeaderFile
#define _Standard_HeaderFile

#include <cstddef>

class Standard 
{
public:
  void* operator new (size_t theSize)
  {
    return Standard::Allocate ();
  }

  static void* Allocate ();
};

#endif // _Standard_HeaderFile
