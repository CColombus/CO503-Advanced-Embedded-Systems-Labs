#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int INIT_USAGE_ENQ = 0;
int INIT_USAGE_DEQ = 0;

char *QUEUE_PATH = "../queues/";

#include "queue.h"

// Function prototypes
Queue *InitQueue(char *name, char mode);
void CloseQueue(Queue *q);
int enqueueINT32(Queue *q, int value);
int dequeueINT32(Queue *q);

// Initialize a queue
Queue *InitQueue(char *name, char mode)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));

    // check if QUEUE_PATH exists
    if (access(QUEUE_PATH, F_OK) == -1)
    {
        QUEUE_PATH = "../../queues/";

        if (access(QUEUE_PATH, F_OK) == -1)
        {
            printf("Queue path does not exist\n");
            exit(1);
        }
    }

    q->filename = (char *)malloc(strlen(QUEUE_PATH) + strlen(name) + 1);
    sprintf(q->filename, "%s%s%s", QUEUE_PATH, name, ".txt");

    if (mode == 'd' && (q->readfd = fopen(q->filename, "r")) == NULL)
        printf("Read Queue open failed\n");
    

    if (mode == 'e' && (q->writefd = fopen(q->filename, "w")) == NULL)
        printf("Write Queue open failed\n");

    return q;
}

// Close a queue
void CloseQueue(Queue *q)
{
    fclose(q->readfd);
    fclose(q->writefd);
    free(q->filename);
    free(q);
}

int dequeueINT32(Queue *q)
{
    char line[20];

    // Check if queue was not initialized
    if (q == NULL)
    {
        printf("\x1b[1;31mQueue not initialized\x1b[0m\n");
        return 0;
    }

    if (fgets(line, sizeof(line), q->readfd) == NULL)
    {
        printf("\x1b[1;31m%s\n\x1b[2;33;41m%s\x1b[0m\n", "\t\tQueue is empty!", "THE PROGRAM WILL HANG TO SIMULATE HARDWARE BEHAVIOUR!");
        while (1)
        {
            sleep(1000);
        }
        return 0;
    }

    if (INIT_USAGE_DEQ == 0){
        INIT_USAGE_DEQ = 1;
        printf("First time using dequeueINT32\n");
    }

    line[strlen(line) - 1] = '\0';
    int value = atoi(line);
    return value;
}

int enqueueINT32(Queue *q, int value)
{
    // Check if queue was not initialized
    if (q == NULL)
    {
        printf("\x1b[1;31mQueue not initialized\x1b[0m\n");
        return 0;
    }

    if (INIT_USAGE_ENQ == 0)
    {
        INIT_USAGE_ENQ = 1;
        printf("First time using enqueueINT32\n");
    }

    fprintf(q->writefd, "%d\n", value);
    fflush(q->writefd);
    return 0;
}
