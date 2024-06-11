#include "queue_wrapper.h"
#include "queue.c"
#include <stdio.h>
#include <stdlib.h>

Queue *q1r;
Queue *q2r;
Queue *q3r;
Queue *qo1b;

void QUEUE_INIT()
{
    q1r = initializeQueue("../queues/q1.txt","r");
    q2r = initializeQueue("../queues/q2.txt","r");
    q3r = initializeQueue("../queues/q3.txt","r");
    qo1b = initializeQueue("../queues/qout1b.txt","w");

    if (q1r == NULL || q2r == NULL || q3r == NULL || qo1b == NULL)
    {
        fprintf(stderr, "Failed to initialize queues at wrapper!\n");
        return;
    }
}

void QUEUE_CLOSE()
{
    closeQueue(q1r);
    closeQueue(q2r);
    closeQueue(q3r);
    closeQueue(qo1b);

    free(q1r);
    free(q2r);
    free(q3r);
    free(qo1b);
}

int RECV1()
{
    // dequeue from queue and convert to int
    return atoi(dequeue(q1r));
}

int RECV2()
{
    // dequeue from queue and convert to int
    return atoi(dequeue(q2r));
}

int RECV3()
{
    // dequeue from queue and convert to int
    return atoi(dequeue(q3r));
}

void SEND(int data)
{
    // enqueue data to queue
    char str[10];
    sprintf(str, "%d", data);
    enqueue(qo1b, str);
}