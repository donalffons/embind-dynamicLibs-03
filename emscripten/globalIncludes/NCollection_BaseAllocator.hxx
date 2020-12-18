#ifndef NCollection_BaseAllocator_HeaderFile
#define NCollection_BaseAllocator_HeaderFile

#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>

class NCollection_BaseAllocator : public Standard_Transient
{
 public:
  Standard_EXPORT static const Handle(NCollection_BaseAllocator)&
    CommonBaseAllocator(void);
};

#endif
