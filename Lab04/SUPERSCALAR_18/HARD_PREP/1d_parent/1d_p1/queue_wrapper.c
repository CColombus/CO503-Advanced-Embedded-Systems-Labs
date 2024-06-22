#include "queue_wrapper.h"
// #include <stdio.h>
#include "../lib/queue.h"
#include "../lib/q_mem_obj_def.h"


// Queue *q4;
// Queue *qc_p1;
// Queue *qd_p1;

void init_queues()
{
    // q4 = InitQueue("q4", 'd');
    // qc_p1 = InitQueue("qc_p1", 'd');
    // qd_p1 = InitQueue("qd_p1", 'e');
}

void close_queues()
{
    // CloseQueue(q4);
    // CloseQueue(qc_p1);
    // CloseQueue(qd_p1);
}

// int RECV1()
// {

//     return dequeueINT32(q4);
// }

int RECV2()
{

    return dequeueINT32(qc_p1);
}

void SEND(int data)
{

    enqueueINT32(qd_p1, data);
}