/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <io.h>

#include <altera_avalon_fifo_regs.h>
#include <altera_avalon_fifo_util.h>

void read_sentence_from_memory(char *buffer, uint32_t base_address, int max_length) {
    int offset = 0;
    int i = 0;

    while (i < max_length - 1) {
        uint16_t data = IORD_16DIRECT(base_address, offset);
        buffer[i] = (data >> 8) & 0xFF;  // Extract the high byte
        if (buffer[i] == '\0') break;    // Check for null terminator
        i++;
        buffer[i] = data & 0xFF;         // Extract the low byte
        if (buffer[i] == '\0') break;    // Check for null terminator
        i++;
        offset += 2; // Each 16-bit integer occupies 2 bytes of memory
    }
    buffer[i] = '\0'; // Ensure null termination
}

int main() {
    while (1){
// out 0x0000_0088 - 0x0000_008b
// csr 0x0000_0060 - 0x0000_007f
// in  0x0000_00a8 - 0x0000_00ab
    	while (altera_avalon_fifo_read_status(0x00000060,1<<1) != 0)
    		{}

    		// Read the data
    		int data = altera_avalon_fifo_read_fifo(0x00000088,0x00000060);
    		printf("Read: %d\n", data);
    }
    return 0;
}
