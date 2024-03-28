# This file intentionally left blank
# Bootloader selection
BOOTLOADER = rp2040

QUANTUM_LIB_SRC += spi_master.c
CUSTOM_MATRIX = lite
SPI_DRIVER_REQUIRED = yes
SRC += matrix.c
BOARD = GENERIC_RP_RP2040