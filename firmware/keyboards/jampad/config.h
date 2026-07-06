#pragma once

// GPIO9 drives the six-LED ring around the encoder. GPIO8 is configured in
// keyboard.json for the nine per-key RGB Matrix LEDs.
#define RGBLIGHT_DI_PIN GP9

// Make RGB_MATRIX_TYPING_HEATMAP read well on the small 3x3 grid. The default
// spread is too narrow for the jampad's LED coordinates, so neighboring keys
// barely warm up.
#define RGB_MATRIX_TYPING_HEATMAP_INCREASE_STEP 48
#define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 30
#define RGB_MATRIX_TYPING_HEATMAP_SPREAD 130
#define RGB_MATRIX_TYPING_HEATMAP_AREA_LIMIT 24
