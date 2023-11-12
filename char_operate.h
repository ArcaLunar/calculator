#ifndef _CHAR_OPERATE_H_
#define _CHAR_OPERATE_H_

#define OP_ADD (int)'+'
#define OP_SUB (int)'-'
#define OP_MUL (int)'*'
#define OP_DIV (int)'/'
#define OP_POW (int)'^'
#define OP_LEFT_BRACE (int)'('
#define OP_RIGHT_BRACE (int)')'

#include <math.h>

// Judge whether the character `c` is an operator
int isOperator( char );

// Calculate the expression with operator `c` and operands `a` and `b`
long double returnCalcAnswer( long double, long double, long double );

// Judge the precede level of operator `c`
int precede( char );

#endif

