#ifndef _PARSE_DOUBLE_H_
#define _PARSE_DOUBLE_H_

#include <string.h>
#include <math.h>

#include "utils.h"
#include "stack.h"

int findEq( char a[] ) {
	for (int i = 0; i < strlen( a ); i++) {
		if (a[i] == '=') return i;
	}
	return -1;
}

int findCol( char a[] ) {
	if (a[strlen( a ) - 1] == ';') return 1;
	else return 0;
}

void replaceVar( char a[], char cp[] ) {
	
}

#endif
