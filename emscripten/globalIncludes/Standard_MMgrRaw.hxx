#ifndef _Standard_MMgrRaw_HeaderFile
#define _Standard_MMgrRaw_HeaderFile

#include <cstddef>

class Standard_MMgrRaw
{
public:
  virtual void* Allocate(const size_t aSize){
    return nullptr;
  }
  
  virtual void Free (void* thePtr){}
};

#endif
