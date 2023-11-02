#ifndef _EXPRESSION_CALC_H_
#define _EXPRESSION_CALC_H_

#include <string.h>
#include <math.h>
#include <stdio.h>

#include "utils.h"
#include "stack.h"
#include "char_operate.h"

long double parseDouble(char a[]) {
    long double ans = 0.0; // Store final answer
    long double multiplier = 10.0;
    
    int index_of_decimal_point = 0; // Find out the index of the decimal point. (or equals to strlen(a) if integer)
    for(; index_of_decimal_point < strlen(a); index_of_decimal_point++)
        if(a[index_of_decimal_point] == '.') break;
    
    // Calculate integer part
    int index = 0;
	while (index < index_of_decimal_point) {
		ans = ans * multiplier + 1.0 * (a[index] - '0');
		index++;
	}
    // Calculate decimal part
    index = strlen(a) - 1;
    long double after_point = 0.0;
    multiplier = 0.1;
	while (index > index_of_decimal_point) {
		after_point = after_point * multiplier + 1.0 * (a[index] - '0');
		index--;
	}
	ans += after_point * 0.1;
	// printf("Transformed: %Lg\n", ans);
	return ans;
}

long double getNextDouble(char a[], int* cur) {
    int index = 0;
    int i;
    char targ[MAXN];
    clearArray(targ, MAXN);
    for(i = *cur; i < strlen(a); i++) {
        if(a[i] == ' ') continue;
        if(!(a[i] >= '0' && a[i] <= '9' || a[i] == '.')) break;
        targ[index++] = a[i];
    }
	*cur = i;
	// printf("Parsed: %s\n", targ);
	return parseDouble( targ );
}

long double calculate(struct dataStack *a) {
    struct dataStack tmp;
	initData( &tmp );
	// showData(a);
	for (int i = 0; i < a->top; i++) {
        if(a->aux[i] == 1) pushData(&tmp, a->data[i]);
        else {
            long double a1 = popData(&tmp);
            long double a2 = popData(&tmp);
            pushData(&tmp, returnCalcAnswer(a->data[i], a2, a1));
        }
    }
    return tmp.data[0];
}

long double parseCalc(char a[]) {
    struct operatorStack ost;
	struct dataStack dst;
	initOp( &ost );
	initData( &dst );
	int index = 0;

	while (index < strlen( a )) {
		// printf( "Works Well\n" );
		if (a[index] == ' ') {
			index++;
			continue;
		}
		else if (isOperator( a[index] ) == -1) {
			pushData( &dst, getNextDouble( a, &index ) );
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
	}

	long double ret = calculate( &dst );
	// printf( "%Lg\n", ret );
	return ret;
}

#endif
