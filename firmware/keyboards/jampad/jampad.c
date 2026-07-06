#include "quantum.h"

#define JAMPAD_ENCODER_COMMON_PIN GP13
#define JAMPAD_ENCODER_A_PIN GP12
#define JAMPAD_ENCODER_B_PIN GP14

void keyboard_pre_init_kb(void) {
    // The encoder common pin is wired to GP13 instead of GND.
    gpio_set_pin_output(JAMPAD_ENCODER_COMMON_PIN);
    gpio_write_pin_low(JAMPAD_ENCODER_COMMON_PIN);

    keyboard_pre_init_user();
}

#ifdef ENCODER_ENABLE
void encoder_quadrature_init_pin(uint8_t index, bool pad_b) {
    if (index != 0) {
        return;
    }

    gpio_set_pin_output(JAMPAD_ENCODER_COMMON_PIN);
    gpio_write_pin_low(JAMPAD_ENCODER_COMMON_PIN);
    gpio_set_pin_input_high(pad_b ? JAMPAD_ENCODER_B_PIN : JAMPAD_ENCODER_A_PIN);
}

uint8_t encoder_quadrature_read_pin(uint8_t index, bool pad_b) {
    if (index != 0) {
        return 0;
    }

    gpio_write_pin_low(JAMPAD_ENCODER_COMMON_PIN);
    return gpio_read_pin(pad_b ? JAMPAD_ENCODER_B_PIN : JAMPAD_ENCODER_A_PIN) ? 1 : 0;
}
#endif
