#include "queue_wrapper.h"
#include "../lib/queue.c"
#include <stdio.h>
#include <stdlib.h>

Queue *q6r; // Queue for receiving filename
Queue *qi1e;

void QUEUE_INIT()
{
    q6r = initializeQueue("../queues/q6.txt", "r");
    qi1e = initializeQueue("../queues/qout1e.txt", "r");

    if (q6r == NULL || qi1e == NULL)
    {
        fprintf(stderr, "Failed to initialize queues\n");
        exit(1);
    }

}

void QUEUE_CLOSE()
{
    closeQueue(q6r);
    closeQueue(qi1e);

    free(q6r);
    free(qi1e);
}

int RECV1()
{
    // dequeue from queue and convert to int
    // char *c = dequeue(q6r);
    // printf("  RECV1: %c rep as %d\n", c[0],(int)c[0]);
    // return (int)c[0];
    return dequeueINT32(q6r);
}

int RECV2()
{
    // dequeue from queue and convert to int
    // return atoi(dequeue(qi1e));
    return dequeueINT32(qi1e);
}