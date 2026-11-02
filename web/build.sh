#!/usr/bin/env bash
# Compiles the original Dodgeball.ino, unchanged, to web/dodgeball.wasm.
#
# Needs: clang with the wasm32 target plus wasm-ld (on macOS: `brew install llvm lld`,
# since Apple's own clang has no WebAssembly target), and Node for Binaryen's
# wasm-opt (`npm install` in this folder).
set -euo pipefail
cd "$(dirname "$0")"

# Use $CLANG if set, else Homebrew's LLVM on a Mac, else whatever clang is on PATH.
if [ -z "${CLANG:-}" ]; then
  CLANG=clang
  for c in /opt/homebrew/opt/llvm/bin/clang /usr/local/opt/llvm/bin/clang; do
    if [ -x "$c" ]; then CLANG="$c"; break; fi
  done
fi

mkdir -p build

# The Arduino IDE adds a prototype for every function in a sketch before
# compiling it, so a .ino can call functions defined further down. Do the same.
{
  echo '#include <Arduino.h>'
  echo '#include <MeggyJrSimple.h>'
  grep -E '^[[:space:]]*(void|int|byte|bool|boolean|long|unsigned int|float)[[:space:]]+[A-Za-z_][A-Za-z0-9_]*[[:space:]]*\([^;]*\)' ../Dodgeball.ino \
    | sed -E 's/\).*/);/'
  echo '#line 1 "Dodgeball.ino"'
  echo '#include "Dodgeball.ino"'
} > build/sketch.cpp

FLAGS=(--target=wasm32 -O2 -nostdlib -ffreestanding -fno-exceptions -fno-rtti
       -fno-threadsafe-statics -Ishim -I.. -w)

"$CLANG" "${FLAGS[@]}" -x c++ build/sketch.cpp shim/meggy_web.cpp \
  -Wl,--no-entry -Wl,--strip-all -o build/dodgeball.raw.wasm

# Asyncify lets delay() and `while (MakingSound) {}` pause the sketch and
# return to the browser, then resume exactly where it left off.
npx --no-install wasm-opt build/dodgeball.raw.wasm -O2 --asyncify \
  --pass-arg=asyncify-imports@env.js_delay,env.js_wait_sound,env.js_loop_yield \
  -o dodgeball.wasm

echo "Built web/dodgeball.wasm ($(wc -c < dodgeball.wasm | tr -d ' ') bytes)"
