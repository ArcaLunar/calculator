#ifndef _STRING_PROCESS_H_
#define _STRING_PROCESS_H_

#include "replace_var.h"
#include "expression_calc.h"

void processString( char a[] ) {
	int result = findEq( a );
	if (result == -1) {
		parseCalc( a );
	}
	else {
		char tmp[2000];
		replaceVar( a + result + 1, tmp );
		parseCalc( tmp );
	}
}

#endif