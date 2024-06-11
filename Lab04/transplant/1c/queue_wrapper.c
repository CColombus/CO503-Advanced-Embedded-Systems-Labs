#include "queue_wrapper.h"
#include "queue.c"
#include <stdio.h>
#include <stdlib.h>

Queue *qi1b;
Queue *qo1c;

void QUEUE_INIT()
{
    qi1b = initializeQueue("../queues/qout1b.txt", "r");
    qo1c = initializeQueue("../queues/qout1c.txt", "w");

    if (qi1b == NULL || qo1c == NULL)
    {
        fprintf(stderr, "Failed to initialize queues at wrapper!\n");
        return;
    }

}

void QUEUE_CLOSE()
{
    closeQueue(qi1b);
    closeQueue(qo1c);

    free(qi1b);
    free(qo1c);
}

int RECV()
{
    // dequeue from queue and convert to int
    return atoi(dequeue(qi1b));
}

void SEND(int data)
{
    // enqueue data to queue
    char str[10];
    sprintf(str, "%d", data);
    enqueue(qo1c, str);
}