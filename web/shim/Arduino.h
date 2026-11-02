// Part of the browser version of Dodgeball. The files in this folder are
// derived from the Meggy Jr Simplified library, Copyright (c) 2010
// Windell H. Oskay, Evil Mad Scientist Laboratories, and like it are
// licensed under the GNU General Public License, version 3 or later.
// See COPYING in this folder.
//
// Minimal stand-in for the Arduino core, just enough for Dodgeball.ino
// to compile to WebAssembly. Timing and randomness behave like an
// Arduino Uno-class board (ATmega328, avr-libc).
#ifndef MEGGY_WEB_ARDUINO_H
#define MEGGY_WEB_ARDUINO_H

#include <stdint.h>

typedef uint8_t byte;
typedef bool boolean;

#define HIGH 1
#define LOW 0

extern "C" {
void delay(unsigned long ms);
unsigned long millis(void);
void *memset(void *dest, int c, unsigned long n);
void *memcpy(void *dest, const void *src, unsigned long n);
}

// Arduino's random(): avr-libc's Park-Miller generator, seeded with 1 at
// power-on unless randomSeed() is called. The sketch never calls
// randomSeed(), so opponents move in the same pattern every power-on,
// exactly as on the real handheld.
long random(long howbig);
long random(long howsmall, long howbig);
void randomSeed(unsigned long seed);

#endif
