Build: `docker build -t test .`

Run: `docker run -it --net=host -v "$(pwd)":"/app/" test`

Visit: `http://localhost:5000/javascript/`

This example runs Emscripten WASM-instantiation in an infinite loop until the error occurs.

Problem:

Current build configuration yields:

```
main.js:1529 Uncaught (in promise) RuntimeError: abort(Assertion failed: old table entries must remain the same) at Error
    at jsStackTrace (https://embind-dynamic-libs-02-git-master.donalffons.vercel.app/emscripten/build/main.js:1782:19)
    at stackTrace (https://embind-dynamic-libs-02-git-master.donalffons.vercel.app/emscripten/build/main.js:2297:16)
    at abort (https://embind-dynamic-libs-02-git-master.donalffons.vercel.app/emscripten/build/main.js:1523:44)
    at assert (https://embind-dynamic-libs-02-git-master.donalffons.vercel.app/emscripten/build/main.js:701:5)
    at postInstantiation (https://embind-dynamic-libs-02-git-master.donalffons.vercel.app/emscripten/build/main.js:2059:13)
    at https://embind-dynamic-libs-02-git-master.donalffons.vercel.app/emscripten/build/main.js:2084:20
    at async Promise.all (index 1)
    at abort (https://embind-dynamic-libs-02-git-master.donalffons.vercel.app/emscripten/build/main.js:1529:11)
    at assert (https://embind-dynamic-libs-02-git-master.donalffons.vercel.app/emscripten/build/main.js:701:5)
    at postInstantiation (https://embind-dynamic-libs-02-git-master.donalffons.vercel.app/emscripten/build/main.js:2059:13)
    at https://embind-dynamic-libs-02-git-master.donalffons.vercel.app/emscripten/build/main.js:2084:20
    at async Promise.all (index 1)
```
