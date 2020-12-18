#include <Standard.hxx>
#include <Standard_MMgrRaw.hxx>
#include <iostream>

void* Standard::Allocate()
{
  std::cout << "1" << std::endl;
  auto a = new Standard_MMgrRaw ();
  std::cout << "2" << std::endl;
  auto b = a->Allocate();
  std::cout << "3" << std::endl;
  return b;
}
