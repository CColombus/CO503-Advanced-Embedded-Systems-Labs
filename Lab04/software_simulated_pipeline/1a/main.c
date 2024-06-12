#include <stdio.h>
#include <malloc.h>
#include <time.h>

// #include "prototype.h"	// Function prototypes for main.c 
#include "encoder.h"
#include "queue_wrapper.h"

// COMMON
#include "../lib/datatype.h"
#include "../lib/config.h"

void *jemalloc(size_t size);

int main(int argc, char *argv[])
{

	INT8 input_file_name[150];
	INT8 *input_file_name_ptr;
	UINT32 image_size;
	UINT8 *input;
	FILE *fp, *fpt;

	UINT8 *output_ptr;
	UINT32 quality_factor, image_format, image_width, image_height;

	// TODO: Do the actual implementation.
	QUEUE_INIT();

	fp = fopen("param.txt", "r");
	printf("File Open @ %ld \n", clock());
	while (fscanf(fp, "%s", input_file_name) != EOF)
	{
		input_file_name_ptr = input_file_name;

		while (*input_file_name_ptr != '.')
		{
			SEND6((int)*input_file_name_ptr);
			input_file_name_ptr++;
		}
		SEND6((int)'\0');

		fscanf(fp, "%d", &quality_factor);
		fscanf(fp, "%d", &image_format);
		fscanf(fp, "%d", &image_width);
		fscanf(fp, "%d", &image_height);

		if (image_format == FOUR_ZERO_ZERO)
			image_size = image_width * image_height;
		else if (image_format == FOUR_TWO_ZERO)
			image_size = (image_width * image_height * 3) >> 1;
		else if (image_format == FOUR_TWO_TWO)
			image_size = image_width * image_height * 2;
		else
			image_size = image_width * image_height * 3;

		input = (UINT8 *)jemalloc(2500000 * sizeof(UINT8));
		fpt = fopen(input_file_name, "rb");
		fread(input, 1, image_size, fpt);
		fclose(fpt);

		output_ptr = encode_image(input, output_ptr, quality_factor, image_format, image_width, image_height);

		free(input);
	}

	SEND6((int)0);

	fclose(fp);

	printf("\n Done ! \n");

	// TODO: Do the actual implementation.
	QUEUE_CLOSE();

	return 0;
}

void *jemalloc(size_t size)
{
	return (malloc(size));
}