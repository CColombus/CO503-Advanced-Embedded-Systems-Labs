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
    uint32_t base_address = 0x10000;
    char buffer[100]; // Adjust size as needed
    read_sentence_from_memory(buffer, base_address, sizeof(buffer));
    printf("Read sentence: %s\n", buffer);
    return 0;
}
