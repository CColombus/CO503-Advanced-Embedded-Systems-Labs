#ifndef QUEUE_WRAPPER_H
#define QUEUE_WRAPPER_H


void init_queues();
void close_queues();


void SEND1(int data);
int RECV2(int component);

#endif /* QUEUE_WRAPPER_H */