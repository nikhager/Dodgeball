# Dodgeball

A dodgeball game for the [Meggy Jr RGB](https://www.evilmadscientist.com/2008/meggy-jr-rgb/), an 8×8 LED handheld that runs Arduino code. I wrote it for a programming class in 2013–14.

You play on the left side of the court and throw balls at computer opponents on the right while dodging theirs. There are seven stages that add opponents, speed and health. Clear all seven to win.

## Controls

- **D-pad:** move
- **A:** throw
- **Any button** on the win or game-over screen: play again

## Running it

**In a browser:** [play it here](https://nikhager.github.io/Dodgeball/), no hardware needed. The same sketch is compiled as-is to WebAssembly; [`web/`](web/) explains how.

**On the handheld:** open `Dodgeball.ino` in the Arduino IDE with the MeggyJrRGB library installed and upload it to a Meggy Jr RGB.

## Status

This is kept close to the original as a record of early work. A 2026 cleanup fixed two bugs that stopped the last two opponents from throwing, removed a leftover setting that started the game at the boss, and merged duplicated restart code. The planned boss stage was never finished, so the game now ends with a win screen after stage 7 (press any button to play again). The unfinished boss code is kept in the file, commented out.
