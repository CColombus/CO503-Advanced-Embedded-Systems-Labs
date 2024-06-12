#include "queue_wrapper.h"
#include "../lib/queue.c"
#include <stdio.h>

Queue *q1;
Queue *q2;
Queue *q3;
Queue *q4;
Queue *q5;
Queue *q6;

void QUEUE_INIT()
{
    q1 = initializeQueue("../queues/q1.txt","w");
    q2 = initializeQueue("../queues/q2.txt","w");
    q3 = initializeQueue("../queues/q3.txt","w");
    q4 = initializeQueue("../queues/q4.txt","w");
    q5 = initializeQueue("../queues/q5.txt","w");
    q6 = initializeQueue("../queues/q6.txt","w");

    if (q1 == NULL || q2 == NULL || q3 == NULL || q4 == NULL || q5 == NULL || q6 == NULL)
    {
        fprintf(stderr, "Failed to initialize queues\n");
        return;
    }
}

void QUEUE_CLOSE()
{
    closeQueue(q1);
    closeQueue(q2);
    closeQueue(q3);
    closeQueue(q4);
    closeQueue(q5);
    closeQueue(q6);

    free(q1);
    free(q2);
    free(q3);
    free(q4);
    free(q5);
    free(q6);
    
}

void SEND1(int Y)
{
    // printf("Y = %d\n", Y);
    // convert int to string
    // char Y_str[12];
    // sprintf(Y_str, "%d", Y);
    // enqueue(q1, Y_str);
    enqueueINT32(q1, Y);
}

void SEND2(int Cb)
{
    // printf("Cb = %d\n", Cb);
    // convert int to string
    // char Cb_str[12];
    // sprintf(Cb_str, "%d", Cb);
    // enqueue(q2, Cb_str);
    enqueueINT32(q2, Cb);
}

void SEND3(int Cr)
{
    // printf("Cr = %d\n", Cr);
    // convert int to string
    // char Cr_str[12];
    // sprintf(Cr_str, "%d", Cr);
    // enqueue(q3, Cr_str);
    enqueueINT32(q3, Cr);
}

void SEND4(int data)
{
    // printf("data = %d\n", data);
    // convert int to string
    // char NA_str[12];
    // sprintf(NA_str, "%d", data);
    // enqueue(q4, NA_str);
    enqueueINT32(q4, data);
}

void SEND5(int data)
{
    // printf("data = %d\n", data);
    // convert int to string
    // char NA_str[12];
    // sprintf(NA_str, "%d", data);
    // enqueue(q5, NA_str);
    enqueueINT32(q5, data);
}

// TODO: This one sends a char, not an int need to cast
void SEND6(int c)
{
    // printf("%c", c);
    // convert char to string
    // char c_str[2];
    // c_str[0] = c;
    // c_str[1] = '\0';
    // enqueue(q6, c_str);
    enqueue(q6, c);
}