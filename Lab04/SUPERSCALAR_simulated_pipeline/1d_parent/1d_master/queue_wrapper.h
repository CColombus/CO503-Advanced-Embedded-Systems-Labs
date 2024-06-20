#ifndef QUEUE_WRAPPER_H
#define QUEUE_WRAPPER_H

#include "queue.h"

// prototypes
void init_queues();
void close_queues();
int RECV1();
int RECV2();
void SEND(int data);

#endif /* QUEUE_WRAPPER_H */