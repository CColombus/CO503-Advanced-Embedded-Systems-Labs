#include "queue_wrapper.h"
#include <stdio.h>

Queue *qb_p3;
Queue *qc_p3;

void init_queues()
{
    qb_p3 = InitQueue("qb_p3", 'd');
    qc_p3 = InitQueue("qc_p3", 'e');
}

void close_queues()
{

    CloseQueue(qb_p3);
    CloseQueue(qc_p3);
}

int RECV()
{

    return dequeueINT32(qb_p3);
}

void SEND(int data)
{

    enqueueINT32(qc_p3, data);
}