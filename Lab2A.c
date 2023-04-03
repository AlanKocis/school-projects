/*
Kocis, Alan
Lab 2A
3/6/23

Program that takes a string of characters, removes all newlines, punctuation, and extra spaces until the EOF character is found.
Additionally formats the input text so that there is one word per line. Using the command prompt, the input can be redirected from 
a .txt file and output can be redirected to another txt file.
*/

#include <stdio.h>

int main() {

	int c;
	int is_space = 0;
	int print_newlines = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			is_space = 1;
		}
		else if (c != ',' && c != '.' && c != '\'' && c != '"' && c != '?' && c != '!' && c != ';' && c != ':') {
			if (is_space == 1 && print_newlines == 1) {
				putchar('\n');
			}
			putchar(c);
			is_space = 0;
			print_newlines = 1;
			
		}
	}
	return 0;
}



/*
Input:







						 The Parsnip



The parsnip,      children, I repeat,
is simply an anemic    beet,
some people call the  parsnip edible;
myself,             I found this claim incredible.
*/

/*
Output:
The
Parsnip
The
parsnip
children
I
repeat
is
simply
an
anemic
beet
some
people
call
the
parsnip
edible
myself
I
found
this
claim
incredible
*/