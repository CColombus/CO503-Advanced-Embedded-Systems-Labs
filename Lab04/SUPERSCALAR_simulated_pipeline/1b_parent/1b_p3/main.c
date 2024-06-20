#include "queue_wrapper.h"
#include "mem_info.h"

// COMMON LIBRARY
#include "datatype.h"

// TODO: Currently, this function is complete. But will have to change for hardware implementation.
// TODO: Remove hard limit -> back pressure
/* Level shifting to get 8 bit SIGNED values for the data  */
void levelshift(void)
{

	// ! Software implementation
	init_queues();

	INT16 i, j;
	// while (1)
	// TODO: Runs forever. Change the condition to stop the loop.

	// TODO: added temporaryCounter to limit the loop otherwise file will be too big,
	// should probably consider queue back pressure
	for (int iter = 0; iter < getIterCount(); iter++)
	{

		for (j = 0; j < 64; j++)
		{
			i = (INT16)RECV3();
			i -= 128;
			SEND(i);
		}
	}

	// ! Software implementation
	close_queues();
}

int main(void)
{
	levelshift();

	return 0;
}
