#include "queue_wrapper.h"
#include "../lib/queue.h"
//#include <stdio.h>
//#include <stdlib.h>

#include "../lib/q_mem_obj_def.h"

int RECV1()
{
	int temp = dequeueINT32(q1);
//	printf("%d\n",temp);
    return temp;
}

int RECV2()
{
	int temp = dequeueINT32(q2);
//	printf("%d\n",temp);
    return temp;
}

int RECV3()
{
	int temp = dequeueINT32(q3);
//	printf("%d\n",temp);
    return temp;
}

void SEND(int data)
{
//	printf("%d\n",data);
    enqueueINT32(q1b, data);
}
