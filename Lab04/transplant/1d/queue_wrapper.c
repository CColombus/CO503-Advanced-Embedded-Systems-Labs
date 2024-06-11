#include "queue_wrapper.h"
#include "queue.c"
#include <stdio.h>
#include <stdlib.h>

Queue *q4r; // Queue for receiving count and quality factor
Queue *qi1c;
Queue *qo1d;

void QUEUE_INIT()
{
    q4r = initializeQueue("../queues/q4.txt", "r");
    qi1c = initializeQueue("../queues/qout1c.txt", "r");
    qo1d = initializeQueue("../queues/qout1d.txt", "w");

    if (q4r == NULL || qi1c == NULL || qo1d == NULL)
    {
        fprintf(stderr, "Failed to initialize queues at wrapper!\n");
        return;
    }

}

void QUEUE_CLOSE()
{
    closeQueue(q4r);
    closeQueue(qi1c);
    closeQueue(qo1d);

    free(q4r);
    free(qi1c);
    free(qo1d);
}

int RECV1()
{
    // dequeue from queue and convert to int
    return atoi(dequeue(q4r));
}

int RECV2()
{
    // dequeue from queue and convert to int
    return atoi(dequeue(qi1c));
}

void SEND(int data)
{
    // enqueue data to queue
    char str[10];
    sprintf(str, "%d", data);
    enqueue(qo1d, str);
}