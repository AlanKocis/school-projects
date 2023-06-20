#define _CRT_SECURE_NO_WARNINGS
#include "info.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* returns how many times malloc was called + 1 (for use in for loop) */
int readInfo(info** infoArray, FILE* fpin) {
	char tempString[30];
	int stage = 1;
	info tempObj = { "", "", "", 0 };
	int i = 0;

	while ((fgets(tempString, 30, fpin)) != NULL) {


		switch (stage)
		{
		case 1: /* name */
			strcpy(tempObj.name, tempString);
			stage = 2;
			break;
		case 2: /* address */
			strcpy(tempObj.address, tempString);
			stage = 3;
			break;
		case 3: /* city/state */
			strcpy(tempObj.cityState, tempString);
			stage = 4;
			break;
		case 4: /* zipcode  - program will only allocate memory if a complete structure is found */
			tempObj.zipCode = atoi(tempString);
			*(infoArray + i) = (info*)malloc(sizeof(info));
			*(*(infoArray + i)) = tempObj;
			i++;
			stage = 1;
			break;
		}
	}
	return i;
}

void freeInfo(info** infoArray, int size) {
	for (int i = 0; i < size; i++) {
		free((void*) infoArray[i]);
	}
}

void printInfo(info** infoArray, int size, FILE* fpout) {
	for (int i = 0; i < size; i++) {
		fputs((*(infoArray + i))->name, fpout);
		fputs((*(infoArray + i))->address, fpout);
		fputs((*(infoArray + i))->cityState, fpout);
		fprintf(fpout, "%d\n\n", (*(infoArray + i))->zipCode);
	}
}

void sortInfo(info** infoArray, int size) {
	info* temp;
	/* bubble sort */
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if ((*(infoArray + j))->zipCode > (*(infoArray + j + 1))->zipCode) {
				temp = *(infoArray + j);
				*(infoArray + j) = *(infoArray + j + 1);
				*(infoArray + j + 1) = temp;
			}
		}
	}

}
