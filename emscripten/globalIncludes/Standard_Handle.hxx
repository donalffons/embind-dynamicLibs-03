#ifndef _Standard_Handle_HeaderFile
#define _Standard_Handle_HeaderFile

#include <Standard_Transient.hxx>

template <class T>
class handle
{
public:

  //! Empty constructor
  handle () : entity(0) {}

  //! Constructor from pointer to new object
  handle (const T *thePtr) : entity(const_cast<T*>(thePtr))
  {
  }

private:
  Standard_Transient* entity;
};

#define Handle(Class) handle<Class>

#endif 
