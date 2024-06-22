#include "queue_wrapper.h"
// #include <stdio.h>
#include "../lib/queue.h"
#include "../lib/q_mem_obj_def.h"


// Queue *qb_p2;
// Queue *qc_p2;

void init_queues()
{
    // qb_p2 = InitQueue("qb_p2", 'd');
    // qc_p2 = InitQueue("qc_p2", 'e');
}

void close_queues()
{

    // CloseQueue(qb_p2);
    // CloseQueue(qc_p2);
}

int RECV()
{

    return dequeueINT32(qb_p2);
}

void SEND(int data)
{

    enqueueINT32(qc_p2, data);
}