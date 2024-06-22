#include "readYUV.h"

#include "../lib/datatype.h"
#include "../lib/config.h"

#include "queue_wrapper.h"

// #include <stdio.h>

void read_444_format(JPEG_ENCODER_STRUCTURE *jpeg_encoder_structure, UINT8 *input_ptr)
{
	INT32 i, j;

	UINT8 R, G, B;
	INT32 Y, Cb, Cr;

	UINT16 rows = jpeg_encoder_structure->rows;
	UINT16 cols = jpeg_encoder_structure->cols;
	UINT16 incr = jpeg_encoder_structure->incr;

	// int lpc1 = 0;
	// int lpc2 = 0;

	for (i = rows; i > 0; i--)
	{
		for (j = cols; j > 0; j--)
		{
			R = *input_ptr++;
			G = *input_ptr++;
			B = *input_ptr++;

			Y = ((77 * R + 150 * G + 29 * B) >> 8);
			Cb = ((-43 * R - 85 * G + 128 * B) >> 8) + 128;
			Cr = ((128 * R - 107 * G - 21 * B) >> 8) + 128;

			if (Y < 0)
				Y = 0;
			else if (Y > 255)
				Y = 255;

			if (Cb < 0)
				Cb = 0;
			else if (Cb > 255)
				Cb = 255;

			if (Cr < 0)
				Cr = 0;
			else if (Cr > 255)
				Cr = 255;

			SEND1(Y);
			SEND2(Cb);
			SEND3(Cr);
			// lpc1++;
		}

		if ((j = (8 - cols)) > 0)
		{
			R = *(input_ptr - 3);
			G = *(input_ptr - 2);
			B = *(input_ptr - 1);

			Y = ((77 * R + 150 * G + 29 * B) >> 8);
			Cb = ((-43 * R - 85 * G + 128 * B) >> 8) + 128;
			Cr = ((128 * R - 107 * G - 21 * B) >> 8) + 128;

			if (Y < 0)
				Y = 0;
			else if (Y > 255)
				Y = 255;

			if (Cb < 0)
				Cb = 0;
			else if (Cb > 255)
				Cb = 255;

			if (Cr < 0)
				Cr = 0;
			else if (Cr > 255)
				Cr = 255;

			for (; j > 0; j--)
			{

				SEND1(Y);
				SEND2(Cb);
				SEND3(Cr);
			}
		}

		input_ptr += incr;
	}

	// printf("first loop sent: %d\n",lpc1);

	input_ptr -= incr;

	for (i = 8 - rows; i > 0; i--)
	{
		for (j = cols * 3; j > 0;)
		{
			R = *(input_ptr - (j--));
			G = *(input_ptr - (j--));
			B = *(input_ptr - (j--));

			Y = ((77 * R + 150 * G + 29 * B) >> 8);
			Cb = ((-43 * R - 85 * G + 128 * B) >> 8) + 128;
			Cr = ((128 * R - 107 * G - 21 * B) >> 8) + 128;

			if (Y < 0)
				Y = 0;
			else if (Y > 255)
				Y = 255;

			if (Cb < 0)
				Cb = 0;
			else if (Cb > 255)
				Cb = 255;

			if (Cr < 0)
				Cr = 0;
			else if (Cr > 255)
				Cr = 255;

			SEND1(Y);
			SEND2(Cb);
			SEND3(Cr);
			// lpc2++;
		}
		if ((j = (8 - cols)) > 0)
		{
			R = *(input_ptr - 3);
			G = *(input_ptr - 2);
			B = *(input_ptr - 1);

			Y = ((77 * R + 150 * G + 29 * B) >> 8);
			Cb = ((-43 * R - 85 * G + 128 * B) >> 8) + 128;
			Cr = ((128 * R - 107 * G - 21 * B) >> 8) + 128;

			if (Y < 0)
				Y = 0;
			else if (Y > 255)
				Y = 255;

			if (Cb < 0)
				Cb = 0;
			else if (Cb > 255)
				Cb = 255;

			if (Cr < 0)
				Cr = 0;
			else if (Cr > 255)
				Cr = 255;

			for (; j > 0; j--)
			{
				SEND1(Y);
				SEND2(Cb);
				SEND3(Cr);
			}
		}
	}

	// printf("second loop sent: %d\n",lpc2);
}
