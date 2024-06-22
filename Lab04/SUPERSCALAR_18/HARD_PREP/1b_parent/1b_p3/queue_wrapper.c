#include "queue_wrapper.h"
// #include <stdio.h>
#include "../lib/queue.h"
#include "../lib/q_mem_obj_def.h"


// Queue *qa_p3;
// Queue *qb_p3;


void init_queues()
{
    // qa_p3 = InitQueue("qa_p3", 'd');
    // qb_p3 = InitQueue("qb_p3", 'e');
}

void close_queues()
{
    // CloseQueue(qa_p3);
    // CloseQueue(qb_p3);
}

int RECV3()
{

    return dequeueINT32(qa_p3);
}

void SEND(int data)
{

    enqueueINT32(qb_p3, data);
}