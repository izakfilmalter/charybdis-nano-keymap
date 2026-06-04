#pragma once

// Hardware repair for the right half: the physical C3 input is bad, so the
// O/L/. column is jumpered to the otherwise-unused C1 pin on the MCU board.
// On the 3x5 layout, right-hand visual columns map to matrix columns as:
// P=0, O=1, I=2, U=3, Y=4. Replace O/L/. (matrix col 1) with GP27.
#define MATRIX_COL_PINS_RIGHT { GP28, GP27, GP6, GP7, GP8 }

// Keep enough dynamic layers for the saved VIA layout JSON.
#define DYNAMIC_KEYMAP_LAYER_COUNT 7

// Home-row mod-tap timing.
#define TAPPING_TERM 150
