#ifndef _STACK_H_
#define _STACK_H_

/*
Implement a custom stack data structure.
*/

#include <string.h>

#define MAXN 10000

// Stack of operators. Used to convert a expression into reverse Polish expression.
struct operatorStack {
    char op[MAXN];
    int top;
};
// Stack of stored doubles.
// Stores numbers and operators in a reverse Polish expression.
struct dataStack {
    long double data[MAXN];
    int aux[MAXN]; // Auxiliary array, in which aux[i]=1 means it's a number, otherwise an operator.
    int top; // A pointer to the place one more than the top of stack
};

// Initialization
void initOp( struct operatorStack* a ) {
    a->top = 0;
}
// Initialization
void initData( struct dataStack* a ) {
    a->top = 0;
}
// Pushes an operator b into the stack
void pushOp( struct operatorStack* a, char b ) {
    a->op[a->top++] = b;
}
// Pop the top operator element
char popOp( struct operatorStack* a ) {
    return (*a).op[--(*a).top];
}
// Return the top operator element
char topOp( struct operatorStack* a ) {
    return a->op[a->top - 1];
}
// Push a number (or an operator) into stack.
void pushData( struct dataStack* a, long double b ) {
    a->data[a->top++] = b;
}
// Pop the top data element
long double popData( struct dataStack* a ) {
    return a->data[--a->top];
}
// Determine whether the stack is empty.
int emptyOp( struct operatorStack* a ) {
    return a->top;
}
// Determine whether the stack is empty.
int emptyData( struct dataStack* a ) {
    return a->top;
}
void showData( struct dataStack* a ) {
    for (int i = 0; i < a->top; i++) printf( "%Lg ", a->data[i] );
    printf( "\n" );
}

#endif
