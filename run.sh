#!/bin/sh

cd emscripten && ./build.sh && cd ..

npx serve
