#ifndef MEM_INFO_H
#define MEM_INFO_H

#include "queue.h"

int getIterCount();
int getWidth();
int getHeight();
int getQualityFactor();
int getImageFormat();

void setMemInfo(int iterCount, int width, int height, int qualityFactor, int imageFormat);

#endif // MEM_INFO_H