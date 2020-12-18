#include <Standard.hxx>
#include <Standard_MMgrRaw.hxx>

class Standard_MMgrFactory
{
public:
  static Standard_MMgrRaw* GetMMgr();

private:
  Standard_MMgrFactory();

private:
  Standard_MMgrRaw* myFMMgr;
};

Standard_MMgrFactory::Standard_MMgrFactory()
: myFMMgr (NULL)
{
  myFMMgr = new Standard_MMgrRaw ();
}

Standard_MMgrRaw* Standard_MMgrFactory::GetMMgr()
{
  static Standard_MMgrFactory aFactory;
  return aFactory.myFMMgr;
}

void* Standard::Allocate(const size_t size)
{
  return Standard_MMgrFactory::GetMMgr()->Allocate(size);
}

void Standard::Free (void* theStorage)
{
  Standard_MMgrFactory::GetMMgr()->Free(theStorage);
}
