#ifndef _CHAR_OPERATE_H_
#define _CHAR_OPERATE_H_

#define OP_ADD 1
#define OP_SUB 2
#define OP_MUL 3
#define OP_DIV 4
#define OP_POW 5
#define OP_LEFT_BRACE 6
#define OP_RIGHT_BRACE 7

#include <math.h>

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

long double returnCalcAnswer( long double c, long double a, long double b ) {
    int op = (int) c;
    if (op == OP_ADD) return a + b;
    else if (op == OP_SUB) return a - b;
    else if (op == OP_MUL) return a * b;
    else if (op == OP_DIV) return a * 1.0 / b;
    else if (op == OP_POW) {
        return pow( a, (int)b );
    }
}

int precede( char c ) {
    if (c == '+' || c == '-') return 1;
    else if (c == '*' || c == '/') return 2;
    else if (c == '^') return 3;
}

#endif

