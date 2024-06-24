#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <stdlib.h>

#include "queue_wrapper.h"

typedef char INT8;
typedef unsigned char UINT8;

int main()
{
	char file_system[80] = "/mnt/host/files/";
	FILE *fptr;
	UINT8 out;
	INT8 filename[50];
	clock_t start, end;
	double cpu_time_used;

	while (1)
	{
		out = 0;

		// Skip any prefix null values
		while ((filename[out] = RECV1()) == '\0')
		{
		}

		while (filename[out] != '\0' && filename[out] != '\n')
		{
			out++;
			filename[out] = (char)RECV1();
		}

		start = clock();

		printf("\nFilename: %s\n", filename);

		filename[out++] = '.';
		filename[out++] = 'j';
		filename[out++] = 'p';
		filename[out++] = 'g';
		filename[out] = '\0';

		char input_file_full[150];
		strcpy(input_file_full, file_system);
		strcat(input_file_full, filename);

		fprintf(stdout, "\nOutput file: %s\n", input_file_full);

		fptr = fopen(input_file_full, "wb");

		if (fptr == NULL)
		{
			printf("Save File Open Error!\n");
			break;
		}

		while (1)
		{

			out = (UINT8)RECV2();

			fputc(out, fptr);
			if (out == 0xFF)
			{
				out = (UINT8)RECV2();
				fputc(out, fptr);

				if (out == 0xD9)
				{
					end = clock();
					break;
				}
			}
		}

		fclose(fptr);

		cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
		printf("\nJPEG conversion complete!\n");
		printf("Time taken for conversion process: %f sec.\n", cpu_time_used);
		break;
	}

	return 0;
}
