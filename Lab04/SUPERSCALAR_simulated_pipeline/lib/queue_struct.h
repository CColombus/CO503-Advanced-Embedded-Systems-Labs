#ifndef QUEUE_STRUCT_H
#define QUEUE_STRUCT_H

#include <stdio.h>

typedef struct Queue
{
    char *filename;
    FILE *readfd;
    FILE *writefd;
} Queue;

#endif // QUEUE_STRUCT_H