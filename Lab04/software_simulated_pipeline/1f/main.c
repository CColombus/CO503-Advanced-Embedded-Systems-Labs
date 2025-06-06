#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "queue_wrapper.h"

typedef char INT8;
typedef unsigned char UINT8;

int main(void)
{
	FILE *fptr;
	UINT8 out;
	INT8 filename[50];

	// ! Software implementation
	init_queues();

	while (1)
	{
		out = 0;

		// TODO: RECV1 is probably for q6.txt reading filename
		filename[out] = (char)RECV1();

		while (filename[out] != '\0' && filename[out] != '\n')
		{
			out++;
			filename[out] = (char)RECV1();
		}

		printf("\nFilename: %s\n", filename);

		// TODO: This is a bug, the filename is not being read correctly
		// TODO: BUT we must have some way to check for queue errors !!!!
		// if (filename[out] == '\0')
		// 	exit(0);

		// while (filename[out] != '\0' || filename[out] != '1')
		// {
		// 	out++;
		// 	filename[out] = (char)RECV1();
		// 	printf("%c", filename[out]);
		// }

		// printf("\nFilename: %s\n", filename); // Filename added by haris
		// exit(0);

		filename[out++] = '.';
		filename[out++] = 'j';
		filename[out++] = 'p';
		filename[out++] = 'g';
		filename[out] = '\0';

		fprintf(stdout, "\nOutput file: %s\n", filename); // Output file added by haris

		fptr = fopen(filename, "wb");
		// asm("dummy");
		while (1)
		{
			// TODO: RECV2 is probably for getting raw jpeg data from previous stage in the pipeline
			out = (UINT8)RECV2();

			fputc(out, fptr);
			if (out == 0xFF)
			{
				out = (UINT8)RECV2();
				fputc(out, fptr);
				// printf("\nWriting: %d\n",out);
				if (out == 0xD9)
					break;
			}
			//  #pragma flush // added by haris
			//			if (!IS_FIFO2EMPTY()){
			//				out = (UINT8)RECV2();
			//				fputc(out, fptr);
			//			}else if(!IS_FIFO3EMPTY()){
			//				RECV3();
			//				break;
			//			}
		}
		// asm("dummy");
		fclose(fptr);
		printf("\n Done ! %ld\n", clock());
		break;
	}

	// ! Software implementation
	close_queues();

	return 0;
}
