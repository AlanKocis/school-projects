#include <stdio.h>
#include <stdlib.h>

void randomString(char* string);
int enterString(char* string);
int enterCharacter();
void strFilter(char* s1, char* s2, char ch);
void clearInputBuffer();
int isUpperAlpha(int c);

int main() {
	char s1[41];
	char s2[22];	/* size 22, 1 for newline/null after 20 characters, and 1 more to check for string length errors  */
	char userContinue = 'n';
	char replacementChar;

	randomString(s1);
	puts(s1);

	do {
		if (enterString(s2) == 0) {
			if ((replacementChar = enterCharacter()) > 0) {
				strFilter(s1, s2, replacementChar);
				puts("Filtered String: ");
				puts(s1);
			}
		}
		puts("Replace characters again? Enter Y/N");
		userContinue = getchar();
		clearInputBuffer();
	} while (userContinue == 'y' || userContinue == 'Y');
}

void randomString(char* string) {
	time_t t;
	srand((unsigned)time(&t));
	char letters[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	for (int i = 0; i < 40; i++) {
		*(string + i) = letters[rand() % 26];
	}
	string[40] = '\0';
}

int enterString(char* string) {
	int size = 0;
	int i = 0;
	puts("Enter characters you want to replace:");
	fgets(string, 22, stdin);
	/* error check */
	while (*(string + i) != '\0' && *(string + i) != '\n') {
		if (!isUpperAlpha(*(string + i))) {
			puts("Error: string must contain uppercase letters 'A' - 'Z'");
			return -1;
		}
		size++;
		i++;
	}

	if (size > 20) {
		puts("Error: string cannot be longer than 20 characters");
		clearInputBuffer();
		return -1;
	}

	if (size < 2) {
		puts("Error: string cannot be less than two characters long");
		return 1;
	}

	return 0;
}

int enterCharacter() {
	/* if negative, error, if not, then it's a character value */
	int c;
	int error;
	puts("Enter replacement character: ");
	c = getchar();
	if ((error = getchar()) != '\n') {
		puts("Error: more than one replacement character entered\n");
		/* clear input buffer */
		clearInputBuffer();
		return -1;
	}
	else {
		return c;
	}
}

void strFilter(char* s1, char* s2, char ch) {
	int i = 0;
	while (*(s2 + i) != '\0' && *(s2 + i) != '\n') {
		int j = 0;
		while (*(s1 + j) != '\0' && *(s1 + j) != '\n') {
			if (*(s1 + j) == *(s2 + i)) {
				*(s1 + j) = ch;
			}
			j++;
		}
		i++;
	}
}

void clearInputBuffer() {
	int error = 0;
	while (error != '\n' && error != EOF)
		error = getchar();
}

int isUpperAlpha(int c) {
	return (c >= 'A' && c <= 'Z');
}

/* output
	CFOYPXBVEXIYUIYSEPLTJSBZITYAVYCOQEXYTPQT
	Enter characters you want to replace:
	ABC
	Enter replacement character:
	*
	Filtered String:
	*FOYPX*VEXIYUIYSEPLTJS*ZITY*VY*OQEXYTPQT
	Replace characters again? Enter Y/N
	Y
	Enter characters you want to replace:
	FTQIZ
	Enter replacement character:
	^
	Filtered String:
	*^OYPX*VEX^YU^YSEPL^JS*^^^Y*VY*O^EXY^P^^
	Replace characters again? Enter Y/N
	y
	Enter characters you want to replace:
	abc
	Error: string must contain uppercase letters 'A' - 'Z'
	Replace characters again? Enter Y/N
	y
	Enter characters you want to replace:
	123
	Error: string must contain uppercase letters 'A' - 'Z'
	Replace characters again? Enter Y/N
	y
	Enter characters you want to replace:
	A
	Error: string cannot be less than two characters long
	Replace characters again? Enter Y/N
	y
	Enter characters you want to replace:
	ABC
	Enter replacement character:
	**************************************
	Error: more than one replacement character entered

	Replace characters again? Enter Y/N
	y
	Enter characters you want to replace:
	MORETHANTWENTYCHARACTERSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
	Error: string cannot be longer than 20 characters
	Replace characters again? Enter Y/N
	n

	C:\Users\alank\source\repos\Lab5B\x64\Debug\Lab5B.exe (process 28628) exited with code 0.
	Press any key to close this window . . .



*/