#ifndef _Standard_HeaderFile
#define _Standard_HeaderFile

#include <cstddef>

class Standard_MMgrRaw
{
public:
  virtual void* Allocate() {
    return new int;
  }
};

void* Standard_Allocate();

#endif // _Standard_HeaderFile
