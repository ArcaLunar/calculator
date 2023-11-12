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
		char f[2000];
		clearArray( f, 2000 );
		int index = 0;
		for (int i = result + 1; i < strlen( a ); i++) {
			if (a[i] == ' ') continue;
			else f[index++] = a[i];
		}
		ans = parseCalc( f, arr );
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

		// remove spaces
		char f[2000];
		clearArray( f, 2000 );
		int index = 0;
		for (int i = result + 1; i < strlen( a ); i++) {
			if (a[i] == ' ') continue;
			else f[index++] = a[i];
		}
		//  ...and calculate the expression on the right side of the assignment
		ans = parseCalc( f, arr );
		reassign( arr, curvar, ans );
	}
	return ans;
}

#endif