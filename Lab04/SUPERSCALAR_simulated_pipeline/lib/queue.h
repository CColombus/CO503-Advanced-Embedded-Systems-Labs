#ifndef QUEUE_H
#define QUEUE_H

#include "queue_struct.h"

Queue *InitQueue(char *name, char mode);
void CloseQueue(Queue *q);
int enqueueINT32(Queue *q, int value);
int dequeueINT32(Queue *q);

#endif // QUEUE_H