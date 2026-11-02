// Part of the browser version of Dodgeball. The files in this folder are
// derived from the Meggy Jr Simplified library, Copyright (c) 2010
// Windell H. Oskay, Evil Mad Scientist Laboratories, and like it are
// licensed under the GNU General Public License, version 3 or later.
// See COPYING in this folder.
//
// Implementation of the browser Meggy Jr: the sketch's view of the hardware
// lives here, and everything physical (pixels, buttons, piezo, time) is
// handed to JavaScript through a few imported functions.
#include "MeggyJrSimple.h"

#define IMPORT(name) __attribute__((import_module("env"), import_name(#name)))

extern "C" {
// Provided by index.html. The three marked "pauses" are made resumable by
// Binaryen's Asyncify pass, so a blocking delay() in the sketch hands
// control back to the browser instead of freezing the tab.
IMPORT(js_delay)      void js_delay(unsigned long ms);      // pauses
IMPORT(js_wait_sound) int  js_wait_sound(void);             // pauses
IMPORT(js_loop_yield) void js_loop_yield(void);             // pauses
IMPORT(js_millis)     unsigned long js_millis(void);
IMPORT(js_buttons)    int  js_buttons(void);
IMPORT(js_tone)       void js_tone(unsigned int divisor, unsigned int ms);
IMPORT(js_display)    void js_display(const byte *rgb);    // 8x8x3, x-major
IMPORT(js_aux)        void js_aux(int leds);
}

// ---- Arduino core bits ---------------------------------------------------

extern "C" void delay(unsigned long ms) { js_delay(ms); }
extern "C" unsigned long millis(void) { return js_millis(); }

extern "C" void *memset(void *dest, int c, unsigned long n) {
  byte *d = (byte *)dest;
  while (n--) *d++ = (byte)c;
  return dest;
}
extern "C" void *memcpy(void *dest, const void *src, unsigned long n) {
  byte *d = (byte *)dest;
  const byte *s = (const byte *)src;
  while (n--) *d++ = *s++;
  return dest;
}

// avr-libc random(): Park-Miller "minimal standard" generator.
static unsigned long rand_next = 1;
static long do_random(unsigned long *ctx) {
  long hi, lo, x;
  x = *ctx;
  if (x == 0) x = 123459876L;
  hi = x / 127773L;
  lo = x % 127773L;
  x = 16807L * lo - 2836L * hi;
  if (x < 0) x += 0x7fffffffL;
  return ((*ctx = x) % ((unsigned long)0x7fffffffL + 1));
}
long random(long howbig) {
  if (howbig == 0) return 0;
  return do_random(&rand_next) % howbig;
}
long random(long howsmall, long howbig) {
  if (howsmall >= howbig) return howsmall;
  return random(howbig - howsmall) + howsmall;
}
void randomSeed(unsigned long seed) {
  if (seed != 0) rand_next = seed;
}

// ---- MeggyJrSimple -------------------------------------------------------

byte Button_A, Button_B, Button_Up, Button_Down, Button_Left, Button_Right;
byte GameSlate[8][8];
static byte lastButtonState;

// Default palette from MeggyJr.h. Channel values are LED brightness
// levels 0-15 (anything above 15 is simply fully on).
static byte ColorTable[26][3] = {
  {0, 0, 0},   {6, 0, 0},  {12, 5, 0}, {7, 10, 0}, {0, 15, 0}, {0, 0, 5},
  {8, 0, 4},   {3, 15, 2}, {1, 0, 0},  {1, 1, 0},  {1, 1, 0},  {0, 1, 0},
  {0, 3, 1},   {0, 0, 1},  {2, 0, 1},  {15, 15, 15},
  {0, 0, 0},   {0, 0, 0},  {0, 0, 0},  {0, 0, 0},  {0, 0, 0},
  {0, 0, 0},   {0, 0, 0},  {0, 0, 0},  {0, 0, 0},  {0, 0, 0},
};

static void setButtons(byte i) {
  Button_B = (i & 1);
  Button_A = (i & 2);
  Button_Up = (i & 4);
  Button_Down = (i & 8);
  Button_Left = (i & 16);
  Button_Right = (i & 32);
}

byte GetButtons(void) { return (byte)(js_buttons() & 63); }

void MeggyJrSimpleSetup(void) {
  lastButtonState = GetButtons();
  js_tone(0, 0);
}

void CheckButtonsDown(void) {
  byte i = GetButtons();
  setButtons(i);
  lastButtonState = i;
}

void CheckButtonsPress(void) {
  byte i = GetButtons();
  setButtons(i & ~lastButtonState);
  lastButtonState = i;
}

void SetAuxLEDs(byte InputLEDs) { js_aux(InputLEDs); }

void SetAuxLEDsBinary(byte n) {
  n = (n & 240) >> 4 | (n & 15) << 4;
  n = (n & 204) >> 2 | (n & 51) << 2;
  js_aux((n & 170) >> 1 | (n & 85) << 1);
}

// The original writes GameSlate[x][y] with no bounds check, so drawing at
// x = 8 (where Dodgeball parks inactive opponents) scribbles past the
// array. Off-screen pixels are dropped here instead.
void DrawPx(byte xin, byte yin, byte color) {
  if (xin < 8 && yin < 8) GameSlate[xin][yin] = color;
}
void SafeDrawPx(byte xin, byte yin, byte color) { DrawPx(xin, yin, color); }

byte ReadPx(byte xin, byte yin) {
  return (xin < 8 && yin < 8) ? GameSlate[xin][yin] : 0;
}

void ClearSlate(void) { memset(GameSlate, 0, sizeof GameSlate); }

void DisplaySlate(void) {
  static byte frame[8][8][3];
  for (int x = 0; x < 8; x++)
    for (int y = 0; y < 8; y++) {
      byte c = GameSlate[x][y];
      const byte *rgb = ColorTable[c < 26 ? c : 0];
      frame[x][y][0] = rgb[0];
      frame[x][y][1] = rgb[1];
      frame[x][y][2] = rgb[2];
    }
  js_display(&frame[0][0][0]);
}

void EditColor(byte WhichColor, byte RedComponent, byte GreenComponent, byte BlueComponent) {
  if (WhichColor >= 26) return;
  ColorTable[WhichColor][0] = RedComponent;
  ColorTable[WhichColor][1] = GreenComponent;
  ColorTable[WhichColor][2] = BlueComponent;
}

void Tone_Start(unsigned int divisor, unsigned int duration_ms) {
  js_tone(divisor, duration_ms);
}

bool Meggy_MakingSound(void) { return js_wait_sound() != 0; }

void delay_ms(unsigned int time) { delay(time); }

// ---- Entry point ---------------------------------------------------------

void setup();
void loop();

// Scratch space Asyncify uses to save the call stack while the sketch is
// paused: an 8-byte header (start, end) followed by the stack data.
static int asyncify_data[2 + 4096];
extern "C" __attribute__((export_name("asyncify_data_ptr"))) int *asyncify_data_ptr(void) {
  asyncify_data[0] = (int)(unsigned long)&asyncify_data[2];
  asyncify_data[1] = (int)(unsigned long)&asyncify_data[2 + 4096];
  return asyncify_data;
}

// Same shape as the Arduino core's main(): setup() once, then loop() forever.
extern "C" __attribute__((export_name("meggy_run"))) void meggy_run(void) {
  setup();
  for (;;) {
    loop();
    js_loop_yield();
  }
}
