#ifndef QUEUE_WRAPPER_H
#define QUEUE_WRAPPER_H

void QUEUE_INIT();
void QUEUE_CLOSE();


void SEND(int data);
int RECV();

#endif /* QUEUE_WRAPPER_H */