# project specific files
SRC += rand.c

# MCU name
MCU = SN32F268F

# Custom Key and LED matrix handling
CUSTOM_MATRIX = yes
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = SN32F26x
RGB_MATRIX_CUSTOM_KB = yes

# Reduce code size
USE_PROCESS_STACKSIZE = 0x1E0
USE_EXCEPTIONS_STACKSIZE = 0xF0
