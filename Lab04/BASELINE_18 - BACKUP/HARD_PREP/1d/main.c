// ? Original filename quant.c was changed to main.c to keep the naming consistent.

#include <stdio.h>
#include "queue_wrapper.h"

// COMMON
#include "../lib/datatype.h"
#include "../lib/config.h"
#include "../lib/quantdata.h"


UINT8 Lqt[BLOCK_SIZE];
UINT8 Cqt[BLOCK_SIZE];
UINT16 ILqt[BLOCK_SIZE];
UINT16 ICqt[BLOCK_SIZE];
INT16 Temp[BLOCK_SIZE];

// TODO: This look okay as is
/*	This function implements 16 Step division for Q.15 format data */
UINT16 DSP_Division(UINT32 numer, UINT32 denom)
{
	UINT16 i;

	denom <<= 15;

	for (i = 16; i > 0; i--)
	{
		if (numer > denom)
		{
			numer -= denom;
			numer <<= 1;
			numer++;
		}
		else
			numer <<= 1;
	}

	return (UINT16)numer;
}

// TODO: Gonna need some changes here.
/* Multiply Quantization table with quality factor to get LQT and CQT */
void initialize_quantization_tables(void)
{
	UINT16 i, index;
	UINT32 value;

	UINT8 luminance_quant_table[] =
		{
			16, 11, 10, 16, 24, 40, 51, 61,
			12, 12, 14, 19, 26, 58, 60, 55,
			14, 13, 16, 24, 40, 57, 69, 56,
			14, 17, 22, 29, 51, 87, 80, 62,
			18, 22, 37, 56, 68, 109, 103, 77,
			24, 35, 55, 64, 81, 104, 113, 92,
			49, 64, 78, 87, 103, 121, 120, 101,
			72, 92, 95, 98, 112, 100, 103, 99};

	UINT8 chrominance_quant_table[] =
		{
			17, 18, 24, 47, 99, 99, 99, 99,
			18, 21, 26, 66, 99, 99, 99, 99,
			24, 26, 56, 99, 99, 99, 99, 99,
			47, 66, 99, 99, 99, 99, 99, 99,
			99, 99, 99, 99, 99, 99, 99, 99,
			99, 99, 99, 99, 99, 99, 99, 99,
			99, 99, 99, 99, 99, 99, 99, 99,
			99, 99, 99, 99, 99, 99, 99, 99};

	// TODO: This line checks out! here we are referring to q4.txt
	// TODO: Before this RECV call main func also does call RECV1 for getting count
	UINT32 quality_factor = (UINT32)RECV1();

	for (i = 0; i < 64; i++)
	{
		index = zigzag_table[i];

		/* luminance quantization table * quality factor */
		value = luminance_quant_table[i] * quality_factor;
		value = (value + 0x200) >> 10;

		if (value == 0)
			value = 1;
		else if (value > 255)
			value = 255;

		Lqt[index] = (UINT8)value;
		ILqt[i] = DSP_Division(0x8000, value);

		/* chrominance quantization table * quality factor */
		value = chrominance_quant_table[i] * quality_factor;
		value = (value + 0x200) >> 10;

		if (value == 0)
			value = 1;
		else if (value > 255)
			value = 255;

		Cqt[index] = (UINT8)value;
		ICqt[i] = DSP_Division(0x8000, value);
	}
	for (i = 0; i < 64; i++)
	{
		SEND(Lqt[i]);
	}
	for (i = 0; i < 64; i++)
	{
		SEND(Cqt[i]);
	}
}

// TODO: Gonna need some changes here.
/* multiply DCT Coefficients with Quantization table and store in ZigZag location */
void quantization(UINT16 *const quant_table_ptr)
{
	INT16 i;
	INT32 value;

	for (i = 0; i <= 63; i++)
	{
		// TODO: This RECV2 call should be from the previous stage in pipeline
		value = (INT16)RECV2() * quant_table_ptr[i];

		value = (value + 0x4000) >> 15;

		Temp[zigzag_table[i]] = (INT16)value;
	}
	for (i = 0; i <= 63; i++)
	{
		SEND(Temp[i]);
	}
}

int main(void)
{
	// TODO: Do the actual implementation here
	

	while (1)
	{
		// TODO: Here we are receiving count from q4.txt
		UINT32 count = (UINT32)RECV1();
		initialize_quantization_tables();

		for (; count > 0; count--)
		{
			quantization(ILqt);
			quantization(ICqt);
			quantization(ICqt);
		}
		break;
	}

	// TODO: Close the queues


	printf("\n Done ! \n");
}
