#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <time.h>

#include "encoder.h"
#include "queue_wrapper.h"

// COMMON
#include "lib/datatype.h"
#include "lib/config.h"

void *jemalloc(size_t size);

stupid

int main()
{
	char file_system[80] = "/mnt/host/files/";
	INT8 input_file_name[150];
	INT8 *input_file_name_ptr;
	UINT32 image_size;
	UINT8 *input;
	FILE *fp, *fpt;

	UINT8 *output_ptr;
	UINT32 quality_factor, image_format, image_width, image_height;

	// TODO: Do the actual implementation.
	char jtag_input[30];
	printf("Enter the name of the parameter file: ");
	scanf("%s", jtag_input);
	char param_file[150];
	strcpy(param_file,file_system);
	strcat(param_file,jtag_input);

	printf("\nGonna look for parameters in: %s\n",param_file);

	fp = fopen(param_file, "r");

	if (fp == NULL)
	{
		printf("Parameter File Open Error!\n");
		return 0;
	}

	while (fscanf(fp, "%s", input_file_name) != EOF)
	{
		input_file_name_ptr = input_file_name;

		while (*input_file_name_ptr != '.')
		{
			SEND6((int)*input_file_name_ptr);
			input_file_name_ptr++;
		}
		SEND6((int)'\0');

		printf("Sent filename to q6.\n");

		fscanf(fp, "%d", &quality_factor);
		fscanf(fp, "%d", &image_format);
		fscanf(fp, "%d", &image_width);
		fscanf(fp, "%d", &image_height);

		// print the parameters and the file name
		printf("File Name: %s\n", input_file_name);
		printf("Quality Factor: %d\n", quality_factor);
		printf("Image Format: %d\n", image_format);
		printf("Image Width: %d\n", image_width);
		printf("Image Height: %d\n", image_height);

		if (image_format == FOUR_ZERO_ZERO)
			image_size = image_width * image_height;
		else if (image_format == FOUR_TWO_ZERO)
			image_size = (image_width * image_height * 3) >> 1;
		else if (image_format == FOUR_TWO_TWO)
			image_size = image_width * image_height * 2;
		else
			image_size = image_width * image_height * 3;

		input = (UINT8 *)jemalloc(2500000 * sizeof(UINT8));

		char input_file_full[150];
		strcpy(input_file_full,file_system);
		strcat(input_file_full,input_file_name);

		fpt = fopen(input_file_full, "rb");

		if (fpt == NULL)
		{
			printf("Raw File Open Error!\n");
			return 0;
		}

		fread(input, 1, image_size, fpt);
		printf("Image file successfully loaded into memory!\n");

		fclose(fpt);

		clock_t start, end;
		double cpu_time_used;

		start = clock();
		output_ptr = encode_image(input, output_ptr, quality_factor, image_format, image_width, image_height);
		end = clock();

		cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

		printf("Time taken: %f sec.\n", cpu_time_used);

		free(input);
	}

	SEND6((int)0);

	fclose(fp);

	printf("\n Done ! \n");

	// TODO: Do the actual implementation.


	return 0;
}

void *jemalloc(size_t size)
{
	return (malloc(size));
}
