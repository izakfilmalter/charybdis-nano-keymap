# Charybdis Nano Keymap

Local QMK/VIA keymap for my BastardKB Charybdis Nano (3x5) Splinky.

## Hardware Repair

The right-hand `O/L/.` column is repaired by moving that logical column to the otherwise-unused `C1`/`GP27` pin on the universal MCU board.

The bodge wire should connect:

```text
right-hand O/L/. column  ->  C1 / GP27 on MCU board
```

Firmware override:

```c
#define MATRIX_COL_PINS_RIGHT { GP28, GP27, GP6, GP7, GP8 }
```

For the Nano/3x5 right side, visual columns map to QMK matrix columns as:

```text
P / ; / /  = matrix col 0 = GP28
O / L / .  = matrix col 1 = GP27, repaired from GP21
I / K / ,  = matrix col 2 = GP6
U / J / M  = matrix col 3 = GP7
Y / H / N  = matrix col 4 = GP8
```

## QMK Setup

Use the BastardKB QMK fork on `bkb-master`:

```sh
git clone https://github.com/Bastardkb/bastardkb-qmk.git
cd bastardkb-qmk
git checkout bkb-master
git submodule update --init --recursive
```

Copy `keymaps/izak` into:

```text
keyboards/bastardkb/charybdis/3x5/keymaps/izak
```

Build:

```sh
PATH="/opt/homebrew/opt/arm-none-eabi-binutils/bin:/opt/homebrew/opt/arm-none-eabi-gcc@8/bin:$PATH" qmk compile -kb bastardkb/charybdis/3x5 -km izak
```

Flash the generated UF2:

```text
bastardkb_charybdis_3x5_izak.uf2
```

## VIA

This firmware enables VIA and reserves 7 dynamic layers.

After flashing, import:

```text
via/charybdis_nano.layout.json
```

## Current Timing

```c
#define TAPPING_TERM 150
```

## Trackball Scroll

Vertical drag-scroll is reversed:

```c
#define CHARYBDIS_DRAGSCROLL_REVERSE_Y
```
