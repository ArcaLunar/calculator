#include <stdio.h>
#include <stdlib.h>
#include "expression_calc.h"

int main() {
	char a[1000];
	while (1) {
		clearArray( a, 1000 );
		char c;
		int index = 0;
		while ((c = getchar()) != '\n') {
			a[index++] = c;
		}
		printf( "%Lg\n", parseCalc( a ) );
	}
}

