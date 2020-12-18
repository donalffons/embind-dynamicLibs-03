mkdir -p build

emcc \
  -I./globalIncludes \
  --bind ./empty-embind.cpp \
  -s ENVIRONMENT='web' \
  -s EXPORT_ES6=1 \
  -s USE_ES6_IMPORT_META=0 \
  -s MAIN_MODULE=1 \
  -s ASSERTIONS=1 \
  -o ./build/main.js

emcc \
  ./library1.cxx \
  -I./globalIncludes \
  --bind ./empty-embind.cpp \
  -s SIDE_MODULE=1 \
  -s ASSERTIONS=1 \
  -o ./build/library1.wasm

emcc \
  ./library2.cxx \
  -I./globalIncludes \
  --bind ./empty-embind.cpp \
  -s SIDE_MODULE=1 \
  -s ASSERTIONS=1 \
  -o ./build/library2.wasm
