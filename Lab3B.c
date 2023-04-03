/*
Kocis, Alan
Lab 3B
3/20/23

This program takes in input from a file, however is also usable from the console, as a set of equations with the form "bbbnnnbbbObbbnnnbbb", where b is any
number of spaces, n is any number of positive integers, and O is an operator (+,-,*,/,%). It reads each equation character by character, and reprints out the equation and its
solution if the equation is valid.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int stage1(int c);
int stage2(int c);
int stage3(int c);
int stage4(int c);

int isDigit(int c);
int isOperator(int c);

int addition(int, int);
int subtraction(int, int);
int multiplication(int, int);
float division(int, int);
int modulo(int, int);

int main() {
    char user_continue;
    int o1, o2;  
    int stage = 0;
    int c = 0;
    char operator = 0;
    int error;

    do {
        user_continue = 'n';
        o1 = -1;
        o2 = -1;
        stage = 1;
        error = 0;
        int noSpace = 0;

        while ((c = getchar()) != '\n' && c != EOF) {

            if (error == 1) {
                continue;
            }

            switch (stage) {

            case 1:
                /* stage 1: find operand 1 or operator if there's no space in between (ie. 1+1) */
                if (c != ' ') {
                    if (noSpace == 1 && isOperator(c)) {
                        if (o1 == -1) {
                            error = 1;
                            break;
                        }
                        operator = c;
                        stage = 3;
                        noSpace = 0;
                        break;
                    }

                    if ((error = stage1(c)) == 1) {
                        o2 = -2; /* preventing double error messages */
                        break;
                    }

                    else {
                        if (noSpace == 0) {
                            o1 = c - '0';
                            noSpace = 1;

                        }
                        else {
                            o1 *= 10;
                            o1 += c - '0';
                        }
                    }
                }
                else if (noSpace == 1) {
                    /* if there's a space after operand1, send to stage 2 */
                    stage = 2;
                    noSpace = 0;
                }
                break;

            case 2:
                /* stage 2: find operator */
                if (c != ' ') {
                    if ((error = stage2(c)) == 1) {
                        o2 = -2;
                        break;
                    }
                    else {
                        operator = c;
                        stage = 3;
                    }
                }
                break;

            case 3:
                /* Stage 3: find operand 2 */
                if (c != ' ') {
                    if ((error = stage3(c)) == 1) {
                        break;
                    }
                    else {
                        if (noSpace == 0) {
                            o2 = c - '0';
                            noSpace = 1;
                        }
                        else {
                            o2 *= 10;
                            o2 += c - '0';
                        }
                    }
                }
                else if (noSpace == 1) {
                    stage = 4;
                }
                break;

            case 4:
                /* Stage 4: make sure no characters except for space after operand 2 */
                error = stage4(c);
                break;
            }

        }

        /* ONCE NEWLINE/EOF HAS BEEN FOUND */
    
        /* final error checks */
        if (operator == '/' && o2 == 0) {
            printf("\nError: division by zero.\n");
            error = 1;
        }


        
        else if (o1 != -1 && o2 == -1) {
            printf("\nError: no character in operand 2.\n");
            error = 1;
        }

        if (error == 0) {
            printf("\n%d %c %d = ", o1, operator, o2);
            switch (operator) {
            case '+':
                printf("%d\n", addition(o1,o2));
                break;
            case '-':
                printf("%d\n", subtraction(o1, o2));
                break;
            case '*':
                printf("%d\n", multiplication(o1, o2));
                break;
            case '/':
                printf("%.3f\n", division(o1, o2));
                break;
            case '%':
                printf("%d\n", modulo(o1, o2));
                break;
            }
        }

        /* prompt user to continue */
        printf("Run program again? Enter y or n: \n");
        scanf("%c", &user_continue);
        getchar();
       
    } while (user_continue == 'Y' || user_continue == 'y');

    return 0;
}

int stage1(int c) {
    if (!isDigit(c)) {
        if (c == '-') {
            printf("\nError: no negative numbers\n");
        }
        else {
            printf("\nError: Unexpected or no character entered in operand 1.\n");
        }
        return 1;
    }
    return 0;
}

int stage2(int c) {
    if (!isOperator(c)) {
        printf("\nError: no valid operator found after space\n");
        return 1;
    }
    return 0;
}

int stage3(int c) {
    if (!isDigit(c)) {
        printf("\nError: Unexpected character entered in operand 2.\n");
        return 1;
    }
    return 0;
}

int stage4(int c) {
    if (c != ' ' && isDigit(c)) {
        printf("\nError: space inbetween digits in operand 2.\n");
        return 1;
    }
    else if (c != ' ') {
        printf("\nError: unexpected character in operand 2.\n");
        return 1;
    }
    return 0;
}

int addition(int o1, int o2) {
    return o1 + o2;
}

int subtraction(int o1, int o2) {
    return o1 - o2;
}

int multiplication(int o1, int o2) {
    return o1 * o2;
}

float division(int o1, int o2) {
    return (float)o1 / (float)o2;
}

int modulo(int o1, int o2) {
    return o1 % o2;
}

int isOperator(int c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%') {
        return 1;
    }
    else {
        return 0;
    }
}

int isDigit(int c) {
	if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0') {
		return 1;
	}
	else {
		return 0;
	}
}

/*
Input:
5+5
y
5 + 6
y
4 * 100000
y
5   -1
y
4%   3
y
5 / 2
y
-5/4
y
6  4  /3
y
5 + 5 1
y
5/3+1
y
10 / 0
y
7 ^ 6
y
   + 7
y
10 *
n
*/

/*
Output:

5 + 5 = 10
Run program again? Enter y or n:

5 + 6 = 11
Run program again? Enter y or n:

4 * 100000 = 400000
Run program again? Enter y or n:

5 - 1 = 4
Run program again? Enter y or n:

4 % 3 = 1
Run program again? Enter y or n:

5 / 2 = 2.500
Run program again? Enter y or n:

Error: no negative numbers
Run program again? Enter y or n:

Error: no valid operator found after space
Run program again? Enter y or n:

Error: space inbetween digits in operand 2.
Run program again? Enter y or n:

Error: Unexpected character entered in operand 2.
Run program again? Enter y or n:

Error: division by zero.
Run program again? Enter y or n:

Error: no valid operator found after space
Run program again? Enter y or n:

Error: Unexpected or no character entered in operand 1.
Run program again? Enter y or n:

Error: no character in operand 2.
Run program again? Enter y or n:
*/