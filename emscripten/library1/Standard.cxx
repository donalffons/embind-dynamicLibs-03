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

#include <iostream>

void* Standard::Allocate(const size_t size)
{
  std::cout << "1" << std::endl;
  auto a = Standard_MMgrFactory::GetMMgr();
  std::cout << "2" << std::endl;
  auto b = a->Allocate(size);
  std::cout << "3" << std::endl;
  return b;
}

void Standard::Free (void* theStorage)
{
  Standard_MMgrFactory::GetMMgr()->Free(theStorage);
}
