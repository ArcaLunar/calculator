#ifndef _STACK_H_
#define _STACK_H_

/*
Implement a custom stack data structure.
*/

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
void initOp( struct operatorStack* );

// Initialization
void initData( struct dataStack* );

// Pushes an operator b into the stack
void pushOp( struct operatorStack*, char );

// Pop the top operator element
char popOp( struct operatorStack* );

// Return the top operator element
char topOp( struct operatorStack* );

// Push a number (or an operator) into stack.
void pushData( struct dataStack*, long double );

// Pop the top data element
long double popData( struct dataStack* );

// Determine whether the stack is empty.
int emptyOp( struct operatorStack* );

// Determine whether the stack is empty.
int emptyData( struct dataStack* );

void showData( struct dataStack* );

#endif
