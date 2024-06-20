#include "queue_wrapper.h"
#include <stdio.h>

Queue *qb_p1;
Queue *qc_p1;

void init_queues()
{
    qb_p1 = InitQueue("qb_p1", 'd');
    qc_p1 = InitQueue("qc_p1", 'e');
}

void close_queues()
{

    CloseQueue(qb_p1);
    CloseQueue(qc_p1);
}

int RECV()
{

    return dequeueINT32(qb_p1);
}

void SEND(int data)
{

    enqueueINT32(qc_p1, data);
}