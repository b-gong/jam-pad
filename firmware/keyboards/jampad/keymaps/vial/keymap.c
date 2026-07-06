#include QMK_KEYBOARD_H

#define ___ KC_TRNS

#ifdef RGBLIGHT_ENABLE
static void set_encoder_ring_for_effective_layer(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case 1:
            rgblight_sethsv_noeeprom(HSV_GREEN);
            break;
        case 2:
            rgblight_sethsv_noeeprom(HSV_ORANGE);
            break;
        case 3:
            rgblight_sethsv_noeeprom(HSV_MAGENTA);
            break;
        default:
            rgblight_sethsv_noeeprom(HSV_BLUE);
            break;
    }
}
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_KP_7, KC_KP_8, KC_KP_9,
        KC_KP_4, KC_KP_5, KC_KP_6,
        KC_KP_1, KC_KP_2, KC_KP_3,
        TO(1)
    ),
    [1] = LAYOUT(
        ___, ___, ___,
        ___, ___, ___,
        ___, ___, ___,
        TO(0)
    ),
    [2] = LAYOUT(
        ___, ___, ___,
        ___, ___, ___,
        ___, ___, ___,
        ___
    ),
    [3] = LAYOUT(
        ___, ___, ___,
        ___, ___, ___,
        ___, ___, ___,
        ___
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = {ENCODER_CCW_CW(KC_UP, KC_DOWN)},
    [1] = {ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)},
    [2] = {ENCODER_CCW_CW(___, ___)},
    [3] = {ENCODER_CCW_CW(___, ___)}
};
#endif

void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    set_encoder_ring_for_effective_layer(default_layer_state | layer_state);
#endif
}

layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    set_encoder_ring_for_effective_layer(default_layer_state | state);
#endif

    return state;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    set_encoder_ring_for_effective_layer(state | layer_state);
#endif

    return state;
}
