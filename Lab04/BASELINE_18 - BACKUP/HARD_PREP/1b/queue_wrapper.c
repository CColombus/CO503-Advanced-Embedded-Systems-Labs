#include "queue_wrapper.h"
#include "../lib/queue.h"
#include <stdio.h>
#include <stdlib.h>

#include "../lib/q_mem_obj_def.h"

int RECV1()
{

    return dequeueINT32(q1);
}

int RECV2()
{

    return dequeueINT32(q2);
}

int RECV3()
{

    return dequeueINT32(q3);
}

void SEND(int data)
{
//	printf("%d\n",data);
    enqueueINT32(q1b, data);
}
