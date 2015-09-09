#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define N	(10)

int stack[N];
size_t i = 0;
int line = 1;
int c;

void error(char c)
{
	printf("line %d: error at %c\n", line++, c);
	while ((c = getchar()) != '\n') {
	}
	i = 0;
}

int main(void)
{
	int tmp = 0;
	while ((c = getchar()) != EOF) {
		tmp = 0;
		if (isdigit(c)) {
			while (isdigit(c)) {
				tmp = 10 * tmp + c - '0';
				c = getchar();
			}
			if (i >= 10) {
				error(tmp + '0');
				continue;
			} else {
				stack[i++] = tmp;
			}
		}

		if (!isdigit(c)) {
			switch (c) {
			case '*':
				stack[i-2] = stack[i-2] * stack[i-1];
				i--;
				break;
			case '/':
				if (stack[i-1] == 0) {
					error('/');

				} else {
					stack[i-2] = stack[i-2] / stack[i-1];
					i--;
				}
				break;
			case '+':
				if (i <= 1) {
					error('+');
				} else {
					stack[i-2] = stack[i-1] + stack[i-2];
					i--;
				}
				break;
			case '-':
				stack[i-2] = stack[i-2] - stack[i-1];
				i--;
				break;
			case ' ':
				break;
			case '\n':
				if (i != 1) {
					printf("line %d: error at \\n\n", line++);
				} else {
					printf("line %d: %d\n", line++, stack[--i]);
				}
				i = 0;
				break;
			default:
				error(c);
				break;
			}
		}
	}
	return 0;
}
