#include <Standard_MMgrRaw.hxx>
#include <stdlib.h>

void* Standard_MMgrRaw::Allocate(const size_t aSize)
{
  // the size is rounded up to 4 since some OCC classes
  // (e.g. TCollection_AsciiString) assume memory to be double word-aligned
  const size_t aRoundSize = (aSize + 3) & ~0x3;
  // we use ?: operator instead of if() since it is faster :-)
  void* aPtr = ( myClear ? calloc(aRoundSize, sizeof(char)) :
                                      malloc(aRoundSize) );
  if ( ! aPtr )
    return nullptr;
  return aPtr;
}

void Standard_MMgrRaw::Free(void* theStorage)
{
  free(theStorage);
}
