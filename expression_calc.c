#include "expression_calc.h"

#include "utils.h"
#include "stack.h"
#include "char_operate.h"
#include "var_system.h"

#include <string.h>
#include <math.h>
#include <stdio.h>

long double parseDouble( char a[] ) {
	long double ans = 0.0; // Store final answer
	long double multiplier = 10.0;

	int index_of_decimal_point = 0; // Find out the index of the decimal point. (or equals to strlen(a) if integer)
	for (; index_of_decimal_point < strlen( a ); index_of_decimal_point++)
		if (a[index_of_decimal_point] == '.') break;

	// Calculate integer part
	int index = 0;
	while (index < index_of_decimal_point) {
		ans = ans * multiplier + 1.0 * (a[index] - '0');
		index++;
	}
	// Calculate decimal part
	index = strlen( a ) - 1;
	long double after_point = 0.0;
	multiplier = 0.1;
	while (index > index_of_decimal_point) {
		after_point = after_point * multiplier + 1.0 * (a[index] - '0');
		index--;
	}
	ans = ans + after_point * 1.0 / 10;
	return ans;
}

long double getNextDouble( char a[], int* cur, struct Varsys* arr ) {
	int index = 0; // To store the temporary number or variable
	int i;
	char targ[MAXN]; // To store the temporary number or variable
	clearArray( targ, MAXN ); // Clear and initialize the array

	// Add characters to `targ` until the next character is an operator
	for (i = *cur; i < strlen( a ); i++) {
		if (a[i] == ' ' || a[i] == ';') continue;
		if (isOperator( a[i] ) != -1) break;
		targ[index++] = a[i];
	}
	// Update `cur` to the index of the next operator
	*cur = i;
	// Judges whether the parsed string is a number or a variable
	// 1=number, 0=variable
	int isNumber = 1;
	for (int i = 0; i < index; i++) {
		if (!((targ[i] >= '0' && targ[i] <= '9') || targ[i] == '.')) {
			isNumber = 0;
			break;
		}
	}
	if (isNumber == 1) return parseDouble( targ );
	else return findVar( arr, targ );
}

long double calculate( struct dataStack* a ) {
	struct dataStack tmp;
	initData( &tmp );
	for (int i = 0; i < a->top; i++) {
		if (a->aux[i] == 1) pushData( &tmp, a->data[i] ); // If is number, push to stack
		else { // If is operator, pop two numbers and calculate. And then push back to stack again
			long double a1 = popData( &tmp );
			long double a2 = popData( &tmp );
			pushData( &tmp, returnCalcAnswer( a->data[i], a2, a1 ) );
		}
	}
	return tmp.data[0]; // Return final answer
}

long double parseCalc( char a[], struct Varsys* arr ) {
	struct operatorStack ost; // Operator stack
	struct dataStack dst; // Data stack
	initOp( &ost );
	initData( &dst );

	int index = 0; // Current index of the string

	while (index < strlen( a )) {
		if (a[index] == ' ' || a[index] == ';') { // Skip spaces and semicolons
			index++;
			continue;
		}
		else if (isOperator( a[index] ) == -1) { // If is not operator, get next number or variable, and push to stack...
			pushData( &dst, getNextDouble( a, &index, arr ) );
			dst.aux[dst.top - 1] = 1; // ...and set the aux to 1, indicating that it is a number
		}
		else if (isOperator( a[index] ) != -1) { // If is operator...
			if (isOperator( a[index] ) == OP_SUB && !((a[index-1]>='0' && a[index-1]<='9') || a[index-1]=='.' || (a[index-1]>='a' && a[index-1]<='z') || (a[index-1]>='A' && a[index-1]<='Z'))) {
				pushData( &dst, 0 );
				dst.aux[dst.top - 1] = 1;
				pushOp( &ost, '-' );
			}
			else if (isOperator( a[index] ) == OP_LEFT_BRACE) { // ...If is left brace, push to operator stack
				pushOp( &ost, a[index] );
			}
			else if (isOperator( a[index] ) == OP_RIGHT_BRACE) { // ...If is right brace, pop all operators until left brace...
				while (topOp( &ost ) != '(') {
					pushData( &dst, isOperator( popOp( &ost ) ) ); // ...and push them to data stack
					dst.aux[dst.top - 1] = 0; // ...and set the aux to 0, indicating that it is an operator
				}
				popOp( &ost ); // Pop out remaining left brace
			}
			else if (ost.top == 0 || topOp( &ost ) == '(') pushOp( &ost, a[index] );
			// ...If is operator and operator stack is empty or top is left brace, push to operator stack
			else if (precede( a[index] ) > precede( topOp( &ost ) )) pushOp( &ost, a[index] );
			// ...If is operator and precedence is higher than top operator, push to operator stack
			else { // ...If is operator and precedence is lower than top operator, pop all operators until precedence is higher...
				//while (ost.top != 0 && topOp( &ost ) != '(') {
				while (ost.top != 0 && precede( a[index] ) <= precede( topOp( &ost ) )) {
					pushData( &dst, isOperator( popOp( &ost ) ) ); // ...and push them to data stack
					dst.aux[dst.top - 1] = 0; // ...and set the aux to 0, indicating that it is an operator
				}
				pushOp( &ost, a[index] ); // Push the current operator to operator stack
			}
			index++; // Increase the index by 1, processing next character
		}
	}
	while (ost.top != 0) {
		pushData( &dst, isOperator( popOp( &ost ) ) ); // Pop out all remaining operators and push to data stack
		dst.aux[dst.top - 1] = 0; // Set the aux to 0, indicating that it is an operator
	}

	long double ret = calculate( &dst ); // Calculate the final answer
	return ret;
}