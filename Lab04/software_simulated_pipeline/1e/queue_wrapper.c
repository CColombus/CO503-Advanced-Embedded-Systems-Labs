#include "queue_wrapper.h"
#include <stdio.h>

Queue *q5;
Queue *qd;
Queue *qe;

int DEBUG_COUNTER = 0;

void debug_queue(char *caller){
    printf("(%s)%d -> ", caller, DEBUG_COUNTER);
    DEBUG_COUNTER = 0;
}

void init_queues()
{
    q5 = InitQueue("q5", 'd');
    qd = InitQueue("qd", 'd');
    qe = InitQueue("qe", 'e');
}

void close_queues()
{
    CloseQueue(q5);
    CloseQueue(qd);
    CloseQueue(qe);
}

int RECV1()
{

    return dequeueINT32(q5);
}

int RECV2()
{
    DEBUG_COUNTER++;

    return dequeueINT32(qd);
}

void SEND1(int data)
{
    enqueueINT32(qe, data);
}
