#ifndef _PARSE_DOUBLE_H_
#define _PARSE_DOUBLE_H_

#include <string.h>
#include <math.h>
#include <stdio.h>

#include "utils.h"
#include "stack.h"
#include "var_system.h"

// Find the equal sign in the string. `-1` is returned if not found.
int findEq( char a[] ) {
	for (int i = 0; i < strlen( a ); i++) {
		if (a[i] == '=') return i;
	}
	return -1;
}

// Find the colon in the string. `1` is returned if found, `0` if not.
int findCol( char a[] ) {
	if (a[strlen( a ) - 1] == ';') return 1;
	else return 0;
}


#endif
