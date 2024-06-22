#include "queue_wrapper.h"
// #include <stdio.h>

#include "../lib/queue.h"
#include "../lib/q_mem_obj_def.h"


// Queue *qa_p1;
// Queue *qa_p2;
// Queue *qa_p3;
// Queue *q4;
// Queue *q5;
// Queue *qa_fn;

void init_queues()
{
    // qa_p1 = InitQueue("qa_p1", 'e');
    // qa_p2 = InitQueue("qa_p2", 'e');
    // qa_p3 = InitQueue("qa_p3", 'e');
    // qa_fn = InitQueue("qa_fn", 'e');
}

void close_queues()
{
    // CloseQueue(qa_p1);
    // CloseQueue(qa_p2);
    // CloseQueue(qa_p3);
    // CloseQueue(qa_fn);
}

void SEND1(int Y)
{

    enqueueINT32(qa_p1, Y);
}

void SEND2(int Cb)
{

    enqueueINT32(qa_p2, Cb);
}

void SEND3(int Cr)
{

    enqueueINT32(qa_p3, Cr);
}

// void SEND6(int c)
// {

//     enqueueINT32(qa_fn, c);
// }