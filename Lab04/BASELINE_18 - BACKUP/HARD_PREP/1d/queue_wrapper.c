#include "queue_wrapper.h"
#include "../lib/queue.h"
#include <stdio.h>
#include <stdlib.h>

#include "../lib/q_mem_obj_def.h"

int RECV1()
{
    // dequeue from queue and convert to int
    // return atoi(dequeue(q4r));
	int temp = dequeueINT32(q4);
	printf("Got %d from q4.\n",temp);
	return temp;
//    return dequeueINT32(q4);
}

int RECV2()
{
    // dequeue from queue and convert to int
    // return atoi(dequeue(qi1c));
    return dequeueINT32(q1c);
}

void SEND(int data)
{
    // enqueue data to queue
    // char str[10];
    // sprintf(str, "%d", data);
    // enqueueINT32(qo1d, str);
//	printf("%d\n",data);
    enqueueINT32(q1d, data);
}