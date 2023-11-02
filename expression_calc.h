#ifndef _EXPRESSION_CALC_H_
#define _EXPRESSION_CALC_H_

#include <string.h>
#include <math.h>
#include <stdio.h>

#include "utils.h"
#include "stack.h"
#include "char_operate.h"
#include "var_system.h"

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
	//printf("Transformed .: %Lg\n", after_point);
	ans = ans + after_point*1.0/10;
	//printf("Transformed: %Lg\n", ans);
	return ans;
}

long double getNextDouble( char a[], int* cur, struct Varsys* arr ) {
	int index = 0;
	int i;
	char targ[MAXN];
	clearArray( targ, MAXN );

	for (i = *cur; i < strlen( a ); i++) {
		if (a[i] == ' ' || a[i] == ';') continue;
		if (isOperator( a[i] ) != -1) break;
		targ[index++] = a[i];
	}
	*cur = i;
	int isNumber = 1;
	for (int i = 0; i < index; i++) {
		if (!((targ[i] >= '0' && targ[i] <= '9') || targ[i] == '.')) {
			isNumber = 0;
			break;
		}
	}
	//printf( "Parsed: %s(%d)\n", targ, isNumber );
	if (isNumber == 1) return parseDouble( targ );
	else return findVar( arr, targ );
}


long double calculate( struct dataStack* a ) {
	struct dataStack tmp;
	initData( &tmp );
	//printf( "Show stack A: " );
	//showData( a );
	for (int i = 0; i < a->top; i++) {
		if (a->aux[i] == 1) pushData( &tmp, a->data[i] );
		else {
			long double a1 = popData( &tmp );
			long double a2 = popData( &tmp );
			pushData( &tmp, returnCalcAnswer( a->data[i], a2, a1 ) );
		}
	}
	//printf( "Show stack TMP: " );
	//showData( &tmp );
	return tmp.data[0];
}


long double parseCalc( char a[], struct Varsys* arr ) {
	struct operatorStack ost;
	struct dataStack dst;
	initOp( &ost );
	initData( &dst );
	int index = 0;

	while (index < strlen( a )) {
		// printf( "Works Well\n" );
		if (a[index] == ' ' || a[index] == ';') {
			index++;
			continue;
		}
		else if (isOperator( a[index] ) == -1) {
			pushData( &dst, getNextDouble( a, &index, arr ) );
			dst.aux[dst.top - 1] = 1;
		}
		else if (isOperator( a[index] ) != -1) {
			if (isOperator( a[index] ) == OP_LEFT_BRACE) {
				pushOp( &ost, a[index] );
			}
			else if (isOperator( a[index] ) == OP_RIGHT_BRACE) {
				while (topOp( &ost ) != '(') {
					pushData( &dst, isOperator( popOp( &ost ) ) );
					dst.aux[dst.top - 1] = 0;
				}
				popOp( &ost );
			}
			else if (ost.top == 0 || topOp( &ost ) == '(') pushOp( &ost, a[index] );
			else if (precede( a[index] ) > precede( topOp( &ost ) )) pushOp( &ost, a[index] );
			else {
				while (ost.top != 0 && topOp( &ost ) != '(') {
					pushData( &dst, isOperator( popOp( &ost ) ) );
					dst.aux[dst.top - 1] = 0;
				}
				pushOp( &ost, a[index] );
			}
			index++;
		}
	}
	while (ost.top != 0) {
		pushData( &dst, isOperator( popOp( &ost ) ) );
		dst.aux[dst.top - 1] = 0;
	}

	long double ret = calculate( &dst );
	// printf( "%Lg\n", ret );
	return ret;
}

#endif
