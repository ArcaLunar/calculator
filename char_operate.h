#ifndef _CHAR_OPERATE_H_
#define _CHAR_OPERATE_H_

#define OP_ADD 1.0
#define OP_SUB 2.0
#define OP_MUL 3.0
#define OP_DIV 4.0
#define OP_POW 5.0
#define OP_LEFT_BRACE 6.0
#define OP_RIGHT_BRACE 7.0

long double isOperator( char c ) {
    switch(c) {
        case '+':
            return OP_ADD;
        case '-':
            return OP_SUB;
        case '*':
            return OP_MUL;
        case '/':
            return OP_DIV;
        case '^':
            return OP_POW;
        case '(':
            return OP_LEFT_BRACE;
        case ')':
            return OP_RIGHT_BRACE;
	}
}

long double returnCalcAnswer(long double op, long double a, long double b) {
    switch(op) {
        case OP_ADD:
            return a+b;
        case OP_SUB:
            return a-b;
        case OP_MUL:
            return a*b;
        case OP_DIV:
            return a/b;
        case OP_POW:
            long double ans = 1;
            for(int i = 0; i < b; i++) ans *= a;
            return ans;
	}
}

long double precede( char c ){
    if(c == '+' || c == '-') return 1.0;
    else if(c == '*' || c == '/') return 2.0;
    else if(c == '^') return 3.0;
}

#endif

