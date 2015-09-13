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
	string = malloc(max * sizeof(char) + 10);
	char * longest;
	longest = malloc(max * sizeof(char) + 10);
	while ((c=getchar()) != EOF) {
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
			if (length >= max) {
				max = 2*max;
				string = realloc(string, max * sizeof(char));
				longest = realloc(longest, max * sizeof(char));
			}
			*(string + length++) = c;
			continue;
		}
		if (length >= longest_length) {
			longest_length = length;
			strcpy(longest, string);
		}
		length = 0;
	}
	free(string);
	printf(prnt, longest_length, longest);
	free(longest);
	return 0;
}
