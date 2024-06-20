#include "queue_wrapper.h"
#include <stdio.h>

Queue *q4;
Queue *qc;
Queue *qd;

void init_queues()
{
    q4 = InitQueue("q4", 'd');
    qc = InitQueue("qc", 'd');
    qd = InitQueue("qd", 'e');
}

void close_queues()
{
    CloseQueue(q4);
    CloseQueue(qc);
    CloseQueue(qd);
}

int RECV1()
{

    return dequeueINT32(q4);
}

int RECV2()
{

    return dequeueINT32(qc);
}

void SEND(int data)
{

    enqueueINT32(qd, data);
}