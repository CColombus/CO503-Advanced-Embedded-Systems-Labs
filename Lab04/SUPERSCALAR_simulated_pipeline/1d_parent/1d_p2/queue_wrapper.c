#include "queue_wrapper.h"
#include <stdio.h>

// Queue *q4;
Queue *qc_p2;
Queue *qd_p2;

void init_queues()
{
    // q4 = InitQueue("q4", 'd');
    qc_p2 = InitQueue("qc_p2", 'd');
    qd_p2 = InitQueue("qd_p2", 'e');
}

void close_queues()
{
    // CloseQueue(q4);
    CloseQueue(qc_p2);
    CloseQueue(qd_p2);
}

// int RECV1()
// {

//     return dequeueINT32(q4);
// }

int RECV2()
{

    return dequeueINT32(qc_p2);
}

void SEND(int data)
{

    enqueueINT32(qd_p2, data);
}