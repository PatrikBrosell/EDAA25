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
	string = malloc(longest_length * sizeof(char) + 10);
//	string = malloc(max * sizeof(char) + 10);
	char * longest;
	longest = malloc(longest_length * sizeof(char) + 10);
//	longest = malloc(longest_length * sizeof(char) + 10);
	do {
	c = getchar();
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
			*(string + length++) = c;
			if (length >= longest_length) {
//				printf("inne\n");
//				max = 2*max;
				longest_length = length;
//				printf("%d\n", longest_length);
//				printf("%d\n", length);
				string = realloc(string, 100 + longest_length * sizeof(char));
				longest = realloc(longest, 100 + longest_length * sizeof(char));
				strcpy(longest, string);
			}
			continue;
		} else {
//		else if (length >= longest_length) {
//			longest_length = length;
//			strcpy(longest, string);
//		}
		length = 0;
		}
	} while (c != EOF);

	free(string);
	printf(prnt, longest_length, longest);
	free(longest);
	return 0;
}
