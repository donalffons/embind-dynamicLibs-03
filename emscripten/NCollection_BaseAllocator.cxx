#include <NCollection_BaseAllocator.hxx>

const Handle(NCollection_BaseAllocator)& 
       NCollection_BaseAllocator::CommonBaseAllocator(void)
{ 
  static Handle(NCollection_BaseAllocator) pAllocator = 
    new NCollection_BaseAllocator;
  return pAllocator;
}
