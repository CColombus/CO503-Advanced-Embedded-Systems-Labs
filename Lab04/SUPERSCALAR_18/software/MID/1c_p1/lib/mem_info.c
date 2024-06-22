#include "mem_info.h"

// TODO: Correctly include this lib
#include <io.h>
// #include <stdio.h>

// base adress of mem_info memory
#define MF_BASE 0x10000

// offsets each int32
#define PROG_STATUS 0
#define ITER_COUNT 4
#define WIDTH 8
#define HEIGHT 12
#define QUALITY_FACTOR 16
#define IMAGE_FORMAT 20
#define FILE_NAME_LEN 24
#define FILE_NAME 28

void setProgStatus(int status){
    // write to memory
    IOWR_32DIRECT(MF_BASE, PROG_STATUS, status);
}

int getProgStatus(){
    return (int)IORD_32DIRECT(MF_BASE, PROG_STATUS);
}

void setFileName(int length, char *fileName){
    // first write length of filename
    IOWR_32DIRECT(MF_BASE, FILE_NAME_LEN, length);
    // write filname to memory as int32 array upto length
    for (int i = 0; i <= length; i++){
        IOWR_8DIRECT(MF_BASE, FILE_NAME + i, fileName[i]);
    }
}

void setMemInfo(int iterCount, int width, int height, int qualityFactor, int imageFormat){
    // write to memory
    IOWR_32DIRECT(MF_BASE, ITER_COUNT, iterCount);
    IOWR_32DIRECT(MF_BASE, WIDTH, width);
    IOWR_32DIRECT(MF_BASE, HEIGHT, height);
    IOWR_32DIRECT(MF_BASE, QUALITY_FACTOR, qualityFactor);
    IOWR_32DIRECT(MF_BASE, IMAGE_FORMAT, imageFormat);
}

int getFileName(char *fileptr){
    while (getProgStatus() != 1);
    return 0;

    // Leave this commented out for now as it is not used

    // read filename from memory
    // int length = (int)IORD_32DIRECT(MF_BASE, FILE_NAME_LEN);
    // char filename[length];
    // // putchar('\n');
    // // putchar('-');
    // for (int i = 0; i <= length; i++)
    // {
    //     filename[i] = (char)IORD_8DIRECT(MF_BASE, FILE_NAME + i);
    //     // putchar(fileName[i]);
    // }
    // strcpy(fileptr, filename);
    // // putchar('\n');
    // return length;
}


int getIterCount(){
    while (getProgStatus() != 1);

    return (int)IORD_32DIRECT(MF_BASE, ITER_COUNT);
}

int getWidth(){
    while (getProgStatus() != 1);

    return (int)IORD_32DIRECT(MF_BASE, WIDTH);
}

int getHeight(){
    while (getProgStatus() != 1);

    return (int)IORD_32DIRECT(MF_BASE, HEIGHT);
}

int getQualityFactor(){
    while (getProgStatus() != 1);

    return (int)IORD_32DIRECT(MF_BASE, QUALITY_FACTOR);
}

int getImageFormat(){
    while (getProgStatus() != 1);

    return (int)IORD_32DIRECT(MF_BASE, IMAGE_FORMAT);
}
