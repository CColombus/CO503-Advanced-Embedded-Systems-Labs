#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int INIT_USAGE_ENQ = 0;
int INIT_USAGE_DEQ = 0;

typedef struct
{
    FILE *file;
    char *filename;
} Queue;

// Function to initialize the queue
Queue *initializeQueue(const char *filename, const char *flag)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (queue == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for queue\n");
        return NULL;
    }

    queue->filename = strdup(filename);
    if (queue->filename == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for filename\n");
        free(queue);
        return NULL;
    }


    queue->file = fopen(filename, flag);
    // queue->file = fopen(filename, );
    if (queue->file == NULL)
    {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        free(queue->filename);
        free(queue);
        return NULL;
    }

    return queue;
}

// Function to enqueue data to the queue
int enqueue(Queue *queue, int data)
{
    if (queue == NULL || queue->file == NULL)
    {
        fprintf(stderr, "Queue not initialized. ENq failed!\n");
        return -1;
    }

    fprintf(queue->file, "%d\n", data);
    fflush(queue->file); // Ensure the data is written to the file
    return 0;
}

int enqueueINT32(Queue *queue, int data)
{

    // TODO: Check for queue full

    if (INIT_USAGE_ENQ == 0){
        INIT_USAGE_ENQ = 1;
        printf("First time using enqueueINT32\n");
    }
    return enqueue(queue, (int)data);
}

// Function to dequeue data from the queue
char *dequeue(Queue *queue)
{
    if (queue == NULL || queue->file == NULL)
    {
        fprintf(stderr, "Queue not initialized. DEq failed!\n");
        return NULL;
    }

    // Read a line from the file
    char *line = (char *)malloc(MAX_LINE_LENGTH);

    if (line == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for line\n");
        return NULL;
    }

    if (fgets(line, MAX_LINE_LENGTH, queue->file) == NULL)
    {
        free(line);
        return NULL;
    }

    // char buffer[MAX_LINE_LENGTH];
    // while (fgets(buffer, MAX_LINE_LENGTH, tempFile) != NULL)
    // {
    //     fputs(buffer, newFile);
    // }

    return line;
}

int dequeueINT32(Queue *queue)
{
    // get return of char *dequeue(queue);
    // char ret_data = dequeue(queue);

    // TODO: Check for queue empty

    if (INIT_USAGE_DEQ == 0){
        INIT_USAGE_DEQ = 1;
        printf("First time using dequeueINT32\n");
    }

    return atoi(dequeue(queue));
}


// Function to close the queue
void closeQueue(Queue *queue)
{
    if (queue != NULL)
    {
        if (queue->file != NULL)
        {
            fclose(queue->file);
        }
        if (queue->filename != NULL)
        {
            free(queue->filename);
        }
        free(queue);
    }
}