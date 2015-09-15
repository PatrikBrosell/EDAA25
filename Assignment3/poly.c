#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "error.h"
#include "poly.h"

#define MAX 10


struct poly_t {
	int expo[MAX];
	int coef[MAX];
};

poly_t* new_poly_from_string(const char* input)
{
	poly_t* poly = calloc(1, sizeof(poly_t));
	int last_is_expo = 1;
	int sign = 1; //1 er plus, -1 er minus
	int c = 0;
	int nbr = 0;
	int ci = 0; //coef index
	int ei = 0; //expo index
	int stop = 0;
	while ((c = *input++) != '\0' && stop == 0) {
		while(isdigit(c)) {
			nbr = 10 * nbr + c - '0';
			if (strlen(input) == 0) {
				stop = 1;
			}
			c = *input++;
		}

		if (last_is_expo == 1 && nbr != 0) {
//			da e de en coeff
			poly->coef[ci++] = sign*nbr;
			last_is_expo = 0;
			nbr = 0;
			continue;
		}
		if (last_is_expo == 1 && c == 'x') {
//			da e de coef 1
			poly->coef[ci++] = 1;
			last_is_expo = 0;
			nbr = 0;
			continue;
		}
		if (last_is_expo == 0 && nbr != 0) {
//			da e de exponent
			poly->expo[ei++] = nbr;
			last_is_expo = 1;
			nbr = 0;
			continue;
		}
		if (c == '+') {
			sign = 1;
			if (last_is_expo == 0) {
				poly->expo[ei++] = 1;
				last_is_expo = 1;
			}
		}
		if (c == '-') {
			sign = -1;
			if (last_is_expo == 0) {
				poly->expo[ei++] = 1;
				last_is_expo = 1;
			}
		}
		nbr = 0; //reset nbr at end of loop.
		if (c == '\0') {
			break;
		}
	}
	return poly;
}

void free_poly(poly_t* poly)
{
	free(poly);
}

poly_t* mul(poly_t* a, poly_t* b)
{
	poly_t* r = calloc(100, sizeof(poly_t));

	int coef[MAX*MAX] = { 0 };
	int expo[MAX*MAX] = { 0 };

	int k = 0;
	for(int i = 0; i < MAX; i++) {
		for(int j = 0; j < MAX; j++) {
//			r->coef[k] = a->coef[i] * b->coef[j];
//			r->expo[k] = a->expo[i] + b->expo[j];
			coef[k] = a->coef[i] * b->coef[j];
			expo[k] = a->expo[i] + b->expo[j];
			k++;
		}
	}
	//sort
	for(int i = 0; i < MAX*MAX; i++) {
		for(int j = 0; j < MAX*MAX; j++){
//			if (r->expo[i] == r->expo[j] && i != j) {
			if (expo[i] == expo[j] && i != j) {
//				r->coef[i] = r->coef[i] + r->coef[j];
//				r->coef[j] = 0;
				coef[i] = coef[i] + coef[j];
				coef[j] = 0;
				expo[j] = 0;
			}
		}
	}
	int tmp = 0;
	for (int i = 0; i < MAX*MAX; i++) {
		if ((coef[i] == 0) && (expo[i] == 0)) {
			tmp = i;
			// i e forsta tomma
			while((coef[tmp++] == 0)) {
				 if ((tmp < MAX*MAX) &&(coef[tmp] != 0)) {
					coef[i] = coef[tmp];
					expo[i] = expo[tmp];
					coef[tmp] = 0;
					expo[tmp] = 0;
					break;
				}
			}
		}
	}

	memcpy(r->coef, coef, MAX*sizeof(int));
	memcpy(r->expo, expo, MAX*sizeof(int));
	return r;
}

void print_poly(poly_t* poly)
{
	int tmpcoef = 0;
	int tmpexpo = 0;
	for (int i = 0; i < MAX; i++) {
		tmpcoef = poly->coef[i];
		tmpexpo = poly->expo[i];
		if (tmpcoef == 0) {
			continue;
		}

		if (tmpcoef < 0) {
			printf(" - ");
			tmpcoef = -tmpcoef;
		} else if (i != 0 && tmpcoef != 0) {
			printf(" + ");
		}

		switch (tmpcoef) {
		case 0:
			//do nothing
			break;
		case 1:
			if (tmpexpo != 0) {
//				printf("x");
			} else {
				printf("%d", tmpcoef);
			}
			break;
		default:
			printf("%d", tmpcoef);
		}

		switch (tmpexpo) {
		case 0:
			//do nothing
			break;
		case 1:
			printf("x");
			break;
		default:
			printf("x^%d", tmpexpo);

		}
	}
	printf("\n");
}
