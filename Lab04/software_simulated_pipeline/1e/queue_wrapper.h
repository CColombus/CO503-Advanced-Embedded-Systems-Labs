#ifndef QUEUE_WRAPPER_H
#define QUEUE_WRAPPER_H

void QUEUE_INIT();
void QUEUE_CLOSE();


void SEND1(int data);
// void SEND2(int data);

int RECV1();
int RECV2();

#endif /* QUEUE_WRAPPER_H */