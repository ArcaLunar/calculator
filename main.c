#include <stdio.h>
#include <stdlib.h>
#include "expression_calc.h"
#include "string_process.h"
#include "replace_var.h"
#include "var_system.h"

int main() {
	char a[1000];
	struct Varsys arr;
	initVar( &arr );

	while (1) {
		clearArray( a, 1000 );

		char c;
		int index = 0;
		printf( ">>>>> " );
		while ((c = getchar()) != '\n') {
			a[index++] = c;
		}

		if (findCol( a ) != 0) {
			processString( a, &arr );
		}
		else printf( "%Lf\n", processString( a, &arr ) );
	}
}

// Run in terminal using `gcc main.c -o a -lm`