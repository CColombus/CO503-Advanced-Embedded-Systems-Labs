#include "queue_wrapper.h"
#include "../lib/queue.h"

#include "../lib/q_mem_obj_def.h"

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

// TODO: This one sends a char, not an int need to cast
void SEND6(int c)
{

    enqueueINT32(q6, c);
}