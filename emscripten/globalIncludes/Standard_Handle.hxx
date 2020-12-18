#ifndef _Standard_Handle_HeaderFile
#define _Standard_Handle_HeaderFile

template <class T>
class handle
{
public:
  handle () {}

  handle (const T *thePtr) {
  }
};

#define Handle(Class) handle<Class>

#endif 
