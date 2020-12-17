#ifndef NCollection_BaseAllocator_HeaderFile
#define NCollection_BaseAllocator_HeaderFile

#include <Standard_Transient.hxx>
#include <Standard_Type.hxx>
#include <NCollection_TypeDef.hxx>


class NCollection_BaseAllocator : public Standard_Transient
{
 public:
  // ---------- PUBLIC METHODS ------------
  Standard_EXPORT virtual void* Allocate (const size_t size);
  
  Standard_EXPORT static const Handle(NCollection_BaseAllocator)&
    CommonBaseAllocator(void);

 protected:
  //! Constructor - prohibited
  NCollection_BaseAllocator(void) {}

 private:
  //! Copy constructor - prohibited
  NCollection_BaseAllocator(const NCollection_BaseAllocator&);

 public:
  // ---------- CasCade RunTime Type Information
  DEFINE_STANDARD_RTTIEXT(NCollection_BaseAllocator,Standard_Transient)
};

DEFINE_STANDARD_HANDLE(NCollection_BaseAllocator,Standard_Transient)

#endif
