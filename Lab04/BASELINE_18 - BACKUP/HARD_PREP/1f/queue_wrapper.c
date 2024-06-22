#include "queue_wrapper.h"
#include <stdio.h>
#include <stdlib.h>

#include "../lib/queue.h"
#include "../lib/q_mem_obj_def.h"


int RECV1()
{
    // dequeue from queue and convert to int
    // char *c = dequeue(q6r);
    // printf("  RECV1: %c rep as %d\n", c[0],(int)c[0]);
    // return (int)c[0];
    return dequeueINT32(q6);
}

int RECV2()
{
    // dequeue from queue and convert to int
    // return atoi(dequeue(qi1e));
    return dequeueINT32(q1e);
}