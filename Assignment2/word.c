#include <stdio.h>
#include <string.h>

int length = 0;
int longest_length = 0;
int c;
int max = 10;
char prnt[] = "%d characters in longest word: %s\n";

int main(void)
{
	char * string = malloc(max);
	char * longest = malloc(max);
	while ((c=getchar()) != EOF) {
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
			*(string + length++) = c;
			if (length >= max) {
				max = 2*max;
				string = realloc(string, max);
				longest = realloc(longest, max);
			}
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
