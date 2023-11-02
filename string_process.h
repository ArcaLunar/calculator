#ifndef _STRING_PROCESS_H_
#define _STRING_PROCESS_H_

#include "replace_var.h"
#include "expression_calc.h"
#include "var_system.h"
#include "utils.h"

long double processString( char a[], struct Varsys* arr ) {
	int result = findEq( a );

	long double ans;

	if (result == -1) {
		ans = parseCalc( a, arr );
	}
	else {
		char curvar[2000];
		clearArray( curvar, 2000 );

		int indexCurVar = 0;
		for (int i = 0; i < result; i++) {
			if (a[i] == ' ') continue;
			if (a[i] == '=') break;
			curvar[indexCurVar++] = a[i];
		}

		ans = parseCalc( a + result + 1, arr );
		//printf("%s: ", curvar);
		reassign( arr, curvar, ans );
	}
	return ans;
}

#endif