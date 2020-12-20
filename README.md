Build: `docker build -t test .`

Run: `docker run -it --net=host -v "$(pwd)":"/app/" test`

Visit: `http://localhost:5000/javascript/`

This example runs Emscripten WASM-instantiation in an infinite loop until the error occurs.

Problem:

Current build configuration yields:

```
Uncaught (in promise) RuntimeError: function signature mismatch
    at _ZN8Standard8AllocateEm (<anonymous>:wasm-function[23]:0x1379)
    at obj.<computed> (https://embind-dynamic-libs-03-git-master.donalffons.vercel.app/emscripten/build/main.js:2037:31)
    at _ZN18Standard_TransientnwEm (<anonymous>:wasm-function[4]:0x200)
    at <anonymous>:wasm-function[3]:0x1c8
    at <anonymous>:wasm-function[5]:0x219
    at __post_instantiate (<anonymous>:wasm-function[1]:0x1b6)
    at callRuntimeCallbacks (https://embind-dynamic-libs-03-git-master.donalffons.vercel.app/emscripten/build/main.js:1747:11)
    at initRuntime (https://embind-dynamic-libs-03-git-master.donalffons.vercel.app/emscripten/build/main.js:1361:3)
    at doRun (https://embind-dynamic-libs-03-git-master.donalffons.vercel.app/emscripten/build/main.js:52650:5)
    at run (https://embind-dynamic-libs-03-git-master.donalffons.vercel.app/emscripten/build/main.js:52672:5)
```
