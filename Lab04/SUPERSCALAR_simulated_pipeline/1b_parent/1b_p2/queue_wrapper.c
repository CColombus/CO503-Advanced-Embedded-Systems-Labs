#include "queue_wrapper.h"
#include <stdio.h>

Queue *qa_p2;
Queue *qb_p2;


void init_queues()
{
    qa_p2 = InitQueue("qa_p2", 'd');
    qb_p2 = InitQueue("qb_p2", 'e');
}

void close_queues()
{
    CloseQueue(qa_p2);
    CloseQueue(qb_p2);
}

int RECV2()
{

    return dequeueINT32(qa_p2);
}

void SEND(int data)
{

    enqueueINT32(qb_p2, data);
}