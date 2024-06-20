#ifndef QUEUE_WRAPPER_H
#define QUEUE_WRAPPER_H

#include "../lib/queue.h"

void init_queues();
void close_queues();

void debug_queue(char *caller);


void SEND1(int data);
// void SEND2(int data);

int RECV1();
int RECV2();

#endif /* QUEUE_WRAPPER_H */