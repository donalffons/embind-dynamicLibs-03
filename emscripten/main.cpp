#include <iostream>
#include <dlfcn.h>
#include <Standard.hxx>

extern "C" {
  void loadLib1() {
    std::cout << "==> Start loading lib 1" << std::endl;
    dlopen("/library1.wasm", RTLD_NOW | RTLD_GLOBAL);
    std::cout << "<== Finished loading lib 1" << std::endl;
  }
  void loadLib2() {
    std::cout << "==> Start loading lib 2" << std::endl;
    dlopen("/library2.wasm", RTLD_NOW | RTLD_GLOBAL);
    std::cout << "<== Finished loading lib 2" << std::endl;
  }
}

int main() {
  std::cout << "Hello, World!" << std::endl;
}
