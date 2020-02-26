/*
 ============================================================================
 Name        : e_bitmap.c
 Author      : rt-rk
 Version     :
 Copyright   : Your copyright notice
 Description : image processing example
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
#include "imageProcessing.h"

#define __ARG_NUM__ 2

int main(int argc, char* argv[])
{
	int err = 0;
	BITMAPFILEHEADER bitmapFileHeader;
	BITMAPINFOHEADER bitmapInfoHeader;
	unsigned char* bitmapData;

	if ( argc != __ARG_NUM__ )
	{
		printf("Enter input file path \n");
		return 1;
	}
	
	printf("Applying brightness\n");	
	bitmapData = LoadBitmapFile(argv[1],&bitmapFileHeader, &bitmapInfoHeader);
	if(!bitmapData)
	{
		printf("Error! Can't open input bitmap file: %s\n", argv[1]);
		return 1;
	}
	
	// Apply image brightness to image
	adjustImageBrightness(bitmapData, bitmapInfoHeader.biWidth,
		bitmapInfoHeader.biHeight, false, 70);
	err = SaveBitmapFile("out_brightness.bmp", &bitmapFileHeader,
		&bitmapInfoHeader, bitmapData);
	if (err) 
	{
		printf("Error trying to save bitmap\n");
	}
	free(bitmapData);

	printf("Applying dark image\n");
	bitmapData = LoadBitmapFile(argv[1], &bitmapFileHeader, &bitmapInfoHeader);
	if(!bitmapData)
	{
		printf("Error! Can't open input bitmap file: %s\n", argv[1]);
		return 1;
	}
	
	darkenImage(bitmapData, bitmapInfoHeader.biWidth,
		bitmapInfoHeader.biHeight);
	err = SaveBitmapFile("out_dark.bmp", &bitmapFileHeader,
		&bitmapInfoHeader, bitmapData);
	if (err)
	{
		printf("Error trying to save bitmap\n");
	}
	free(bitmapData);

	printf("Applying effect\n");
	bitmapData = LoadBitmapFile(argv[1], &bitmapFileHeader, &bitmapInfoHeader);
	if(!bitmapData)
	{
		printf("Error! Can't open input bitmap file: %s\n", argv[1]);
		return 1;
	}
	
	effect(bitmapData, bitmapInfoHeader.biWidth,
		bitmapInfoHeader.biHeight);
	err = SaveBitmapFile("out_bw.bmp", &bitmapFileHeader,
		&bitmapInfoHeader, bitmapData);
	if (err) 
	{
		printf("Error trying to save bitmap\n");
	}
	free(bitmapData);

	return EXIT_SUCCESS;
}
