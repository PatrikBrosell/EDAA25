#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
	int longest = 0;
	int c;
	int longest_start = 0;
	int i = 0;
	int tmp_start = 0;

	char *string = malloc(100);

	while ((c=getchar()) != EOF) {
		if ((c > 'z' || c < 'a') && (c < 'A' || c > 'Z')) {
			*(string + i) = '\0';
			tmp_start = ++i;
		}
		else {
			*(string + i++) = c;
		}
		if (i - tmp_start > longest) {
			longest_start = tmp_start;
			longest = i - tmp_start;
		}
		if (i >= longest_start + 1) {
			string = realloc(string, i * 2);
		}

	}
	printf("%d characters in longest word: %s\n", longest, string + longest_start);
	free(string);
	return 0;
}
