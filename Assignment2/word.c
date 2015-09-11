#include <stdio.h>
#include <ctype.h>
#include <string.h>

int length = 0;
int longest_length = 0;
int c;
int max = 10;
char prnt[] = "%d characters in longest word: %s\n";

int main(void)
{
	char * string;
	string = malloc(max * sizeof(char));
	char * longest;
	longest = malloc(max * sizeof(char));
	do {
	c = getchar();
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
			if (length >= max) {
				max = 2*max;
				string = realloc(string, max);
				longest = realloc(longest, max);
			}
			*(string + length++) = c;
			continue;
		}
		else if (length >= longest_length) {
			longest_length = length;
			strcpy(longest, string);
		}
		length = 0;
	} while (c != EOF);

	free(string);
	printf(prnt, longest_length, longest);
	free(longest);
	return 0;
}
