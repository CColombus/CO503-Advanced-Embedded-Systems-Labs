#include "queue_wrapper.h"
// #include <stdio.h>
#include "../lib/queue.h"
#include "../lib/q_mem_obj_def.h"


// Queue *qd_p1;
// Queue *qd_p2;
// Queue *qd_p3;
// Queue *qe;

void init_queues()
{
    // qd_p1 = InitQueue("qd_p1", 'd');
    // qd_p2 = InitQueue("qd_p2", 'd');
    // qd_p3 = InitQueue("qd_p3", 'd');
    // qe = InitQueue("qe", 'e');
}

void close_queues()
{
    // CloseQueue(qd_p1);
    // CloseQueue(qd_p2);
    // CloseQueue(qd_p3);
    // CloseQueue(qe);
}

int RECV2(int component)
{
    int data;
    switch (component)
    {
    case 0:
        data = dequeueINT32(qd_p1); // Table data
        break;
    case 1:
        data = dequeueINT32(qd_p1); // Macroblock data
        break;
    case 2:
        data = dequeueINT32(qd_p2); // Macroblock data
        break;
    case 3:
        data = dequeueINT32(qd_p3); // Macroblock data
        break;
    default:
        data = -1;
        break;
    }
    return data;
}

void SEND1(int data)
{
    enqueueINT32(qe, data);
}
