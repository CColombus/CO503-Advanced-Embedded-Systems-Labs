#include <stdio.h>
#include <string.h>

#include <stdlib.h>
#include <io.h>
#include <time.h>

#include "queue_wrapper.h"
#include "../lib/mem_info.h"

// base adress of mem_info memory
#define MF_BASE 0x10000

// offsets each int32
#define PROG_STATUS 0
#define ITER_COUNT 4
#define WIDTH 8
#define HEIGHT 12
#define QUALITY_FACTOR 16
#define IMAGE_FORMAT 20
#define FILE_NAME_LEN 24
#define FILE_NAME 28

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

	// Wait for start stage
	while (getProgStatus() != 1)
		;

	// Read filename from memory
	int length = (int)IORD_32DIRECT(MF_BASE, FILE_NAME_LEN);
	char filename_mem[length];
	for (int i = 0; i <= length; i++)
	{
		filename_mem[i] = (char)IORD_8DIRECT(MF_BASE, FILE_NAME + i);
	}

	strcat(filename_mem, ".jpg");
	printf("\nOutput Filename: %s\n", filename_mem);

	// append file_system to filename
	char input_file_full[150];
	strcpy(input_file_full, file_system);
	strcat(input_file_full, filename_mem);

	printf("\nOutput file: %s\n", input_file_full);

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
	printf("\n Done !\n");

	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("Time taken: %f sec.\n", cpu_time_used);

	// ! Software implementation
	close_queues();

	return 0;
}
