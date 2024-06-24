#include <stdio.h>
#include <string.h>

#include <stdlib.h>
#include <io.h>
#include <time.h>

#include "queue_wrapper.h"
#include "../lib/mem_info.h"

typedef char INT8;
typedef unsigned char UINT8;

int main()
{
	char file_system[80] = "/mnt/host/files/";
	FILE *fptr;
	UINT8 out;
	// char filename[150];

	// ! Software implementation
	init_queues();

	printf("Final Stage of Superscalar JPEG Encoder\n");

	// Wait for start stage
	while (getProgStatus() != 1)
		;

	printf("Start singnal received from First Stage\n");

	// Read filename from memory
	int length = (int)IORD_32DIRECT(MF_BASE, FILE_NAME_LEN);
	char filename_mem[length+1];
	for (int i = 0; i < length; i++)
	{
		filename_mem[i] = (char)IORD_8DIRECT(MF_BASE, FILE_NAME + i);
	}
	filename_mem[length] = '\0';

	strcat(filename_mem, ".jpg");
	printf("\nOutput Filename: %s\n", filename_mem);

	// append file_system to filename
	char input_file_full[150];
	strcpy(input_file_full, file_system);
	strcat(input_file_full, filename_mem);

	printf("Output file path: %s\n", input_file_full);

	fptr = fopen(input_file_full, "wb");

	if (fptr == NULL)
	{
		printf("Save File Open Error!\n");
		return 0;
		// break;
	}

	clock_t start, end;
	double cpu_time_used;

	start = clock();
	while (1)
	{

		out = (UINT8)RECV2();

		fputc(out, fptr);
		if (out == 0xFF)
		{
			out = (UINT8)RECV2();
			fputc(out, fptr);

			if (out == 0xD9)
				break;
		}
	}
	end = clock();

	fclose(fptr);
	printf("\nJPEG conversion complete!\n");

	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("Quality Factor: %d\n", getQualityFactor());
	printf("Image Format: %d\n", getImageFormat());
	printf("Image Width: %d\n", getWidth());
	printf("Image Height: %d\n", getHeight());
	printf("Time taken for conversion process: %f sec.\n", cpu_time_used);

	// ! Software implementation
	close_queues();

	return 0;
}
