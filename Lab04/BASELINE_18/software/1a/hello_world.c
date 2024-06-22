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
#include <string.h>
#include <unistd.h>
#include <io.h>

#include <altera_avalon_fifo_regs.h>
#include <altera_avalon_fifo_util.h>

void write_sentence_to_memory(const char *sentence, uint32_t base_address) {
    int len = strlen(sentence);
    int offset = 0;

    for (int i = 0; i < len; i += 2) {
        uint16_t data = 0;
        if (i + 1 < len) {
            // Combine two characters into one 16-bit integer
            data = (sentence[i] << 8) | sentence[i + 1];
        } else {
            // If there's only one character left, just use it
            data = sentence[i];
        }
        IOWR_16DIRECT(base_address, offset, data);
        offset += 2; // Each 16-bit integer occupies 2 bytes of memory
    }
}

int main() {
    int count = 4;
    // out 0x0000_0088 - 0x0000_008b
    // csr 0x0000_0060 - 0x0000_007f
    // in  0x0000_00a8 - 0x0000_00ab
    while(1){
    	while (altera_avalon_fifo_read_status(0x00000060,1<<0) != 0)
    	{}

    	// Write the data to FIFO
    	altera_avalon_fifo_write_fifo(0x000000a8,0x00000060,(int)count);
    	count += 4;

    	usleep(50000);
    }
}
