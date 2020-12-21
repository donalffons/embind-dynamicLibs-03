#include <Standard.hxx>
#include <iostream>

void* Standard_Allocate()
{
  std::cout << "1" << std::endl;
  auto a = new Standard_MMgrRaw ();
  std::cout << "2" << std::endl;
  auto b = a->Allocate();
  std::cout << "3" << std::endl;
  return 0;
}
