#include "queue_wrapper.h"
#include "../lib/queue.h"
//#include <stdio.h>
//#include <stdlib.h>

#include "../lib/q_mem_obj_def.h"

int RECV()
{
    // dequeue from queue and convert to int
    // return atoi(dequeue(qi1b));
    return dequeueINT32(q1b);
}

void SEND(int data)
{
    // enqueue data to queue
    // char str[10];
    // sprintf(str, "%d", data);
    // enqueueINT32(qo1c, str);
//	printf("%d\n",data);
    enqueueINT32(q1c, data);
}
