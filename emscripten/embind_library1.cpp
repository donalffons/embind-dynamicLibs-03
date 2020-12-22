#include <emscripten/bind.h>
using namespace emscripten;

#include <Standard.hxx>

EMSCRIPTEN_BINDINGS(my_module) {
  function("Standard_Allocate", &Standard_Allocate);
}
