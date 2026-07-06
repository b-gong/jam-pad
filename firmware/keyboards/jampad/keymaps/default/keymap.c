#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Physical orientation:
     *
     *  7 8 9
     *  4 5 6    Encoder press: 0
     *  1 2 3
     *
     * The schematic matrix is rotated 90 degrees clockwise from this view,
     * so the LAYOUT macro in keyboard.json maps physical order to GPIO order.
     */
    [0] = LAYOUT(
        KC_KP_7, KC_KP_8, KC_KP_9,
        KC_KP_4, KC_KP_5, KC_KP_6,
        KC_KP_1, KC_KP_2, KC_KP_3,
        KC_KP_0
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        tap_code(clockwise ? KC_UP : KC_DOWN);
    }

    return false;
}

void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);

    // Six-color ring test. LED 0 is the 1 o'clock LED; the chain runs clockwise.
    rgblight_setrgb_at(80, 0, 0, 0);
    rgblight_setrgb_at(80, 32, 0, 1);
    rgblight_setrgb_at(80, 80, 0, 2);
    rgblight_setrgb_at(0, 80, 0, 3);
    rgblight_setrgb_at(0, 0, 80, 4);
    rgblight_setrgb_at(48, 0, 80, 5);
#endif
}
