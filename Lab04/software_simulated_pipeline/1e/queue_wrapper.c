#include "queue_wrapper.h"
#include "../lib/queue.c"
#include <stdio.h>
#include <stdlib.h>

Queue *q5r; // Queue for receiving w,h,count of macroblocks
Queue *qi1d;
Queue *qo1e;
// Queue *qo2e; // ! Queue for sending DONE flag

void QUEUE_INIT()
{
    q5r = initializeQueue("../queues/q5.txt", "r");
    qi1d = initializeQueue("../queues/qout1d.txt", "r");
    qo1e = initializeQueue("../queues/qout1e.txt", "w");
    // qo2e = initializeQueue("../queues/qout2e.txt", "w"); // ! Again this is special for DONE flag

    if (q5r == NULL || qi1d == NULL || qo1e == NULL)// || qo2e == NULL)
    {
        fprintf(stderr, "Failed to initialize queues\n");
        exit(1);
    }

}

void QUEUE_CLOSE()
{
    closeQueue(q5r);
    closeQueue(qi1d);
    closeQueue(qo1e);
    // closeQueue(qo2e);

    free(q5r);
    free(qi1d);
    free(qo1e);
    // free(qo2e);
}

int RECV1()
{
    // dequeue from queue and convert to int
    // return atoi(dequeue(q5r));
    return dequeueINT32(q5r);
}

int RECV2()
{
    // dequeue from queue and convert to int
    // return atoi(dequeue(qi1d));
    return dequeueINT32(qi1d);
}

void SEND1(int data)
{
    // enqueue data to queue
    // char str[10];
    // sprintf(str, "%d", data);
    // enqueue(qo1e, str);
    enqueue(qo1e, data);
}

// void SEND2(int data)
// {
//     // enqueue data to queue
//     // char str[10];
//     // sprintf(str, "%d", data);
//     // enqueue(qo2e, str);
//     enqueue(qo2e, data);
// }