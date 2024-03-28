/* Copyright 2022 durken (https://github.com/durken1/)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "quantum.h"
#include "spi_master.h"
#include "matrix.h"
#include "print.h"
#include <string.h> /* memset */

void matrix_init_custom(void) {
    spi_init();
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    static matrix_row_t temp_matrix[MATRIX_ROWS] = {0};
    spi_status_t        read_result[8]           = {0};

    // recieve the matrix status from SPI
    spi_start(GP17, true, 0, 32);
    // spi_receive((uint8_t *)temp_matrix, 8);
    for (int i = 0; i < 7; ++i) {
        spi_write(i);
        read_result[i] = spi_read();
    }
    temp_matrix[0] = (matrix_row_t)read_result[1] << 8 | (matrix_row_t)read_result[0];
    temp_matrix[1] = (matrix_row_t)read_result[3] << 8 | (matrix_row_t)read_result[2];
    temp_matrix[2] = (matrix_row_t)read_result[5] << 8 | (matrix_row_t)read_result[4];
    temp_matrix[3] = (matrix_row_t)read_result[6];
    spi_stop();

    // Check if we've changed, return the last-read data
    bool changed = memcmp(current_matrix, temp_matrix, sizeof(temp_matrix)) != 0;
    if (changed) {
        memcpy(current_matrix, temp_matrix, sizeof(temp_matrix));
        // debug
        uprintf("first row: %u\n", current_matrix[0]);
    }
    return changed;
}
