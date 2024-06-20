#include "queue_wrapper.h"
#include <stdio.h>

#include "queue.h"

Queue *q1;
Queue *q2;
Queue *q3;
Queue *q4;
Queue *q5;
Queue *q6;

void init_queues()
{
    q1 = InitQueue("q1", 'e');
    q2 = InitQueue("q2", 'e');
    q3 = InitQueue("q3", 'e');
    q4 = InitQueue("q4", 'e');
    q5 = InitQueue("q5", 'e');
    q6 = InitQueue("q6", 'e');
}

void close_queues()
{
    CloseQueue(q1);
    CloseQueue(q2);
    CloseQueue(q3);
    CloseQueue(q4);
    CloseQueue(q5);
    CloseQueue(q6);
}

void SEND1(int Y)
{

    enqueueINT32(q1, Y);
}

void SEND2(int Cb)
{

    enqueueINT32(q2, Cb);
}

void SEND3(int Cr)
{

    enqueueINT32(q3, Cr);
}

void SEND4(int data)
{

    enqueueINT32(q4, data);
}

void SEND5(int data)
{

    enqueueINT32(q5, data);
}

void SEND6(int c)
{

    enqueueINT32(q6, c);
}