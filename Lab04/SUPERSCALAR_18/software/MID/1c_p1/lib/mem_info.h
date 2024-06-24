#ifndef MEM_INFO_H
#define MEM_INFO_H

#include "queue.h"

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

int getIterCount();
int getWidth();
int getHeight();
int getQualityFactor();
int getImageFormat();

void setMemInfo(int iterCount, int width, int height, int qualityFactor, int imageFormat);

void setProgStatus(int status);
int getProgStatus();

void setFileName(int length, char *fileName);
int getFileName(char *fileName);


#endif // MEM_INFO_H