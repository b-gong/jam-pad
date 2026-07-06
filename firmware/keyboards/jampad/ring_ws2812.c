#ifdef RGBLIGHT_ENABLE

#include "rgblight.h"

/*
 * QMK's RP2040 WS2812 driver is normally single-chain. This mirrors the
 * Work Louder custom RGBLight pattern, but uses the RP2040 PIO vendor driver
 * instead of bitbang so it is valid on this MCU.
 */
#undef WS2812_DI_PIN
#define WS2812_DI_PIN RGBLIGHT_DI_PIN

#define RGBLIGHT_WS2812

#define ws2812_init jampad_ring_ws2812_init
#define ws2812_set_color jampad_ring_ws2812_set_color
#define ws2812_set_color_all jampad_ring_ws2812_set_color_all
#define ws2812_flush jampad_ring_ws2812_flush
#define ws2812_leds jampad_ring_ws2812_leds

#include "ws2812_vendor.c"

const rgblight_driver_t rgblight_driver = {
    .init          = jampad_ring_ws2812_init,
    .set_color     = jampad_ring_ws2812_set_color,
    .set_color_all = jampad_ring_ws2812_set_color_all,
    .flush         = jampad_ring_ws2812_flush,
};

#endif
