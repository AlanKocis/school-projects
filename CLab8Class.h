#ifndef INFO_H
#define INFO_H
#include <stdio.h>
typedef struct {
	char name[30];
	char address[30];
	char cityState[30];
	int zipCode;
} info;

int readInfo(info** infoArray, FILE* fpin);		/* returns how many times malloc was called + 1 (for use in for loop) */
void freeInfo(info** infoArray, int size);
void printInfo(info** infoArray, int size, FILE* fpin);
void sortInfo(info** infoArray, int size);

#endif