#include "queue_wrapper.h"
#include <stdio.h>

Queue *q1;
Queue *q2;
Queue *q3;
Queue *qb;


void init_queues()
{
    q1 = InitQueue("q1", 'd');
    q2 = InitQueue("q2", 'd');
    q3 = InitQueue("q3", 'd');
    qb = InitQueue("qb", 'e');
}

void close_queues()
{
    CloseQueue(q1);
    CloseQueue(q2);
    CloseQueue(q3);
    CloseQueue(qb);
}

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

    enqueueINT32(qb, data);
}