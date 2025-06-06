// ? Original file name dct.c was changed to main.c to keep the naming consistent.

#include "queue_wrapper.h"
#include "mem_info.h"
#include <stdlib.h>

#include "datatype.h"

INT16 *data;

// TODO: Currently, this function is complete. But will have to change for hardware implementation.
/* DCT for One block(8x8) */
void DCT(void)
{
	UINT16 i;
	INT32 x0, x1, x2, x3, x4, x5, x6, x7, x8;

	/*	All values are shifted left by 10
		and rounded off to nearest integer */

	static const UINT16 c1 = 1420; /* cos PI/16 * root(2)	*/
	static const UINT16 c2 = 1338; /* cos PI/8 * root(2)	*/
	static const UINT16 c3 = 1204; /* cos 3PI/16 * root(2)	*/
	static const UINT16 c5 = 805;  /* cos 5PI/16 * root(2)	*/
	static const UINT16 c6 = 554;  /* cos 3PI/8 * root(2)	*/
	static const UINT16 c7 = 283;  /* cos 7PI/16 * root(2)	*/

	static const UINT16 s1 = 3;
	static const UINT16 s2 = 10;
	static const UINT16 s3 = 13;

	/* read back from queue */
	for (i = 0; i < 64; i++)
	{

		data[i] = (INT16)RECV();
	}

	for (i = 8; i > 0; i--)
	{
		x8 = data[0] + data[7];
		x0 = data[0] - data[7];

		x7 = data[1] + data[6];
		x1 = data[1] - data[6];

		x6 = data[2] + data[5];
		x2 = data[2] - data[5];

		x5 = data[3] + data[4];
		x3 = data[3] - data[4];

		x4 = x8 + x5;
		x8 -= x5;

		x5 = x7 + x6;
		x7 -= x6;

		data[0] = (INT16)(x4 + x5);
		data[4] = (INT16)(x4 - x5);

		data[2] = (INT16)((x8 * c2 + x7 * c6) >> s2);
		data[6] = (INT16)((x8 * c6 - x7 * c2) >> s2);

		data[7] = (INT16)((x0 * c7 - x1 * c5 + x2 * c3 - x3 * c1) >> s2);
		data[5] = (INT16)((x0 * c5 - x1 * c1 + x2 * c7 + x3 * c3) >> s2);
		data[3] = (INT16)((x0 * c3 - x1 * c7 - x2 * c1 - x3 * c5) >> s2);
		data[1] = (INT16)((x0 * c1 + x1 * c3 + x2 * c5 + x3 * c7) >> s2);

		data += 8;
	}

	data -= 64;

	for (i = 8; i > 0; i--)
	{
		x8 = data[0] + data[56];
		x0 = data[0] - data[56];

		x7 = data[8] + data[48];
		x1 = data[8] - data[48];

		x6 = data[16] + data[40];
		x2 = data[16] - data[40];

		x5 = data[24] + data[32];
		x3 = data[24] - data[32];

		x4 = x8 + x5;
		x8 -= x5;

		x5 = x7 + x6;
		x7 -= x6;

		data[0] = (INT16)((x4 + x5) >> s1);
		data[32] = (INT16)((x4 - x5) >> s1);

		data[16] = (INT16)((x8 * c2 + x7 * c6) >> s3);
		data[48] = (INT16)((x8 * c6 - x7 * c2) >> s3);

		data[56] = (INT16)((x0 * c7 - x1 * c5 + x2 * c3 - x3 * c1) >> s3);
		data[40] = (INT16)((x0 * c5 - x1 * c1 + x2 * c7 + x3 * c3) >> s3);
		data[24] = (INT16)((x0 * c3 - x1 * c7 - x2 * c1 - x3 * c5) >> s3);
		data[8] = (INT16)((x0 * c1 + x1 * c3 + x2 * c5 + x3 * c7) >> s3);

		data++;
	}

	data -= 8;

	/* write out to queue */
	for (i = 0; i < 64; i++)
	{
		SEND(data[i]);
	}
}


// TODO: Rate limited here manually. Will have to change for hardware implementation.
int main(void)
{
	data = (INT16 *)malloc(sizeof(INT16) * 64);

	// TODO: Do the actual implementation.
	init_queues();

	// TODO: added temporaryCounter to limit the loop otherwise file will be too big,
	// while (1)
	for (int iter = 0; iter < getIterCount(); iter++)
	{
		DCT();
	}

	// TODO: Do the actual implementation.
	close_queues();
}
