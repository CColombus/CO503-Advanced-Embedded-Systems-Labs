#include "queue_wrapper.h"
#include <stdio.h>

Queue *q6;
Queue *qe;

void init_queues()
{
    q6 = InitQueue("q6", 'd');
    qe = InitQueue("qe", 'd');
}

void close_queues()
{
    CloseQueue(q6);
    CloseQueue(qe);
}

int RECV1()
{

    return dequeueINT32(q6);
}

int RECV2()
{

    return dequeueINT32(qe);
}