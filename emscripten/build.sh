mkdir -p build

emcc \
  --bind ./empty-embind.cpp \
  -s ENVIRONMENT='web' \
  -s EXPORT_ES6=1 \
  -s USE_ES6_IMPORT_META=0 \
  -s MAIN_MODULE=1 \
  -s ASSERTIONS=1 \
  -I./globalIncludes \
  -o ./build/main.js

emcc \
  -I./globalIncludes \
  --bind ./empty-embind.cpp \
  -s SIDE_MODULE=1 \
  -s ASSERTIONS=1 \
  ./Standard.cxx \
  ./Standard_MMgrRaw.cxx \
  -o ./build/library1.wasm

emcc \
  -I./globalIncludes \
  --bind ./empty-embind.cpp \
  -s SIDE_MODULE=1 \
  -s ASSERTIONS=1 \
  ./library2.cxx \
  -o ./build/library2.wasm
