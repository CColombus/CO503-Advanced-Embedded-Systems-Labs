#include "queue_wrapper.h"
#include <stdio.h>
#include <stdlib.h>

#include "lib/q_mem_obj_def.h"
#include "lib/queue.h"

int RECV1()
{
    // dequeue from queue and convert to int
    // return atoi(dequeue(q5r));
    return dequeueINT32(q5);
}

int RECV2()
{
    // dequeue from queue and convert to int
    // return atoi(dequeue(qi1d));
    return dequeueINT32(q1d);
}

void SEND1(int data)
{
    // enqueue data to queue
    // char str[10];
    // sprintf(str, "%d", data);
    // enqueueINT32(qo1e, str);
    enqueueINT32(q1e, data);
}

// void SEND2(int data)
// {
//     // enqueue data to queue
//     // char str[10];
//     // sprintf(str, "%d", data);
//     // enqueueINT32(qo2e, str);
//     enqueueINT32(qo2e, data);
// }