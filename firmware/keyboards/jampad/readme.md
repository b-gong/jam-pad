# jampad

QMK firmware definition for the jam-pad RP2040 macropad.

## Hardware Notes

- Matrix rows: `GP0`, `GP1`, `GP2`
- Matrix columns: `GP3`, `GP4`, `GP5`, `GP6`
- Encoder: A on `GP12`, B on `GP14`
- Encoder pushbutton: matrix position row 0, column 3
- Per-key WS2812/SK6812 chain: `GP8`
- Encoder ring WS2812 chain: `GP9`

The 3x3 switch matrix is physically rotated 90 degrees counterclockwise from
the schematic, so the `LAYOUT` macro is defined in physical numpad order.

## Build

Copy `keyboards/jampad` into a QMK firmware checkout, then build with:

```sh
qmk compile -kb jampad -km default
```

or:

```sh
make jampad:default
```

## Vial

Copy `keyboards/jampad` into a `vial-qmk` checkout, then build with:

```sh
make jampad:vial
```

The Vial unlock combo is physical `1` + `9`.

Hold the encoder pushbutton while plugging in to trigger Bootmagic.
