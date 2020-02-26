#ifndef IMAGEPROCESSING_H_
#define IMAGEPROCESSING_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void darkenImage(unsigned char* imageData, int imageWidth, int imageHeight);

void adjustImageBrightness(unsigned char* iData, int iWidth, int iHeight,
		bool brighten, unsigned char adjustmentValue);

void effect(unsigned char* iData, int iWidth, int iHeight);

#endif /* IMAGEPROCESSING_H_ */
