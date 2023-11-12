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
int isOperator( char c ) {
    if (c == '+') return OP_ADD;
    else if (c == '-') return OP_SUB;
    else if (c == '*') return OP_MUL;
    else if (c == '/') return OP_DIV;
    else if (c == '^') return OP_POW;
    else if (c == ')') return OP_RIGHT_BRACE;
    else if (c == '(') return OP_LEFT_BRACE;
    else return -1;
}

// Calculate the expression with operator `c` and operands `a` and `b`
long double returnCalcAnswer( long double c, long double a, long double b ) {
    int op = (int) c;
    if (op == OP_ADD) return a + b;
    else if (op == OP_SUB) return a - b;
    else if (op == OP_MUL) return a * b;
    else if (op == OP_DIV) return a * 1.0 / b;
    else if (op == OP_POW) {
        return pow( a, b );
    }
}

// Judge the precede level of operator `c`
int precede( char c ) {
    if (c == '+' || c == '-') return 1;
    else if (c == '*' || c == '/') return 2;
    else if (c == '^') return 3;
    return -1;
}

#endif

