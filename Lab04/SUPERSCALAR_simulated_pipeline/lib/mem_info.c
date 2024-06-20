#include <stdio.h>
#include <io.h>
#include <string.h>
#include <stdlib.h>

#include "mem_info.h"

void setMemInfo(int iterCount, int width, int height, int qualityFactor, int imageFormat)
{
    char QUEUE_PATH[100] = "../queues/";
    // check if QUEUE_PATH exists
    if (access(QUEUE_PATH, F_OK) == -1)
    {
        // change to the correct path
        strcpy(QUEUE_PATH, "../../queues/");

        if (access(QUEUE_PATH, F_OK) == -1)
        {
            printf("Queue path does not exist\n");
            exit(1);
        }
    }

    strcat(QUEUE_PATH, "memInfo.txt");
    FILE *file = fopen(QUEUE_PATH, "w");

    if (file != NULL)
    {
        fprintf(file, "%d\n%d\n%d\n%d\n%d\n", iterCount, width, height, qualityFactor, imageFormat);
        fclose(file);
        printf("memInfo.txt written successfully.\n");
    }
    else
    {
        printf("Failed to open memInfo.txt for writing.\n");
    }
}

int globalIterCount = 0;
int globalWidth = 0;
int globalHeight = 0;
int globalQualityFactor = 0;
int globalImageFormat = 0;

void getMemInfo()
{
    // if all of the values are non-zero, then the file was already read
    if (globalIterCount != 0 && globalWidth != 0 && globalHeight != 0 && globalQualityFactor != 0 && globalImageFormat != 0)
    {
        return;
    }

    char QUEUE_PATH[100] = "../queues/";
    // check if QUEUE_PATH exists
    if (access(QUEUE_PATH, F_OK) == -1)
    {
        // change to the correct path
        strcpy(QUEUE_PATH, "../../queues/");

        if (access(QUEUE_PATH, F_OK) == -1)
        {
            printf("Queue path does not exist\n");
            exit(1);
        }
    }

    strcat(QUEUE_PATH, "memInfo.txt");
    FILE *file = fopen(QUEUE_PATH, "r");
    
    if (file != NULL)
    {
        fscanf(file, "%d\n%d\n%d\n%d\n%d\n", &globalIterCount, &globalWidth, &globalHeight, &globalQualityFactor, &globalImageFormat);
        // if any of the values are 0, then the file was not read properly
        if (globalIterCount == 0 || globalWidth == 0 || globalHeight == 0 || globalQualityFactor == 0 || globalImageFormat == 0)
        {
            printf("Failed to read memInfo.txt properly. Check memInfo for possible corruption!\n");
        }
        fclose(file);
    }
    else
    {
        printf("Failed to open memInfo.txt for reading.\n");
    }
}

int getIterCount()
{
    getMemInfo();
    return globalIterCount;
}

int getWidth()
{
    getMemInfo();
    return globalWidth;
}

int getHeight()
{
    getMemInfo();
    return globalHeight;
}

int getQualityFactor()
{
    getMemInfo();
    return globalQualityFactor;
}

int getImageFormat()
{
    getMemInfo();
    return globalImageFormat;
}