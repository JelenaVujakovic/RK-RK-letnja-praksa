
#include "imageProcessing.h"
#include "bmp.h"

#define BW_TRESHOLD 128
const unsigned char darkenFactor = 192;
const int brightnessMinimum = 20;
const int brightnessMaximum = 220;


void darkenImage(unsigned char* iData, int iWidth, int iHeight)
{
	int i;
	int j;
	unsigned char* ptr = iData;
	
	for (i=0; i<iHeight; i++)
	{
		for (j=0; j<iWidth; j++)
		{
			*ptr = *ptr + darkenFactor;
			ptr++;
			*ptr = *ptr + darkenFactor;
			ptr += 1;
			*ptr = *ptr + darkenFactor;
			ptr += 1;
		}
	}
}

void adjustImageBrightness(unsigned char* iData, int iWidth, int iHeight,
		bool brighten, unsigned char adjustmentValue)
{
	int i;
	int newValue;

	for (i=0; i<iWidth*iHeight*3; i++)
	{
		newValue = iData[i];
		if(brighten)
		{
			newValue += adjustmentValue;
		}
		else
		{
			newValue -= adjustmentValue;
		}

		if(newValue < brightnessMinimum)
		{
			newValue = brightnessMinimum;
		}
		else if(newValue > brightnessMaximum)
		{
			newValue = brightnessMaximum;
		}

		iData[i] = newValue;
	}
}

void effect(unsigned char* iData, int iWidth, int iHeight)
{
	unsigned char* ptr = iData;
	int i;
	int j;
	int k;
	
	for (i=0; i<iHeight; i++)
	{
		for (j=0; j<iWidth; j++)
		{
			for (k=0; k<3; k++)
			{
				if(*(ptr+k) > BW_TRESHOLD)
				{
					*(ptr+k) = 255;
				}
				else
				{
					*(ptr+k) = 0;
				}
			}
			ptr += 3;
		}
	}
}
