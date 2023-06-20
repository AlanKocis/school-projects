/*
Kocis, Alan
Lab 8
5/8/23
Program that takes input from a file and dynamically creates memory to store
information including name, address, city/state, and zip code in a struct, sorting them
by zip code in ascending order. Finally, the program writes the sorted output to a file.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "info.h"
/* other includes are in info.c to avoid linker errors */

int main(int argc, char* argv[])
{

	FILE *fpin, *fpout;

	if (argc != 3)
	{
		printf("Error: incorrect command line usage. Formal should be \"filename.exe readfile writefile\"\n");
		return 1;
	}

	if ((fpin = fopen(argv[1], "r")) == NULL)
	{
		printf("Error: could not open input file.\n");
		return 1;
	}

	if ((fpout = fopen(argv[2], "w")) == NULL)
	{
		printf("Error: could not open output file.\n");
		return 1;
	}
	
	int size;
	info* infoArray[50];

	size = readInfo(infoArray, fpin);
	sortInfo(infoArray, size);
	printInfo(infoArray, size, fpout);
	freeInfo(infoArray, size);

	return 0;
}