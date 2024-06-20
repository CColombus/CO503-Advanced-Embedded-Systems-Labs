#ifndef QUEUE_WRAPPER_H
#define QUEUE_WRAPPER_H

#include "../lib/queue.h"

// Prototypes
void init_queues();
void close_queues();
int RECV();
void SEND(int data);

#endif /* QUEUE_WRAPPER_H */