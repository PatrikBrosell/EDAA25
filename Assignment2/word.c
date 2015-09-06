#include <stdio.h>
#include <ctype.h>
#include <string.h>

int length = 0;
int longest_length = 0;
int c;
char string[20000];
char longest[20000];

int main(void)
{
	do {
	c = getchar();
		if (isalpha(c)) {
			string[length++] = c;
		}
		else if (length >= longest_length) {
			longest_length = length;
			strcpy(longest, string);
			length = 0;
		} else {
			length = 0;
		}
	} while (c != EOF);

	printf("%d characters in longest word: %s\n", longest_length, longest);

	return 0;
}
