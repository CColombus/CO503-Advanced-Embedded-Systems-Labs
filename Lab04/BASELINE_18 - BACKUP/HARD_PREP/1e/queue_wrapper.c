#include "queue_wrapper.h"
#include <stdio.h>
#include <stdlib.h>

#include "../lib/q_mem_obj_def.h"
#include "../lib/queue.h"

int RECV1()
{
	// dequeue from queue and convert to int
	// return atoi(dequeue(q5r));
	int temp = dequeueINT32(q5);
//	printf("Got %d from q5.\n",temp);
	return temp;
}

int RECV2()
{
    // dequeue from queue and convert to int
    // return atoi(dequeue(qi1d));
	int temp = dequeueINT32(q1d);
//	printf("Got %d from q1d.\n",temp);
	return temp;
}

void SEND1(int data)
{
    // enqueue data to queue
    // char str[10];
    // sprintf(str, "%d", data);
    // enqueueINT32(qo1e, str);
//	printf("Sent %d\n",data);
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
