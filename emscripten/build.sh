mkdir -p build

emcc \
  --bind ./empty-embind.cpp \
  -s ENVIRONMENT='web' \
  -s EXPORT_ES6=1 \
  -s USE_ES6_IMPORT_META=0 \
  -s MAIN_MODULE=1 \
  -s ALLOW_MEMORY_GROWTH=1 \
  -o ./build/main.js

emcc \
  ./library1.cpp \
  --bind ./empty-embind.cpp \
  -s SIDE_MODULE=1 \
  -o ./build/library1.wasm

emcc \
  --bind ./empty-embind.cpp \
  -s SIDE_MODULE=1 \
  -o ./build/library2.wasm
