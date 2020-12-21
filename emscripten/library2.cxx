#include <Standard.hxx>

void* a = (new Standard_MMgrRaw())->Allocate();

// Previous Version (This still results in the same error):
// void* a = Standard_Allocate();
