#ifndef QUEUE_WRAPPER_H
#define QUEUE_WRAPPER_H

void QUEUE_INIT();
void QUEUE_CLOSE();

// 3 RECV functions
int RECV1();
int RECV2();
int RECV3();
// 1 SEND function
void SEND(int data);

#endif /* QUEUE_WRAPPER_H */