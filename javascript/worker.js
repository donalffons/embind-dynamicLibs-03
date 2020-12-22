import main from '/emscripten/build/main.js';

globalThis.setImmediate = () => {}

(async () => {
  const o = await main({
    locateFile: f => "/emscripten/build/main.wasm",
    dynamicLibraries: [],
    noInitialRun: true,
  });
  const library1 = new Int8Array(await (await fetch("/emscripten/build/library1.wasm")).arrayBuffer());
  o.FS.writeFile("/library1.wasm", library1);
  const library2 = new Int8Array(await (await fetch("/emscripten/build/library2.wasm")).arrayBuffer());
  o.FS.writeFile("/library2.wasm", library2);
  o.callMain();
  o.ccall("loadLib1");
  o.ccall("loadLib2");
  setTimeout(() => {
    postMessage("");
  }, 100);
})();
