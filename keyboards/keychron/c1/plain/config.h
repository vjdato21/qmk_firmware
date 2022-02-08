/* USB Device descriptor parameter */
#define DESCRIPTION                 Keychron \x43\x31 Plain

#define USB_MAX_POWER_CONSUMPTION   100

/* key matrix size */
#define MATRIX_ROWS                 6
#define MATRIX_COLS                 17

#define DIODE_DIRECTION             COL2ROW

#define MATRIX_COL_PINS             { A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, D0 }
#define MATRIX_ROW_PINS             { C3, C4, C5, C6, C7, C8 }

/* Keep LED Matrix pins so that we can set them low */
#define LED_MATRIX_ROW_PINS         { C0, C1, C2, D4, C9, C10 }

/* Connects each switch in the dip switch to the GPIO pin of the MCU */
#define DIP_SWITCH_PINS             { D7 }

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE                    5

/* LED Status indicators */
#define LED_CAPS_LOCK_PIN           B3
#define LED_PIN_ON_STATE            1

#define LED_MAC_PIN                 B4
#define LED_WIN_PIN                 B5

/* VIA configs */
#define DYNAMIC_KEYMAP_LAYER_COUNT     4
#define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR 1000
