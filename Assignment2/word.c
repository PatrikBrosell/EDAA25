#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	int longest = 0;
	int c;
	int max = 100;
	int longest_start = 0;
	int i = 0;
	int tmp_start = 0;
	char *string = malloc(max);

	while ((c=getchar()) != EOF) {
		if (i >= max) {
			max = 2 * max;
			string = realloc(string, max);
		}
		if ((c > 'z' || c < 'a') && (c < 'A' || c > 'Z')) {
			*(string + i) = '\0';
			if ((i - tmp_start) > longest) {
				longest = i - tmp_start;
				longest_start = tmp_start;
			}
			tmp_start = ++i;
		} else {
			*(string + i++) = c;
		}
	}

	printf("%d characters in longest word: %s\n", longest, string + longest_start);
	free(string);
	return 0;
}
