#ifndef NCollection_BaseList_HeaderFile
#define NCollection_BaseList_HeaderFile

#include <NCollection_BaseAllocator.hxx>

class NCollection_BaseList
{
public:
  NCollection_BaseList () {
    auto asd = NCollection_BaseAllocator::CommonBaseAllocator();
  }
};

#endif
