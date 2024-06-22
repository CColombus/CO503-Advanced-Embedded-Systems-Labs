#ifndef MEM_INFO_H
#define MEM_INFO_H

#include "queue.h"

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