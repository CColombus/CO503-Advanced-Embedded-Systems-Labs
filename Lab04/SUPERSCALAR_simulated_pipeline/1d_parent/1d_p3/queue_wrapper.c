#include "queue_wrapper.h"
#include <stdio.h>

// Queue *q4;
Queue *qc_p3;
Queue *qd_p3;

void init_queues()
{
    // q4 = InitQueue("q4", 'd');
    qc_p3 = InitQueue("qc_p3", 'd');
    qd_p3 = InitQueue("qd_p3", 'e');
}

void close_queues()
{
    // CloseQueue(q4);
    CloseQueue(qc_p3);
    CloseQueue(qd_p3);
}

// int RECV1()
// {

//     return dequeueINT32(q4);
// }

int RECV2()
{

    return dequeueINT32(qc_p3);
}

void SEND(int data)
{

    enqueueINT32(qd_p3, data);
}