# Dodgeball in the browser

This folder runs the original `../Dodgeball.ino` in a web page. The sketch itself is not edited: it is compiled to WebAssembly against a stand-in for the Meggy Jr library, and the page plays the part of the hardware.

| File | What it is |
|---|---|
| `shim/MeggyJrSimple.h` | Same API and constants as the Meggy Jr Simplified library (v1.4) |
| `shim/Arduino.h` | The few Arduino core pieces the sketch uses (`byte`, `delay`, `random`) |
| `shim/meggy_web.cpp` | The library implementation, talking to the page instead of AVR hardware |
| `index.html` | The handheld: 8×8 LED screen, aux LEDs, buttons, piezo sound |
| `dodgeball.wasm` | The compiled sketch (committed so the page can be served as-is) |
| `build.sh` | Rebuilds `dodgeball.wasm` |

## Play locally

Browsers won't load WebAssembly from a `file://` page, so serve the folder:

```
cd web
python3 -m http.server
```

Then open http://localhost:8000.

## Rebuild

```
brew install llvm lld  # Apple's clang has no WebAssembly target
cd web && npm install  # Binaryen's wasm-opt
./build.sh
```

## How it works

- **Compiling:** like the Arduino IDE, `build.sh` adds a prototype for each function in the sketch, then compiles it with clang for `wasm32`.
- **Blocking calls:** the sketch waits with `delay()` and `while (MakingSound) {}`. Binaryen's Asyncify pass lets those calls pause the program and hand control back to the browser, then resume where they left off.
- **Colors:** the library stores LED brightness levels 0–15 per channel (values above 15 are fully on), and its LEDs are unbalanced: its own white is (3, 15, 2). The page scales each channel to match the library's palette, so colors approximate the real screen.
- **Randomness:** `random()` uses the same generator as avr-libc, seeded the same way, so opponents follow the same pattern every power-on, as on the hardware.

## Differences from the hardware

- `DrawPx` off the screen (the sketch parks inactive opponents at x = 8) is ignored. The real library writes past its pixel array.
- `int` is 32 bits here and 16 bits on the ATmega328. The only effect would be a stage counter overflowing after about 38 minutes on one stage.
- A button tapped between the sketch's input checks (about every 70 ms) still counts, so keyboard taps aren't missed.

## License

The game (`../Dodgeball.ino`) is my own code. The files in `shim/` are derived from the Meggy Jr Simplified library by Windell H. Oskay (Evil Mad Scientist Laboratories), which is licensed under the GNU GPL v3, so those files are GPL v3 or later as well. See `shim/COPYING`.
