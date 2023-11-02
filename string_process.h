#ifndef _STRING_PROCESS_H_
#define _STRING_PROCESS_H_

#include "replace_var.h"
#include "expression_calc.h"
#include "var_system.h"
#include "utils.h"

long double processString( char a[], struct Varsys* arr ) {
	int result = findEq( a ); // Whether the string contains an assignment operation

	long double ans;

	if (result == -1) { // If not, directly calculate the expression
		ans = parseCalc( a, arr );
	}
	else {
		// If yes, parse the variable name...
		char curvar[NAME_MAX_LENGTH];
		clearArray( curvar, NAME_MAX_LENGTH );

		int indexCurVar = 0;
		for (int i = 0; i < result; i++) {
			if (a[i] == ' ') continue;
			if (a[i] == '=') break;
			curvar[indexCurVar++] = a[i];
		}

		//  ...and calculate the expression on the right side of the assignment
		ans = parseCalc( a + result + 1, arr );
		reassign( arr, curvar, ans );
	}
	return ans;
}

#endif