#include "queue_wrapper.h"
#include <stdio.h>

Queue *qa_p1;
Queue *qb_p1;


void init_queues()
{
    qa_p1 = InitQueue("qa_p1", 'd');
    qb_p1 = InitQueue("qb_p1", 'e');
}

void close_queues()
{
    CloseQueue(qa_p1);
    CloseQueue(qb_p1);
}

int RECV1()
{

    return dequeueINT32(qa_p1);
}

void SEND(int data)
{

    enqueueINT32(qb_p1, data);
}