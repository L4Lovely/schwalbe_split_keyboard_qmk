#include QMK_KEYBOARD_H
#include "split_util.h" // Add this line
#include "matrix.h"      // Required for matrix_is_modified()
#include "transport.h"

// Define Layer Names
enum layers {
    _BASE,
    _LOWER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base Layer
     * ,---------------------------.         ,---------------------------.
     * |  Q  |  W  |  E  |  R  |  T  |         |  Y  |  U  |  I  |  O  |  P  |
     * |-----|-----|-----|-----|-----|         |-----|-----|-----|-----|-----|
     * |  A  |  S  |  D  |  F  |  G  |         |  H  |  J  |  K  |  L  |  ;  |
     * |-----|-----|-----|-----|-----|         |-----|-----|-----|-----|-----|
     * |  Z  |  X  |  C  |  V  |  B  |         |  N  |  M  |  ,  |  .  |  /  |
     * |-----|-----|-----|-----|-----|         |-----|-----|-----|-----|-----|
     * | ESC | CTL | ALT | LWR | SPC |         | ENT | BKSP| ALT | GUI | DEL |
     * `---------------------------'         `---------------------------'
     */
    [_BASE] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,           KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
        KC_ESC,  KC_LCTL, KC_LALT, MO(_LOWER), KC_SPC,      KC_ENT,  KC_BSPC, KC_RALT, KC_RGUI, KC_DEL
    ),

    /* Lower Layer (Numbers/Symbols)
     * ,---------------------------.         ,---------------------------.
     * |  1  |  2  |  3  |  4  |  5  |         |  6  |  7  |  8  |  9  |  0  |
     * |-----|-----|-----|-----|-----|         |-----|-----|-----|-----|-----|
     * | TAB |     |     |     |     |         | LFT | DWN |  UP | RGT |     |
     * |-----|-----|-----|-----|-----|         |-----|-----|-----|-----|-----|
     * | F1  | F2  | F3  | F4  | F5  |         | F6  | F7  | F8  | F9  | F10 |
     * |-----|-----|-----|-----|-----|         |-----|-----|-----|-----|-----|
     * |     |     |     |     |     |         |     |     |     |     |     |
     * `---------------------------'         `---------------------------'
     */
    [_LOWER] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_TAB,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______
    )
};

// void housekeeping_task_user(void) {
//     gpio_set_pin_output(GP25);
    
//     // If the LED is ON, the two halves are NOT talking.
//     // If the LED is OFF, the UART handshake is successful.
//     if (!is_transport_connected()) {
//         gpio_write_pin(GP25, 1); 
//     } else {
//         gpio_write_pin(GP25, 0);
//     }
// }

void housekeeping_task_user(void) {
    static uint16_t boot_timer = 0;
    static bool booted = false;
    static bool led_initialized = false;

    // init led pin 1x
    if (!led_initialized) {
        gpio_set_pin_output(GP25);
        led_initialized = true;
        boot_timer = timer_read();
    }

    // boot : blink 3 times
    if (!booted) {
        uint16_t elapsed = timer_elapsed(boot_timer);
        if (elapsed < 600) {
            gpio_write_pin(GP25, (elapsed / 100) % 2);
            return; 
        } else {
            gpio_write_pin(GP25, 0);
            booted = true;
        }
    }

    // Normal Status Mode
    if (!is_transport_connected()) {
        gpio_write_pin(GP25, 1); 
    } else {
        gpio_write_pin(GP25, 0);//
    }
}
