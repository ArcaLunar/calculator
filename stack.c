#include "stack.h"

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
