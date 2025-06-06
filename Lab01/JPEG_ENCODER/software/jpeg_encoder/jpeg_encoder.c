/*************************************************************************************
 * CO503 Advanced Embedded Systems
 *
 * Date			: 16-08-2016
 * Author 		: Isuru Nawinne
 * Edited by	:
 *
 * Description	: Compress and convert a BMP image file into JPEG format
 *
 *************************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <io.h>
#include <unistd.h>

#include "application/jpeg_encoding.h"
#include "application/bmp_extract.h"

#define NO_OF_FILES 7

#define LED_BASE 0x09001010 // INSERT BASE ADDRESS OF "led_out" PIO DEVICE FROM QSYS
#define OFFSET 0x00000000


void convert_picture(const char *jtag_input);


int main()
{
	char jtag_input[20];

	// Print that welcome message. Programmers looove welcome messages! ;)
	printf("Welcome to CO503 JPEG Encoder! \n\n");

	int j = 0;
	for (j = 0; j <= 7; j++) {
		IOWR_8DIRECT(LED_BASE, OFFSET, 1 << j);
		usleep(30000);
	}
	IOWR_8DIRECT(LED_BASE, OFFSET, 0b00000000);

	while(1) {
		printf("Input file: ");
		IOWR_8DIRECT(LED_BASE, OFFSET, 0b00000001); // Waiting indicator
		scanf("%s", jtag_input); // Ask for the input BMP file

		if (strcmp(jtag_input, "exit") == 0) {
			IOWR_8DIRECT(LED_BASE, OFFSET, 0b00000111); // Finished indicator
			return 0;
		}
		// Check if the filename ends in '.bmp'
		else if(strcmp(&jtag_input[strlen(jtag_input) - 4], ".bmp") == 0) {
			IOWR_8DIRECT(LED_BASE, OFFSET, 0b00000011); // Encoding indicator
			convert_picture(jtag_input); // See function at the bottom

		}
		printf("\n\n");
	}

	IOWR_8DIRECT(LED_BASE, OFFSET, 0b00000111); // Finished indicator
	return 0;
}

/*
 * Convert a BMP picture of name <jtag_input> into JPEG.
 */
void convert_picture(const char *jtag_input)
{
	char file_name[80] = "/mnt/host/files/";
	char destination[80] = "/mnt/host/files/";
	Bmp_data pic_data;

	strcat(file_name, jtag_input);
	strcat(destination, jtag_input);

	// Replace the '.bmp' with '.jpg'
	strcpy(&destination[strlen(destination) - 3], "jpg");

	if(bmp_extract(file_name, &pic_data) == 0) {
		// Convert to JPEG. This is where the magic happens!
		jpeg_encode(destination, pic_data.bitmap, pic_data.header->BMPHeight, pic_data.header->BMPWidth, 90);
	} else {
		// An error has happened
	}
}
