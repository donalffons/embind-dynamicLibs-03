mkdir -p build

emcc \
  --bind embind_library1.cpp \
  ./library1.cxx \
  -I./globalIncludes \
  -s SIDE_MODULE=1 \
  -s ASSERTIONS=1 \
  -s EXPORT_ALL=1 \
  -o ./build/library1.wasm

emcc \
  --bind embind_empty.cpp \
  ./library2.cxx \
  -I./globalIncludes \
  -s SIDE_MODULE=1 \
  -s ASSERTIONS=1 \
  -o ./build/library2.wasm

emcc \
  --bind embind_empty.cpp \
  -I./globalIncludes \
  main.cpp \
  -s EXPORT_ES6=1 \
  -s USE_ES6_IMPORT_META=0 \
  -s MAIN_MODULE=1 \
  -s ASSERTIONS=1 \
  -s EXTRA_EXPORTED_RUNTIME_METHODS=['callMain','ccall'] \
  -o ./build/main.js
