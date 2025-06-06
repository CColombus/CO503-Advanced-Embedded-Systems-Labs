#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "queue_wrapper.h"

typedef char INT8;
typedef unsigned char UINT8;

int main(void)
{
	char file_system[80] = "/mnt/host/files/";
	FILE *fptr;
	UINT8 out;
	INT8 filename[50];

	while (1)
	{
		out = 0;

		filename[out] = (char)RECV1();

		while (filename[out] != '\0' && filename[out] != '\n')
		{
			out++;
			filename[out] = (char)RECV1();
		}

		printf("\nFilename: %s\n", filename);

		filename[out++] = '.';
		filename[out++] = 'j';
		filename[out++] = 'p';
		filename[out++] = 'g';
		filename[out] = '\0';

		fprintf(stdout, "\nOutput file: %s\n", filename);

		char input_file_full[150];
		strcpy(input_file_full, file_system);
		strcat(input_file_full, filename);

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
					break;
			}
		}

		fclose(fptr);
		printf("\n Done !\n");
		break;
	}

	return 0;
}
