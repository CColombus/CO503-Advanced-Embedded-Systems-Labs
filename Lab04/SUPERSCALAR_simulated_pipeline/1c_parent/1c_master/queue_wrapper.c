#include "queue_wrapper.h"
#include <stdio.h>

Queue *qb;
Queue *qc;

void init_queues()
{
    qb = InitQueue("qb", 'd');
    qc = InitQueue("qc", 'e');
}

void close_queues()
{

    CloseQueue(qb);
    CloseQueue(qc);
}

int RECV()
{

    return dequeueINT32(qb);
}

void SEND(int data)
{

    enqueueINT32(qc, data);
}