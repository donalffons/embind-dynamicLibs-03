#include <Standard_MMgrRaw.hxx>
#include <stdlib.h>

void* Standard_MMgrRaw::Allocate(const size_t aSize)
{
  const size_t aRoundSize = (aSize + 3) & ~0x3;
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
