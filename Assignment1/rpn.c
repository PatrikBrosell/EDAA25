//Patrik Brosell dat12pbr
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define N	(10)

int stack[N];
size_t i = 0;
int line = 1;
int c;

//void push(int val)
//{
//	if (i < 10) {
//		stack[i++] = val;
//	}
//}

//int pop()
//{
//	if (i > 0) {
//		return stack[--i];
//	} else if (i == 0) {
//		return stack[i];
//	}
//	return -1;
//}

//void flush()
//{
//	while ((c = getchar()) != '\n') {
//		c = getchar();
//	}
//	i = 0;
//}

void error(char c)
{
	printf("line %d: error at %c\n", line++, c);
	while ((c = getchar()) != '\n') {
	}
	i = 0;
}

int main(void)
{
//	c = getchar();
	int tmp = 0;
	while ((c = getchar()) != EOF) {
//	do {
		tmp = 0;
		if (isdigit(c)) {
			while (isdigit(c)) {
				tmp = 10 * tmp + c - '0';
				c = getchar();
			}
			if (i >= 10) {
				error(tmp + '0');
//				flush();
				continue;
			} else {
				stack[i++] = tmp;
//				push(tmp);
			}
		}

		if (!isdigit(c)) {
			switch (c) {
			case '*':
				stack[i-2] = stack[i-2] * stack[i-1];
				i--;
//				push(pop() * pop());
				break;
			case '/':
//				tmp = pop();
				if (stack[i-1] == 0) {
//				if (tmp == 0) {
					error('/');
//					flush();

				} else {
					stack[i-2] = stack[i-2] / stack[i-1];
					i--;
//					push(pop() / tmp);
				}
				break;
			case '+':
				if (i <= 1) {
					error('+');
//					flush();
				} else {
					stack[i-2] = stack[i-1] + stack[i-2];
//					push(pop() + pop());
					i--;
				}
				break;
			case '-':
//				tmp = pop();
//				push(pop() - tmp);
				stack[i-2] = stack[i-2] - stack[i-1];
				i--;
				break;
			case ' ':
				break;
			case '\n':
				if (i != 1) {
					printf("line %d: error at \\n\n", line++);
				} else {
//					printf("line %d: %d\n", line++, pop());
					printf("line %d: %d\n", line++, stack[--i]);
				}
				i = 0;
				break;
			default:
				error(c);
//				flush();
				break;
			}
		}
	}
//	} while ((c=getchar()) != EOF);
	return 0;
}
