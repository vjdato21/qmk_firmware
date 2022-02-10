# project specific files
SRC = ../../../drivers/led/sn32/matrix_sn32f24xx.c
SRC += rand.c

# MCU name
MCU = SN32F268F

# Custom Key and LED matrix handling
CUSTOM_MATRIX = yes
LED_MATRIX_ENABLE = yes
LED_MATRIX_DRIVER = SN32F26x

# Reduce code size
USE_PROCESS_STACKSIZE = 0x1E0
USE_EXCEPTIONS_STACKSIZE = 0xF0
